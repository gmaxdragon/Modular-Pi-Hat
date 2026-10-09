/*
 * Seizo board bring-up diagnostics, version 0.1.0.
 * AI-assisted draft. Not compiled for the ESP32 target or tested on hardware yet.
 * Purpose: verify native USB communication and that the main MCU is running.
 * This is not the robot controller and does not implement a safety interlock.
 * Keep the external servo/stepper supplies disconnected during bring-up.
 * No GPIO outputs, servo PWM, step signals, Wi-Fi, or Bluetooth are configured.
 *
 * Arduino IDE: board ESP32S3 Dev Module; USB CDC On Boot = Enabled;
 * USB Mode = Hardware CDC and JTAG; Upload Mode = UART0 / Hardware CDC.
 * Use an 8MB flash setting and disabled PSRAM only for the proposed N8 module.
 * Send PING, STATUS, or HELP with a newline over the native USB serial port.
 * Official setup reference:
 * https://docs.espressif.com/projects/arduino-esp32/en/latest/tutorials/cdc_dfu_flash.html
 */
#include <Arduino.h>
#include <ctype.h>
#include <string.h>

#if !defined(CONFIG_IDF_TARGET_ESP32S3)
#error "Select an ESP32-S3 target before compiling this diagnostic sketch."
#endif
#if !defined(ARDUINO_USB_CDC_ON_BOOT) || !ARDUINO_USB_CDC_ON_BOOT
#error "Enable USB CDC On Boot. This sketch intentionally does not use UART0."
#endif

static constexpr size_t LINE_CAPACITY = 64;
static char lineBuffer[LINE_CAPACITY];
static size_t lineLength = 0;
static bool discardUntilNewline = false;

static void handleCommand(char *line) {
  // Trim spaces, then accept case-insensitive ASCII commands.
  char *start = line;
  while (*start && isspace(static_cast<unsigned char>(*start))) ++start;
  char *end = start + strlen(start);
  while (end > start && isspace(static_cast<unsigned char>(end[-1]))) --end;
  *end = '\0';
  if (*start == '\0') return;
  for (char *p = start; *p; ++p) {
    *p = static_cast<char>(toupper(static_cast<unsigned char>(*p)));
  }

  if (strcmp(start, "PING") == 0) {
    Serial.println("PONG");
  } else if (strcmp(start, "STATUS") == 0) {
    Serial.print("SEIZO_DIAGNOSTICS VERSION=0.1.0 MOTOR_OUTPUTS_CONFIGURED=0 UPTIME_MS=");
    Serial.println(static_cast<unsigned long>(millis()));
  } else if (strcmp(start, "HELP") == 0) {
    Serial.println("COMMANDS: PING STATUS HELP. No movement commands are implemented.");
  } else {
    Serial.println("ERR UNKNOWN_COMMAND");
  }
}

void setup() {
  Serial.begin(115200);
  // Do not wait for a host, initialize any actuator outputs, or turn on a motor supply.
}

void loop() {
  // Bound the work per loop and avoid blocking reads or dynamically allocated Strings.
  for (size_t budget = 0; budget < 64 && Serial.available() > 0; ++budget) {
    const int value = Serial.read();
    if (value < 0) break;
    const char c = static_cast<char>(value);
    if (c == '\r') continue;
    if (c == '\n') {
      if (discardUntilNewline) {
        Serial.println("ERR LINE_TOO_LONG_OR_INVALID");
      } else {
        lineBuffer[lineLength] = '\0';
        handleCommand(lineBuffer);
      }
      lineLength = 0;
      discardUntilNewline = false;
    } else if (!discardUntilNewline) {
      const unsigned char byteValue = static_cast<unsigned char>(c);
      if ((byteValue < 32 && c != '\t') || byteValue > 126 || lineLength >= LINE_CAPACITY - 1) {
        discardUntilNewline = true;
      } else {
        lineBuffer[lineLength++] = c;
      }
    }
  }
  delay(1);
}

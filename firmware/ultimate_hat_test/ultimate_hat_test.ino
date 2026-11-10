

#include <Arduino.h>
#include <Wire.h>
#include <ctype.h>
#include <string.h>

#if defined(CONFIG_IDF_TARGET_ESP32S3)
  // This sketch targets the ESP32-S3 board family and uses its onboard USB serial.
#elif defined(CONFIG_IDF_TARGET_ESP32)
  #warning "This sketch is tuned for ESP32-S3; some pins and USB behavior may differ."
#else
  #warning "Board target is not recognized; pin compatibility is not guaranteed."
#endif

#if defined(ARDUINO_USB_CDC_ON_BOOT) && !ARDUINO_USB_CDC_ON_BOOT
  #warning "USB CDC is disabled on boot; serial monitor may not come up automatically."
#elif !defined(ARDUINO_USB_CDC_ON_BOOT)
  #warning "ARDUINO_USB_CDC_ON_BOOT is not defined; USB serial behavior may vary by board."
#endif

#if defined(ARDUINO_USB_MODE) && ARDUINO_USB_MODE != 1
  #warning "ARDUINO_USB_MODE is not set to the recommended USB CDC+JTAG mode."
#endif

static constexpr int LED_PIN = 38;
static constexpr int BOOT_PIN = 0;
static constexpr int USB_SENSE_PIN = 39;
static constexpr int OLED_SDA = 40;
static constexpr int OLED_SCL = 41;

static constexpr size_t LINE_CAPACITY = 64;
static char lineBuffer[LINE_CAPACITY];
static size_t lineLength = 0;

static bool droppingLine = false;
static bool ledIsOn = false;

static void handleCommand(char *line) {
  char *start = line;

  while (*start && isspace(static_cast<unsigned char>(*start))) {
    ++start;
  }

  char *end = start + strlen(start);

  while (end > start &&
         isspace(static_cast<unsigned char>(end[-1]))) {
    --end;
  }

  *end = '\0';

  if (*start == '\0') {
    return;
  }

  for (char *p = start; *p; ++p) {
    *p = static_cast<char>(
      toupper(static_cast<unsigned char>(*p))
    );
  }

  if (!strcmp(start, "PING")) {
    Serial.println("PONG");

  } else if (!strcmp(start, "STATUS")) {
    Serial.print(
      "BOARD=MODULAR_PI_HAT MCU=ESP32S3 "
      "VERSION=0.2.0 UPTIME_MS="
    );

    Serial.print(static_cast<unsigned long>(millis()));
    Serial.print(" LED=");
    Serial.print(ledIsOn ? "ON" : "OFF");
    Serial.println(" ACTUATOR_OUTPUTS_CONFIGURED=0");

  } else if (!strcmp(start, "PINMAP")) {
    Serial.println(
      "LED=38 BOOT=0 USB_SENSE=39 USB_DM=19 USB_DP=20"
    );

    Serial.println(
      "OLED_SDA=40 OLED_SCL=41 "
      "PI_UART_TX=43 PI_UART_RX=44"
    );

    Serial.println("GRIPPER=4 WRIST=5 (NOT INITIALIZED)");

    Serial.println(
      "J4_SIGNAL_PINS=1,2,6,7 "
      "J5_SIGNAL_PINS=12,13,14,15"
    );

    Serial.println(
      "J6_SIGNAL_PINS=8,9,10,11 "
      "J7_SIGNAL_PINS=16,17,18,21"
    );

  } else if (!strcmp(start, "BUTTON")) {
    Serial.println(
      digitalRead(BOOT_PIN) == LOW
        ? "BOOT=PRESSED"
        : "BOOT=RELEASED"
    );

  } else if (!strcmp(start, "VBUS")) {
    // GPIO39 has no ADC. This is presence detection,
    // not a USB voltage measurement.
    Serial.println(
      digitalRead(USB_SENSE_PIN) == HIGH
        ? "USB_SENSE=HIGH (logic presence indication only)"
        : "USB_SENSE=LOW (logic presence indication only)"
    );

  } else if (!strcmp(start, "LED ON") ||
             !strcmp(start, "LED OFF") ||
             !strcmp(start, "LED TOGGLE")) {
    if (!strcmp(start, "LED TOGGLE")) {
      ledIsOn = !ledIsOn;
    } else {
      ledIsOn = !strcmp(start, "LED ON");
    }

    digitalWrite(LED_PIN, ledIsOn ? HIGH : LOW);
    Serial.println(ledIsOn ? "LED=ON" : "LED=OFF");

  } else if (!strcmp(start, "USB")) {
    Serial.println(
      digitalRead(USB_SENSE_PIN) == HIGH
        ? "USB_SENSE=HIGH (logic presence indication only)"
        : "USB_SENSE=LOW (logic presence indication only)"
    );

  } else if (!strcmp(start, "OLED")) {


    if (!Wire.begin(OLED_SDA, OLED_SCL, 100000)) {
      Serial.println("OLED=I2C_START_FAILED");
      return;
    }

    Wire.setTimeOut(50);
    bool found = false;

    for (uint8_t address = 0x3C; address <= 0x3D; ++address) {
      Wire.beginTransmission(address);
      const uint8_t result = Wire.endTransmission();

      if (result == 0) {
        Serial.println(
          address == 0x3C
            ? "I2C_ACK=0x3C"
            : "I2C_ACK=0x3D"
        );

        found = true;

      } else if (result != 2) {
        Serial.print("I2C_ERROR_CODE=");
        Serial.println(static_cast<unsigned int>(result));
      }
    }

    if (!found) {
      Serial.println("OLED=NO_ACK_AT_0x3C_OR_0x3D");
    }

    Serial.println(
      "An ACK alone does not identify or fully test the display."
    );

    Wire.end();

  } else if (!strcmp(start, "HELP")) {
    Serial.println("Ultimate Pi HAT test");

    Serial.println(
      "COMMANDS: PING STATUS PINMAP BUTTON VBUS USB "
      "LED ON LED OFF LED TOGGLE OLED HELP"
    );

    Serial.println(
      "Keep actuators disconnected; verify USB is connected."
    );

  } else {
    Serial.println("ERR UNKNOWN_COMMAND");
  }
}

void setup() {
  // Set the LED to a known state before exposing it to the host.
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
  ledIsOn = false;

  // These inputs already have external circuitry on the PCB.
  pinMode(BOOT_PIN, INPUT_PULLUP);
  pinMode(USB_SENSE_PIN, INPUT);

  Serial.begin(115200);
  delay(250);
  Serial.println();
  Serial.println("Ultimate Pi HAT ready");
  Serial.println("Type HELP for a list of commands.");

  // No servo outputs, motor commands or radio are initialized.
}

void loop() {
  for (size_t budget = 0;
       budget < 64 && Serial.available() > 0;
       ++budget) {
    const int value = Serial.read();

    if (value < 0) {
      break;
    }

    const char c = static_cast<char>(value);

    if (c == '\n' || c == '\r') {
      if (droppingLine) {
        Serial.println("ERR LINE_TOO_LONG_OR_INVALID");
      } else {
        lineBuffer[lineLength] = '\0';
        handleCommand(lineBuffer);
      }

      lineLength = 0;
      droppingLine = false;

    } else if (!droppingLine) {
      const unsigned char byte =
        static_cast<unsigned char>(c);

      if ((byte < 32 && c != '\t') ||
          byte > 126 ||
          lineLength >= LINE_CAPACITY - 1) {
        droppingLine = true;
      } else {
        lineBuffer[lineLength++] = c;
      }
    }
  }

  delay(1);
}
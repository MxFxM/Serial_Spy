#include <Arduino.h>

#define SPY Serial2
// Serial 2 on Teensy 4.0:
// 7 - RX
// 8 - TX

#define OUT Serial1
// Serial 1 on Teensy 4.0:
// 0 - RX
// 1 - TX

#define USB Serial

void setup() {
  USB.begin(9600); // usb is always 12 Mbit/s
  OUT.begin(19200);
  SPY.begin(9600);

  // wait for connection to pc
  while (!USB.available()) {
    delay(1);
  }
}

void loop() {
  if (USB.available()) {
    uint8_t newByte = USB.read();
    SPY.write(newByte);
    OUT.write(newByte);
  }

  if (SPY.available()) {
    uint8_t newByte = SPY.read();
    USB.write(newByte);
    OUT.write(newByte);
  }
}
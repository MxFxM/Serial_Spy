#include <Arduino.h>

#define SPY Serial2
#define USB Serial

void setup() {
  USB.begin(9600); // usb is always 12 Mbit/s
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
  }

  if (SPY.available()) {
    uint8_t newByte = SPY.read();
    USB.write(newByte);
  }
}
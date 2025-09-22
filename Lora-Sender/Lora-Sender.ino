#include <SPI.h>
#include <LoRa.h>

// Pin mapping
#define SS 5
#define RST 14
#define DIO0 26

void setup() {
  Serial.begin(115200);
  while (!Serial);

  LoRa.setPins(SS, RST, DIO0); // CS, reset, irq

  if (!LoRa.begin(433E6)) {   // 433 MHz for SX1278
    Serial.println("Starting LoRa failed!");
    while (1);
  }
  Serial.println("LoRa Sender Ready");
}

void loop() {
  Serial.println("Sending packet...");
  LoRa.beginPacket();
  LoRa.print("Hello ESP32 LoRa!");
  LoRa.endPacket();
  delay(2000);
}

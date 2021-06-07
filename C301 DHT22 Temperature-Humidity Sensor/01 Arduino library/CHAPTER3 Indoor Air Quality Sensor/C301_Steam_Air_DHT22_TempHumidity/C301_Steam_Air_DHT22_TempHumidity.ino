/*
   @301 DHT22 Temperature-humidity sensor
*/

#include <C301_Steam_Air_DHT22_TempHumidity.h>  // Internal library header file
#define PIN 3

SteamDHT22 dht22(PIN, DHT22);  // pin number, type

void setup() {
  Serial.begin(9600);     // Start serial communication at a speed of 9600bps.
  dht22.begin();          // (1) Initialize the sensor.
}

void loop() {
  dht22.read();         // (2) Measure the value of the sensor.
  dht22.display();      // (3) Output the sensor value.

  delay(1000);          // Wait for 1 second.
}

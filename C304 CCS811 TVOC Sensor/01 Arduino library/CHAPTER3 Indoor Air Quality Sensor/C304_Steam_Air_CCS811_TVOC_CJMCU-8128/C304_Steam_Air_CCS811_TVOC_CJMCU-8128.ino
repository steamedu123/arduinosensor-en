/*
   @CJMCU-8128 CCS811 TVOC Sensor  (CCS811+SI7021_BMP280)
   @AliExpress : https://aliexpi.com/Qyvr 
*/

#include <C304_Steam_Air_CCS811_TVOC_CJMCU-8128.h> // Internal library header file

SteamCJMCU8128 cjmcu8128; // Instance

void setup() {
  Serial.begin(9600); // Start serial communication at a speed of 9600bps.
  cjmcu8128.begin();  // (1) Initialize the sensor.
}

void loop() {
  cjmcu8128.read();    // (2) Measure the value of the sensor.
  cjmcu8128.display(); // (3) Output the sensor value.
  delay(1000);         // Wait for 1 second.
}

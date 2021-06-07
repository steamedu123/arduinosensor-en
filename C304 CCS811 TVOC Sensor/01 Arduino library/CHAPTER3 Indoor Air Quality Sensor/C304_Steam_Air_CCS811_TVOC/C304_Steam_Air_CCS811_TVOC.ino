/*
   @304 CCS811 TVOC sensor
*/

#include <C304_Steam_Air_CCS811_TVOC.h> // Internal library header file

SteamCCS811 ccs811;    // Instance, pin number

void setup() {
  Serial.begin(9600); // Start serial communication at a speed of 9600bps.
  ccs811.begin();     // (1) Initialize the sensor.
}

void loop() {
  ccs811.read();     // (2) Measure the value of the sensor.
  ccs811.display();  // (3) Output the sensor value.
  delay(1000);       // Wait for 1 second.
}

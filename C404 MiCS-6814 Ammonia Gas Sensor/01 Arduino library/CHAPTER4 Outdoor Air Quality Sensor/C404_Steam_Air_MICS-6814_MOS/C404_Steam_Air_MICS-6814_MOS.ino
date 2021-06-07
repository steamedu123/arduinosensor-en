/*
   @404 MiCS-6814 Ammonia gas sensor
*/

#include <C404_Steam_Air_MICS-6814_MOS.h>   // Internal library header file

SteamMICS6814 mics6814;     // Instance

void setup() {
  Serial.begin(115200);     // Start serial communication at a speed of 115200bps.
  mics6814.begin();         // (1) Initialize the sensor.
}

void loop() {
  mics6814.read();          // (2) Measure the value of the sensor.
  mics6814.display();       // (3) Output the sensor value.
  delay(3000);              // Wait for 1 second.
}

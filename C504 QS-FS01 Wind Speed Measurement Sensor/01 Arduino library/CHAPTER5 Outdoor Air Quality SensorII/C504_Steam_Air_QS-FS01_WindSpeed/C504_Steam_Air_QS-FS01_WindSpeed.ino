/*
   @504 QS-FS01 Wind speed sensor
*/

#include <C504_Steam_Air_QS-FS01_WindSpeed.h> // Internal library header file
#define AoutPIN A1

SteamQSFS01 qsfs01(AoutPIN);  // Instance, pin number

void setup() {
  Serial.begin(57600);        // Start serial communication at a speed of 57600bps.
  qsfs01.begin();             // (1) Initialize the sensor.
}

void loop() {
  qsfs01.read();              // (2) Measure the value of the sensor.
  qsfs01.display();           // (3) Output the sensor value.
  delay(1000);                // Wait for 1 second.
}

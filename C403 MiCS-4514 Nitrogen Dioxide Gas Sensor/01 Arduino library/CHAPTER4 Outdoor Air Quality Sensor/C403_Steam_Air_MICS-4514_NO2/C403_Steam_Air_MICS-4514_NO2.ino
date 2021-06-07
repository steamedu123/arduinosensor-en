/*
   @403 MiCS-4514 Nitrogen dioxide gas sensor
*/

#include <C403_Steam_Air_MICS-4514_NO2.h>   // Internal library header file

SteamMICS4514 mics4514(3, A0, A1);     // Instance, pin number(pre, nox, red)

void setup() {
  Serial.begin(9600);       // Start serial communication at a speed of 9600bps.
  mics4514.begin();         // (1) Initialize the sensor.
}

void loop() {
  mics4514.read();          // (2) Measure the value of the sensor.
  mics4514.display();       // (3) Output the sensor value.
  delay(1000);              // Wait for 1 second.
}

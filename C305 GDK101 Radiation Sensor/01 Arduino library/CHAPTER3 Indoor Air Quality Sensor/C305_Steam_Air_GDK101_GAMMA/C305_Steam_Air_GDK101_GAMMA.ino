/*
   @305 GDK101 Gamma radiation sensor
*/

#include <C305_Steam_Air_GDK101_GAMMA.h>    // Internal library header file

SteamGDK101 gdk101;       // Instance

void setup() {
  Serial.begin(115200);   // Start serial communication at a speed of 115200bps.
  gdk101.begin();         // (1) Initialize the sensor.
}

void loop() {
  gdk101.read();          // (2) Measure the value of the sensor.
  gdk101.display();       // (3) Output the sensor value.
  delay(2000);            // Wait for 2 second.
}

/*
   @502 GUVA-S12SD Ultraviolet light sensor
*/

#include <C502_Steam_Air_GUVA-12SD_UV.h>    // Internal library header file
#define AoutPIN A1

SteamGUVA12SD uv(AoutPIN);    // Instance, pin number

void setup() {
  Serial.begin(9600);     // Start serial communication at a speed of 9600bps.
  uv.begin();             // (1) Initialize the sensor.
}

void loop() {
  uv.read();              // (2) Measure the value of the sensor.
  uv.display();           // (3) Output the sensor value.
  delay(1000);            // Wait for 1 second.
}

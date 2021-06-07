/*
   @203 GP2Y1010AU0F Fine Dust Sensor
*/

#include <C203_Steam_Air_GP2Y1010AU0F_Dust.h>   // Internal library header file
#define sharpLEDPin    3
#define sharpVoPin     A1

SteamGP2Y1010AU0F sensor(sharpLEDPin, sharpVoPin);    // pin number

void setup() {
  Serial.begin(9600);   // Start serial communication at a speed of 9600bps.
  sensor.begin();       // (1)Initialize the sensor.
}

void loop() {
  if (sensor.read()) {  // (2) Measure the value of the sensor.
    sensor.display();   // (3) Output the sensor value.
  }
}

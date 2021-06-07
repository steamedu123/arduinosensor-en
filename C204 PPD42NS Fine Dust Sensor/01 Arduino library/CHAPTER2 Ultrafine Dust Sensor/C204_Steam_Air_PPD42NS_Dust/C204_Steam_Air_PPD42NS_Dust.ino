/*
   @204 PPD42NS Fine Dust Sensor
*/

#include <C204_Steam_Air_PPD42NS_Dust.h>  // Internal library header file
#define PIN 3

SteamPPD42NS ppd42ns(PIN);    // pin number

void setup() {
  Serial.begin(9600);	  // Start serial communication at a speed of 9600bps.
  ppd42ns.begin();      // (1) Initialize the sensor.
}

void loop() {
  ppd42ns.read();       // (2) Measure the value of the sensor.
  ppd42ns.display();    // (3) Output the sensor value.
}

/*
   @205 SDS011 Fine Dust Sensor
*/

#include <C205_Steam_Air_NovaSDS011_Dust.h>    // Internal library header file

#define RxPIN 3
#define TxPIN 2

SteamNovaSDS011 novasds011(RxPIN, TxPIN); // pin number

void setup() {
  Serial.begin(9600);     // Start serial communication at a speed of 9600bps.
  novasds011.begin();     // (1) Initialize the sensor.
}

void loop() {
  novasds011.read();      // (2) Measure the value of the sensor.
  novasds011.display();   // (3) Output the sensor value.
}

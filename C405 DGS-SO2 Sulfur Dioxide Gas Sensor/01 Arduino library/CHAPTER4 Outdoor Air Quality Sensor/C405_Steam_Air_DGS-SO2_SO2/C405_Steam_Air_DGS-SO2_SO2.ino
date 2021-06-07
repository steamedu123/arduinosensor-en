 /*
   @405 DGS-SO2 Sulfur dioxide sensor
*/

#include <C405_Steam_Air_DGS-SO2_SO2.h> // Internal library header file

SteamDGSSO2 dgsSO2;     // Instance, pin number

void setup() {
  Serial.begin(9600);   // Start serial communication at a speed of 9600bps.
  dgsSO2.begin();       // (1) Initialize the sensor.
}

void loop() {
  dgsSO2.read();        // (2) Measure the value of the sensor.
  dgsSO2.display();     // (3) Output the sensor value.
}

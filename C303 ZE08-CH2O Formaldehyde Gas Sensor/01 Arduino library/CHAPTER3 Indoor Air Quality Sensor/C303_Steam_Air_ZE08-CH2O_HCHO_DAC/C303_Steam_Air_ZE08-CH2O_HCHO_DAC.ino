/*
   @303 ZE08-CH2O Formaldehyde gas sensor
*/

#include <C303_Steam_Air_ZE08-CH2O_HCHO.h>    // Internal library header file

SteamZE08CH2O hcho(A1);          // pin number

void setup() {
  Serial.begin(9600);   // Start serial communication at a speed of 9600bps.
  hcho.begin();         // (1) Initialize the sensor.
}

void loop() {
  hcho.read();          // (2) Measure the value of the sensor.
  hcho.display();       // (3) Output the sensor value.
  delay(1000);          // Wait for 1 second.
}

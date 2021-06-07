/*
   @501 BME280 Atmospheric pressure (Barometric) sensor
*/

#include <C501_Steam_Air_BME280_hPa.h>   // Internal library header file

SteamBME280 bme280;     // Instance, pin number

void setup() {
  Serial.begin(9600);   // Start serial communication at a speed of 9600bps.
  bme280.begin();       // (1) Initialize the sensor.
}

void loop() {
  bme280.read();        // (2) Measure the value of the sensor.
  bme280.display();     // (3) Output the sensor value.
  delay(1000);          // Wait for 1 second.
}

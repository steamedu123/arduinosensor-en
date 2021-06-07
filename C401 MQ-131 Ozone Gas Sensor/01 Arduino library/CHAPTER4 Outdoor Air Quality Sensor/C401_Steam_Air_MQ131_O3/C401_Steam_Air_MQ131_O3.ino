/*
   @401 MQ-131 Ozone gas sensor
*/

#include <C401_Steam_Air_MQ131_O3.h>    // Internal library header file
#define AoutPIN A1
#define TEMP 24 // °C
#define HUMI 40 //  %

SteamMQ131 mq131(AoutPIN);    // Instance, pin number

void setup() {
  Serial.begin(115200);       // Start serial communication at a speed of 115200bps.
  mq131.begin();              // (1) Initialize the sensor.
}

void loop() {
  mq131.read(TEMP, HUMI);     // (2) Measure the value of the sensor.
  mq131.display();            // (3) Output the sensor value.

  delay(6000);                // Wait for 6 second.
}

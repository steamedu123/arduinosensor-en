/*
   @402 MQ-7   Carbon monoxide gas sensor
*/

#include <C402_Steam_Air_MQ7_CO.h>    // Internal library header file
#define AoutPIN A1

SteamMQ7 mq7(AoutPIN);  // Instance, pin number

void setup() {
  Serial.begin(9600);   // Start serial communication at a speed of 9600bps.
  mq7.begin();          // (1) Initialize the sensor.
}

void loop() {
  mq7.read();           // (2) Measure the value of the sensor.
  mq7.display();        // (3) Output the sensor value.
  delay(1000);          // Wait for 1 second.
}

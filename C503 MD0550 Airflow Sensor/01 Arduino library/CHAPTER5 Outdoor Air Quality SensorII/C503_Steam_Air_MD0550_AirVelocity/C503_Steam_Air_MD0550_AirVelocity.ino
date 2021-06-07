/*
   @503 MD0550 Airflow sensor
*/
 
#include <C503_Steam_Air_MD0550_AirVelocity.h>  // Internal library header file
#define RvPIN  A2
#define TmpPIN A1

SteamMD0550 md0550(RvPIN, TmpPIN);    // Instance, pin number

void setup() {
  Serial.begin(57600);    // Start serial communication at a speed of 57600bps.
  md0550.begin();         // (1) Initialize the sensor.
}

void loop() {
  md0550.read();          // (2) Measure the value of the sensor.
  md0550.display();       // (3) Output the sensor value.
  delay(1000);            // Wait for 1 second.
}

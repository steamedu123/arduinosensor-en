/*
   @202 PMS7003 Fine Dust Sensor
*/

#include <C202_Steam_Air_PMS7003_Dust.h>    // Internal library header file
#define RxPIN 3
#define TxPIN 2

SteamPMS7003 pms7003(RxPIN, TxPIN);   // RX/TX pin number

void setup() {
  Serial.begin(9600);     // Start serial communication at a speed of 9600bps.
  pms7003.begin();        // (1) Initialize the sensor.
}

void loop() {
  if (pms7003.read()) {   // (2) Measure the value of the sensor.
    pms7003.display();    // (3) Output the sensor value.
  }
}

/*
   @604 nRF24L01 Remote Monitoring with RF Communication(Receiver)
*/

#include <C602_Steam_Air_NRF24L01.h> // Internal library header file
#include <C602_Steam_Air_OLED.h>

SteamNRF24L01 rf;   // RF instance
SteamOLED oled;     // OLED instance

void setup() {
  Serial.begin(9600);             // Start serial communication at a speed of 9600bps.
  rf.begin();                     // (1) Initialize the RF
  Serial.println("Listening...");  // Wait to receive data 
}

void loop() {
  rf.receive();                   // (2) Receive sensor data.  
  oled.display(rf.getPm(), rf.getTemp(), rf.getHumi(), rf.getPa()); // (3) Output sensor data to OLED.
}

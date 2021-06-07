/*
   @604 nRF24L01 Remote Monitoring with RF Communication(Transmitter)
*/

#include <C602_Steam_Air_NRF24L01.h> // Internal library header file
#include <C202_Steam_Air_PMS7003_Dust.h>
#include <C501_Steam_Air_BME280_hPa.h>

SteamPMS7003 pms7003(4, 5);   // the find dust instance and pin number Rx(4), Tx(5) 
SteamBME280 bme280;           // Temperature/humidity/barometric pressure instance
SteamNRF24L01 rf;             // RF instance

byte value[4];

void setup() {
  Serial.begin(9600);     //  Start serial communication at a speed of 9600bps.

  pms7003.begin();        // (1) Initialize the fine dust sensor.
  bme280.begin();         // (1) Initialize the temperature/humidity/barometrice pressure sensor.
  rf.begin();             // (1) Initialize the RF.
}

void loop() {

  bme280.read();        // (2) Measure the value of the temperature/humidity/barometrice pressure sensor.
  pms7003.read();       // (2) Measure the value of the fine dust sensor.
  rf.send(pms7003.getPM2_5(), bme280.getTemp(), bme280.getHumidity(), bme280.gethPa()); // (3) The sensor value is transmitted via RF.
}

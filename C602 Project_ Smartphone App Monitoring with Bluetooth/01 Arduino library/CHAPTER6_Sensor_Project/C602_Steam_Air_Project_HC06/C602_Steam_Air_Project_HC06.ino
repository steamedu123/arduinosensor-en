/*
   @602 HC-06 Smartphone App Monitoring with Bluetooth
*/

#include <C602_Steam_Air_Bluetooth.h> // Internal library header file
#include <C202_Steam_Air_PMS7003_Dust.h>
#include <C301_Steam_Air_DHT22_TempHumidity.h>

SteamBluetooth bt(2, 3);      // the Bluetooth instance and pin number Rx(2), Tx(3)
SteamPMS7003 pms7003(4, 5);   // the fine dust sensor instance and Rx pin number.
SteamDHT22 dht22(A1, DHT22);  // the temperature/humidity sensor instance, pin number(A1) and DHT22 type.


void setup() {
  Serial.begin(9600);     // Start serial communication at a speed of 9600bps.

  bt.begin();             // (1) Initialize the Bluetooth.
  pms7003.begin();        // (1) Initialize the fine dust sensor.
  dht22.begin();          // (1) Initialize the temperature/humidity sensor.
}

void loop() {
  pms7003.read();       // (2) Measure the value of the fine dust sensor.
  dht22.read();         // (2) Measure the value of the temperature/humidity sensor.

  bt.sendBT(pms7003.getPM2_5(), dht22.getTemp(), dht22.getHumidity()); // (3) The sensor value is transmitted via Bluetooth.
}

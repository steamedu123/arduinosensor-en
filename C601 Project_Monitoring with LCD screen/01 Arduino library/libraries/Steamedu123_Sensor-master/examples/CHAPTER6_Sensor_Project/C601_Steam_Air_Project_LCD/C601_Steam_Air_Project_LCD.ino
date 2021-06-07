/*
   @601 16X2 LCD Monitoring with LCD screen
*/


#include <C601_Steam_Air_LCD16X2.h>   // Internal library header file
#include <C202_Steam_Air_PMS7003_Dust.h>
#include <C301_Steam_Air_DHT22_TempHumidity.h>

SteamLCD16X2 lcd16x2;         // 16x2 LCD instance
SteamPMS7003 pms7003(2, 3);   // the fine dust sensor instance and Rx(D2) pin number.
SteamDHT22 dht22(A1, DHT22);  // the temperature/humidity sensor instance, pin number(A1) and DHT22 type.

void setup() {
  Serial.begin(9600);     // Start serial communication at a speed of 9600bps.

  lcd16x2.begin();        // (1) Initialize the 16x2 LCD.
  pms7003.begin();        // (1) Initialize the fine dust sensor.
  dht22.begin();          // (1) Initialize the temperature/humidity sensor.
}

void loop() {
  pms7003.read();       // (2) Measure the value of the fine dust sensor.
  dht22.read();         // (2) Measure the value of the temperature/humidity sensor.

  pms7003.display();   // (3) Outputs the fine dust value.
  dht22.display();     // (3) Outputs the temperature/humidity value.

  lcd16x2.display(pms7003.getPM2_5(), dht22.getTemp(), dht22.getHumidity());  // (4) The sensor value is output on the LCD.
}

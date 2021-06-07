/*
   @603 ESP01   Remote Monitoring with Wi-Fi 
*/

#include <C603_Steam_Air_ESP01.h>  // Internal library header file
#include <C301_Steam_Air_DHT22_TempHumidity.h>
#include <C205_Steam_Air_NovaSDS011_Dust_PWM.h>

SteamESP01 esp01(2, 3);         // ESP01 Wi-Fi Instance
SteamDHT22 dht22(A1, DHT22);    // the temperature/humidity sensor instance, pin number(A1) and DHT22 type.
SteamNovaSDS011PWM novasds011(4, 5); // the fine dust sensor instance and pin number(pm2.5, pm1).

String ssid = "iptime";               // Wi-Fi router name (SSID) used at home
String pass = "12345678";             // Wi-Fi password you use at home
String apiKey = "XJ61RWFSL0OJEDTG";   // Input Write API key of thingspeak.com channel
const long interval = 4000;           // Sensor value transmission cycle to thingspeak.com, 4 seconds

void setup() {
  Serial.begin(9600);       // Start serial communication at a speed of 9600bps.
  Serial.println("C603 IoT Project Start(ESP01)");

  esp01.begin(ssid, pass, apiKey, interval); // (1) Initialize the Wi-Fi.
  dht22.begin();          // (1) Initialize the temperature/humidity sensor.
  novasds011.begin();     // (1) Initialize the fine dust sensor.
}

void loop() {
  novasds011.read();      // (2) Measure the value of the fine dust sensor.
  dht22.read();           // (2) Measure the value of the temperature/humidity sensor.

  esp01.sendData(novasds011.getPM2_5(), dht22.getTemp(), dht22.getHumidity()); // (3) The sensor value is transmitted via Wi-Fi.
}

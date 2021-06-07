/*
   @302 MH-Z19B Carbon dioxide gas sensor
*/

#include <C302_Steam_Air_MH-Z19B_CO2_PWM.h>   // Internal library header file

#define pwmPin 3

SteamMHZ19BPWM mhz19b_pwm(pwmPin);    // pin number

void setup() {
  Serial.begin(115200);       // Start serial communication at a speed of 115200bps.
  mhz19b_pwm.begin();         // (1) Initialize the sensor.
}

void loop() {
  mhz19b_pwm.read();        // (2) Measure the value of the sensor.
  mhz19b_pwm.display();     // (3) Output the sensor value.
  delay(5000);              // Wait for 5 second.
}

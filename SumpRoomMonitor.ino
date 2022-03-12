/*
 * Sump Room Monitor
 * Scott W. Vincent
 * 
 * Uses Pushover library by Arduino Hannover
 * https://github.com/ArduinoHannover/Pushover
 * 
 * WiFi Setup based on:
 * https://arduino-esp8266.readthedocs.io/en/latest/esp8266wifi/readme.html
 */

#include <ESP8266WiFi.h>
#include "Pushover.h"

// I/O Settings
const int ALARM_RELAY = 9;

// WiFi Settings
const char* WIFI_SSID = "SSID";
const char* WIFI_PASS = "Password";

// Pushover
Pushover po = Pushover("SecureAppToken","UserToken", UNSAFE);

// Setup Function
void setup() 
{
  Serial.begin(115200);

  setupIO();
  setupWiFi();
}

// I/O Setup
void setupIO()
{
  pinMode(ALARM_RELAY, INPUT_PULLUP);
}

// WiFi Setup
void setupWiFi()
{
  delay(10);
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(WIFI_SSID);
  WiFi.begin(WIFI_SSID, WIFI_PASS);
 
  while (WiFi.status() != WL_CONNECTED) 
    {
    delay(500);
    Serial.print(".");
    }
 
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}
 
// Main Loop
void loop() 
{

  // Alarm is active when low
  if (digitalRead(ALARM_RELAY) == LOW) 
  {
    // Debounce
    delay(100);
    if ((digitalRead(ALARM_RELAY) == LOW)) 
    {
      NotifySumpAlarmActive();
    }
  }
}

void NotifySumpAlarmActive()
{
  Serial.println("Sump Pump Alarm Active");
  pushover_button.setTitle("Sump Pump Alarm Active");
  pushover_button.setMessage("The backup sump pump controller is in an alarm condition.");
  pushover_button.setSound("vibrate");
  pushover_button.setPriority(1);
  Serial.println(pushover_button.send());
}

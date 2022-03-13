/*
 * Sump Room Monitor
 * Main Program
 * 
 * Copyright 2022 by Scott W. Vincent
 * www.swvincent.com
 * Licensed under GNU General Public License v2.0
 * See LICENSE file for details
 */

#include <ESP8266WiFi.h>
#include "Pushover.h"

// I/O
const int ALARM_RELAY = 9;

// Alarm Monitoring
const unsigned long MIN_ALARM_TIME = 5000;
const int SUMP_OKAY = LOW;

unsigned long alarmStateChangeMillis;
int alarmState = SUMP_OKAY;
int lastAlarmState = SUMP_OKAY;

// WiFi Settings
const char* WIFI_SSID = "SSID";
const char* WIFI_PASS = "Password";

// Pushover
Pushover po = Pushover("SecureAppToken","UserToken", UNSAFE);

const unsigned long MIN_PUSHOVER_INTERVAL = 10000;
unsigned long lastNotificationTime = millis() - MIN_PUSHOVER_INTERVAL;

// Setup Function
void setup() 
{
  Serial.begin(115200);

  setupIO();
  setupWiFi();

  NotifyStartup();
}
 
// Main Loop
void loop() 
{
  ProcessAlarmState();
  ProcessNotifications();
}

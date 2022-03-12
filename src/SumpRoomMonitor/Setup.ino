/*
 * Sump Room Monitor
 * Setup
 * 
 * Copyright 2022 by Scott W. Vincent
 * www.swvincent.com
 * Licensed under GNU General Public License v2.0
 * See LICENSE file for details
 */
 
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

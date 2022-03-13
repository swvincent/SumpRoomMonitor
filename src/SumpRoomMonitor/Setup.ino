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
  pinMode(LED_BUILTIN, OUTPUT);
}

// WiFi Setup
void setupWiFi()
{
  delay(100);
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(WIFI_SSID);
  WiFi.begin(WIFI_SSID, WIFI_PASS);
 
  while (WiFi.status() != WL_CONNECTED) 
  {
    digitalWrite(LED_BUILTIN, LOW);
    delay(125);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(125);
    digitalWrite(LED_BUILTIN, LOW);
    delay(125);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(125);
    Serial.print(".");
  }
 
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

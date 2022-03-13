/*
 * Sump Room Monitor
 * Notifications
 * 
 * Copyright 2022 by Scott W. Vincent
 * www.swvincent.com
 * Licensed under GNU General Public License v2.0
 * See LICENSE file for details
 */

bool notifySumpAlarm = false;
bool notifySumpOkay = false;

void ProcessNotifications()
{
  // Wait until minimum interval notification time has passed
  if ((millis() - lastNotificationTime) < MIN_PUSHOVER_INTERVAL)
    return;

  // Only one notification per interval to "be nice" to the API
  if (notifySumpOkay)
    NotifySumpOkay();
  else if (notifySumpAlarm)
    NotifySumpAlarm();
}

void NotifySumpOkay()
{
  Serial.println("Sump Pump Okay");
  po.setTitle("Sump Pump Okay");
  po.setMessage("The sump pump controller is okay.");
  po.setSound("vibrate");
  po.setPriority(0);
  Serial.println(po.send());

  notifySumpOkay = false;
  lastNotificationTime = millis();
}

void NotifySumpAlarm()
{
  Serial.println("Sump Pump Alarm");
  po.setTitle("Sump Pump Alarm");
  po.setMessage("The sump pump controller is in an alarm condition.");
  po.setSound("vibrate");
  po.setPriority(1);
  Serial.println(po.send());

  notifySumpAlarm = false;
  lastNotificationTime = millis();
}

void NotifyStartup()
{
  Serial.println("Startup Notification");
  po.setTitle("Sump Pump Monitor Running");
  po.setMessage("The sump pump monitoring system has started.");
  //po.setSound("vibrate");
  po.setPriority(-1);
  Serial.println(po.send());

  lastNotificationTime = millis();
}

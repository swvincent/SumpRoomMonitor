/*
 * Sump Room Monitor
 * Notifications
 * 
 * Copyright 2022 by Scott W. Vincent
 * www.swvincent.com
 * Licensed under GNU General Public License v2.0
 * See LICENSE file for details
 */

void NotifySumpAlarm()
{
  Serial.println("Sump Pump Alarm");
  pushover_button.setTitle("Sump Pump Alarm");
  pushover_button.setMessage("The sump pump controller is in an alarm condition.");
  pushover_button.setSound("vibrate");
  pushover_button.setPriority(1);
  Serial.println(pushover_button.send());
}

void NotifySumpOkay()
{
  Serial.println("Sump Pump Okay");
  pushover_button.setTitle("Sump Pump Okay");
  pushover_button.setMessage("The sump pump controller is okay.");
  pushover_button.setSound("vibrate");
  pushover_button.setPriority(0);
  Serial.println(pushover_button.send());
}

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
  po.setTitle("Sump Pump Alarm");
  po.setMessage("The sump pump controller is in an alarm condition.");
  po.setSound("vibrate");
  po.setPriority(1);
  Serial.println(po.send());
}

void NotifySumpOkay()
{
  Serial.println("Sump Pump Okay");
  po.setTitle("Sump Pump Okay");
  po.setMessage("The sump pump controller is okay.");
  po.setSound("vibrate");
  po.setPriority(0);
  Serial.println(po.send());
}

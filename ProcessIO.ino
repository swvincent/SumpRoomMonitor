/*
 * Sump Room Monitor
 * ProcessIO
 * 
 * Copyright 2022 by Scott W. Vincent
 * www.swvincent.com
 * Licensed under GNU General Public License v2.0
 * See LICENSE file for details
 */

void ProcessAlarmState()
{
  int reading = digitalRead(ALARM_RELAY);

  if (reading != lastAlarmState)
  {
    alarmStateChangeMillis = millis();
  }
  
  if ((millis() - alarmStateChangeMillis) > MIN_ALARM_TIME)
  {
    if (alarmState != reading)
    {
      alarmState = reading;

      if (alarmState == SUMP_OKAY)
      {
        NotifySumpOkay();
      }
      else
      {
        NotifySumpAlarm();
      }
    }
  }

  lastAlarmState = reading;
}

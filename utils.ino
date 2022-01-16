/**
   converts hours or minutes to the correct digit for specified index
   if isHour === true, converts 24 hour time to standard time
   example (hour): 21 returns 2 (for index 0) returns 1 (for index 1)
   example (minute): 30 returns 3 (for index 0) returns 1 (for index 1)
*/
int convertDigits(int digits, int index, bool isHour) {

  // convert from 24 hour to standard time
  if (isHour && digits > 12) {
    digits = digits - 12;
  }
  // convert midnight (00) to 12
  if (isHour && digits == 0) {
    digits = 12;
  }

  // convert to string to check length and charAt
  String timeString = String(digits);

  // prepend with "0" if the hour or minute is a single digit
  if (timeString.length() < 2) {
    timeString = "0" + timeString;
  }

  // get the character at the specified index
  char indexChar = timeString.charAt(index);

  // convert the character to string and then integer
  String indexString = String(indexChar);
  int output = indexString.toInt();

  return output;
}

/**
   Logs time to serial monitor, e.g.:
   2018/12/29 (Saturday) 21:48:40
*/
void logTime(DateTime now) {
  Serial.print(now.year(), DEC);
  Serial.print('/');
  Serial.print(now.month(), DEC);
  Serial.print('/');
  Serial.print(now.day(), DEC);
  Serial.print(" (");
  //Serial.print(daysOfTheWeek[now.dayOfTheWeek()]);
  Serial.print(") ");
  Serial.print(now.hour(), DEC);
  Serial.print(':');
  Serial.print(now.minute(), DEC);
  Serial.print(':');
  Serial.print(now.second(), DEC);
  Serial.println();
  Serial.print(now.dayOfTheWeek(), DEC);
}

void setupLED() {
  // LED Setup
#ifndef __AVR_ATtiny85__
  Serial.begin(9600);
  Serial.println("7 Segment Backpack Test");
#endif
  matrix.begin(0x70);
}


/**
   Writes the current hour and minutes in standard format on LED
*/
void writeTimeToLED(DateTime now) {
  int h0 = convertDigits(now.hour(), 0, true);
  int h1 = convertDigits(now.hour(), 1, true);

  int m0 = convertDigits(now.minute(), 0, false);
  int m1 = convertDigits(now.minute(), 1, false);

  matrix.writeDigitNum(0, h0, true);
  matrix.writeDigitNum(1, h1, true);
  matrix.drawColon(true);
  matrix.writeDigitNum(3, m0, true);
  matrix.writeDigitNum(4, m1, true);
  matrix.writeDisplay();
}

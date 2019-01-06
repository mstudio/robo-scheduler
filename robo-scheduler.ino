// Date and time functions using a DS3231 RTC connected via I2C and Wire lib
#include <Wire.h>

// Library for RTC module DS3231, in case power is lost (which includes battery backup)
#include "RTClib.h"

// Library or LED
#include <Adafruit_GFX.h>

// Library for LED Backpack
#include "Adafruit_LEDBackpack.h"

// Library for eMic2 which controls time
#include <SoftwareSerial.h>
#include "Emic2TtsModule.h"

// Real-Time-Clock module
RTC_DS3231 rtc;

// 7 Segment LED module
Adafruit_7segment matrix = Adafruit_7segment();


const char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

#define NUM_ALARMS 3

const int times[NUM_ALARMS][2] = {{10, 3}, {20, 51}, {15, 10}};

const String messages[NUM_ALARMS] = {"hello there lady", "Pack your snacks. now. okaaaaayee. I am a ninja. Huzzah.", "whats your name"};

// Emic 2 Globals
const int emic2RxPin = 5;
const int emic2TxPin = 6;
SoftwareSerial emic2Serial = SoftwareSerial(emic2RxPin, emic2TxPin);
Emic2TtsModule emic2TtsModule = Emic2TtsModule(&emic2Serial);

void setup () {

  // RTC Setup
#ifndef ESP8266
  while (!Serial); // for Leonardo/Micro/Zero
#endif

  Serial.begin(9600);

  delay(3000); // wait for console opening

  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }

  if (rtc.lostPower()) {
    Serial.println("RTC lost power, lets set the time!");
    // following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
    // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  }

  // LED Setup
#ifndef __AVR_ATtiny85__
  Serial.begin(9600);
  Serial.println("7 Segment Backpack Test");
#endif
  matrix.begin(0x70);

  // Audio Setup
  Serial.print(F("Initializing Emic..."));
  pinMode(emic2RxPin, INPUT);
  pinMode(emic2TxPin, OUTPUT);
  emic2Serial.begin(9600);
  emic2TtsModule.init();
  emic2TtsModule.setVolume(10);
  emic2TtsModule.setWordsPerMinute(1000);
  emic2TtsModule.setVoice(9);
  //emic2TtsModule.playSingingDemo();
  //emic2TtsModule.say("Alex go do somthing you hate being miserble bilds character ");
  emic2TtsModule.say("calvin go do somthing you hate. being miserble builds character ");
  Serial.print(F("OK"));

}

/**gdxdsdsf
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
  Serial.print(daysOfTheWeek[now.dayOfTheWeek()]);
  Serial.print(") ");
  Serial.print(now.hour(), DEC);
  Serial.print(':');
  Serial.print(now.minute(), DEC);
  Serial.print(':');
  Serial.print(now.second(), DEC);
  Serial.println();
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

/**
 * Pronounce the actual message audio using emic2 module.
 * Then wait 1 minute so that the message does not repeat on the next loop.
 */
void sayMessage(String message) {
  Serial.print("say message: ");
  Serial.print(message);
  emic2TtsModule.say(message);

  delay(60000);
}

/**
 * Turns current hour and minute into text, e.g. 17:03 -> "5 oh 3";
 */
String getTimeMessage(DateTime now) {
  const String messageHour = (now.hour() > 12) ? String(now.hour() - 12) : String(now.hour());
  const String messageMin = (now.minute() < 10) ? "oh " + String(now.minute()) : String(now.minute());
  const String timeMessage = "It is" + messageHour + " " + messageMin + ".";
  return timeMessage;
}

/**
 * Loops through times array and looks for an hour/minute match.
 * If found, plays the appropriate message.
 */
void checkAlarms(DateTime now) {
  for (int i = 0; i < NUM_ALARMS; i++) {

    // hour and minute in array
    const int h = times[i][0];
    const int m = times[i][1];

    // if current hour and minute match what's in the array, say the time and message.
    if (h == now.hour() && m == now.minute()) {
      Serial.print("** FOUND HOUR AND MINUTE");
      Serial.println();
      const String message = messages[i];
      const String timeMessage = getTimeMessage(now);
      sayMessage(timeMessage + message);
    }
  }
}


void loop () {
  DateTime now = rtc.now();

  logTime(now);

  writeTimeToLED(now);

  checkAlarms(now);

  delay(1000);
}


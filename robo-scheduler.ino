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

  setupAudio();  
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


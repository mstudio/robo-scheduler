// Library for RTC module DS3231, in case power is lost (which includes battery backup)
#include "RTClib.h"

// Library for LED
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

// Define total number of alarms
#define NUM_ALARMS 3

// Define times of alarms (hour and minute)
const int times[NUM_ALARMS][2] = {{10, 3}, {20, 51}, {15, 10}};

// Define message of alarms
const String messages[NUM_ALARMS] = {"hello there lady", "Pack your snacks. now. okaaaaayee. I am a ninja. Huzzah.", "whats your name"};

// Emic 2 Globals
const int emic2RxPin = 5;
const int emic2TxPin = 6;
SoftwareSerial emic2Serial = SoftwareSerial(emic2RxPin, emic2TxPin);
Emic2TtsModule emic2TtsModule = Emic2TtsModule(&emic2Serial);

void setup () {

  Serial.begin(9600);

  delay(1000); // wait for console opening

  setupRTC();

  setupLED();

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


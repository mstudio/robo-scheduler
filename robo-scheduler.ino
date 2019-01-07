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

//const char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

// Define total number of alarms
#define NUM_ALARMS 5

// Define times of alarms (hour and minute)
const int times[NUM_ALARMS][2] = {{7, 30}, {8, 16}, {8, 15}, {8, 13}, {8, 14}};

// Define message of alarms
const String messages[NUM_ALARMS] = {"Wake up and eat breakfast", "Are you dressed for school. Get dressed.", "Is your lunch packed dad", "Dad did you pack your snack?", "Get ready for the bus Alex. do it! do it now!"};

// Emic 2 Globals
const int emic2RxPin = 5;
const int emic2TxPin = 6;
SoftwareSerial emic2Serial = SoftwareSerial(emic2RxPin, emic2TxPin);
Emic2TtsModule emic2TtsModule = Emic2TtsModule(&emic2Serial);

const int buttonAPin = 2;
const int ledPin =  13;
int buttonAState = 0;

// Jokes
// Define total number of jokes
#define NUM_JOKES 4

const String joke1 = "Knock knock .Stan    . Stan back, I'm coming in!";
const String joke2 = "Knock knock .Funnel   .The funnel start once you let me in.";
const String joke3 = "Knock knock .Garden    .Stop garden the door and let me in.";
const String joke4 = "Knock knock .I'm    .Don't you know you're own name?";

//#define JOKER "alsdkfjsdlkfas flk flkdjf lksdjf alksdfj klsdf alksdf asdfkd jflkas dfjasd; alkdfj adslkfj dskfajsdlksdj fldskjf slk;dfj lsdk;fj alsdkfjasdlkf jaslkdfj a"

void setup () {

  Serial.begin(9600);

  delay(1000); // wait for console opening

  // initialize the LED pin as an output for testing button A:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input for buttonA:
  pinMode(buttonAPin, INPUT);

  setupRTC();

  setupLED();

  setupAudio();
}

/**
   Loops through times array and looks for an hour/minute match.
   If found, plays the appropriate message.
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

  // read the state of the pushbutton value:
  buttonAState = digitalRead(buttonAPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonAState == HIGH) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
    tellAJoke(now);
  } else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
  }

  delay(100);
}


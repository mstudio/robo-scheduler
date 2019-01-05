#include <Time.h>
#include <TimeLib.h>
#include <SoftwareSerial.h>
#include "Emic2TtsModule.h"

// Stream parse states
enum ParseState {
  STATE_NORMAL,
  STATE_LINK_H,
  STATE_LINK_HT,
  STATE_LINK_HTT,
  STATE_LINK_HTTP,
  STATE_LINK_HTTPS,
  STATE_LINK_HTTP_COLON,
  STATE_LINK_HTTP_COLON_SLASH,
  STATE_LINK_FOUND,
  STATE_LINK_FALSE_POSITIVE,
  STATE_LINK_DONE
};

// Emic 2 Globals
const int emic2RxPin = 5;
const int emic2TxPin = 6;
SoftwareSerial emic2Serial = SoftwareSerial(emic2RxPin, emic2TxPin);
Emic2TtsModule emic2TtsModule = Emic2TtsModule(&emic2Serial);


void setup() {
  // Set up the Emic2 module.
  Serial.print(F("Initializing Emic..."));
  pinMode(emic2RxPin, INPUT);
  pinMode(emic2TxPin, OUTPUT);
  emic2Serial.begin(9600);
  emic2TtsModule.init();
  emic2TtsModule.setVolume(10);
  emic2TtsModule.setWordsPerMinute(150);
  //emic2TtsModule.setVoice(PerfectPaul);
  emic2TtsModule.playSingingDemo();
  Serial.print(F("OK"));
  
}


void loop() {
  //emic2TtsModule.say("Good morning children.");
  emic2TtsModule.say("It is 8:15. Pack your snacks and put your shoes on.");

  delay(60000);    // 1/2 second delay
}

// ---------------------------------------------------------------------------




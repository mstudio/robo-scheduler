// Library for RTC module DS3231, in case power is lost (which includes battery backup)
// #include "RTClib.h"

// // Library for LED
// #include <Adafruit_GFX.h>

// // Library for LED Backpack
// #include "Adafruit_LEDBackpack.h"

// Library for eMic2 which controls time
#include <SoftwareSerial.h>
#include "Emic2TtsModule.h"

// Emic 2 Globals
const int emic2RxPin = 52;
const int emic2TxPin = 50;
SoftwareSerial emic2Serial = SoftwareSerial(emic2RxPin, emic2TxPin);
Emic2TtsModule emic2TtsModule = Emic2TtsModule(&emic2Serial);

// Pins:
// 2: left tooth
// 3: left-mid tooth
// 4: right-mid tooth
// 5: right tooth
// 6: red tongue
// 7: orange answer
// 8: blue top

int voiceNumber = 0;
const int defaultVoiceSpeed = 200;

const int buttonPlusPin = 2;
const int buttonMinusPin = 3;
const int buttonTimesPin = 4;
const int buttonStatePin = 5;
const int buttonRiddlePin = 6;
const int buttonAnswerPin = 7;
const int buttonVoicePin = 8;
const int ledPin =  13;
int buttonPlusState = 1;
int buttonMinusState = 1;
int buttonTimesState = 1;
int buttonStateState = 1;
int buttonRiddleState = 1;
int buttonAnswerState = 1;
int buttonVoiceState = 1;

// math/riddles
boolean hasAnsweredRiddle = true;
boolean hasAnsweredUsState = true;
int mathNumberA;
int mathNumberB;
int mathAnswer;
String question;
String answer;

// Riddles/States
#define NUM_RIDDLES 25
#define NUM_STATES 50
int riddleCount = 0;
int UsStateCount = 0;

void setup () {

  Serial.begin(9600);

  delay(1000); // wait for console opening

  randomSeed(analogRead(0));

  Serial.print(F("Setup - random seed complete."));
  Serial.println();

  getRiddleQuestion(2);

  // initialize the LED pin as an output for testing:
  pinMode(ledPin, OUTPUT);

  // initialize the buttons on the face of the unit
  pinMode(buttonPlusPin, INPUT_PULLUP);
  pinMode(buttonMinusPin, INPUT_PULLUP);
  pinMode(buttonTimesPin, INPUT_PULLUP);
  pinMode(buttonStatePin, INPUT_PULLUP);
  pinMode(buttonRiddlePin, INPUT_PULLUP);
  pinMode(buttonAnswerPin, INPUT_PULLUP);
  pinMode(buttonVoicePin, INPUT_PULLUP);

  Serial.print("Setup - button setup complete.");
  Serial.println();
 
  shuffleRiddles();

  Serial.print("Setup - riddles complete.");
  Serial.println();

  shuffleStates();

  Serial.print("Setup - states complete.");

  setupAudio();

  Serial.print("Setup - audio complete.");
  Serial.println();
}

void loop () {

  // read the state of the pushbutton value:
  buttonPlusState = digitalRead(buttonPlusPin);
  if (buttonPlusState == LOW) {
    tellMath("plus", 100);
  }

  buttonMinusState = digitalRead(buttonMinusPin);
  if (buttonMinusState == LOW) {
    tellMath("minus", 100);
  }

  buttonTimesState = digitalRead(buttonTimesPin);
  if (buttonTimesState == LOW) {
    tellMath("times", 12);
  }

  buttonStateState = digitalRead(buttonStatePin);
  if (buttonStateState == LOW) {
    tellUSState();
  }

  buttonRiddleState = digitalRead(buttonRiddlePin);
  if (buttonRiddleState == LOW) {
    tellRiddle();
  }

  buttonAnswerState = digitalRead(buttonAnswerPin);
  if (buttonAnswerState == LOW) {
    tellAnswer();
  }

  buttonVoiceState = digitalRead(buttonVoicePin);
  if (buttonVoiceState == LOW) {
    changeVoice();
  }
  delay(10);
}


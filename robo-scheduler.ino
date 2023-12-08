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
const int buttonStatePin = 12;
const int buttonRiddlePin = 6;
const int buttonAnswerPin = 7;
const int buttonVoicePin = 8;
const int switchDoorPin = 9;
const int ledPin = 13;
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

// door
boolean doorOpen = false;
unsigned long doorOpenStartTime = 0;
unsigned long doorOpenTestTime = 0;

void setup()
{

  Serial.begin(9600);
  delay(1000); // wait for console opening
  randomSeed(analogRead(0));

  Serial.print(F("Setup - random seed complete."));
  Serial.println();

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
  pinMode(switchDoorPin, INPUT_PULLUP);

  Serial.print("Setup - button setup complete.");
  Serial.println();

  shuffleRiddles();

  Serial.print("Setup - riddles complete.");
  Serial.println();

  shuffleUsStates();

  Serial.print("Setup - states complete.");

  setupAudio();

  Serial.print("Setup - audio complete.");
  Serial.println();
}

void loop()
{
  // read the state of the pushbutton value:
  buttonPlusState = digitalRead(buttonPlusPin);
  if (buttonPlusState == LOW)
  {
    tellMath("plus", 100);
  }

  buttonMinusState = digitalRead(buttonMinusPin);
  if (buttonMinusState == LOW)
  {
    tellMath("minus", 100);
  }

  buttonTimesState = digitalRead(buttonTimesPin);
  if (buttonTimesState == LOW)
  {
    tellMath("times", 12);
  }

  buttonStateState = digitalRead(buttonStatePin);
  if (buttonStateState == LOW)
  {
    tellUsState();
    Serial.print("capital button is low");
    Serial.println();
  }
  else
  {
    Serial.print("capital button is HIGH");
    Serial.println();
  }

  buttonRiddleState = digitalRead(buttonRiddlePin);
  if (buttonRiddleState == LOW)
  {
    tellRiddle();
  }

  buttonAnswerState = digitalRead(buttonAnswerPin);
  if (buttonAnswerState == LOW)
  {
    tellAnswer();
  }

  buttonVoiceState = digitalRead(buttonVoicePin);
  if (buttonVoiceState == LOW)
  {
    changeVoice();
  }

  switchDoorState = digitalRead(switchDoorPin);
  // LOW: door is closed
  if (switchDoorState == LOW)
  {
    // if door was open, thank user for closing it.
    if (doorOpen)
    {
      doorOpen = false;
      float timeDeltaSec = getTimeDelta(doorOpenStartTime, millis());
      // Serial.print("Closed door: ");
      // Serial.print(timeDeltaSec);
      // Serial.print("sec");
      // Serial.println();
      thankForClosingDoor(timeDeltaSec);
    }
  }

  // HIGH: door is open
  if (switchDoorState == HIGH)
  {
    if (doorOpen)
    {
      // get change in time (ms)
      float timeDeltaSec = getTimeDelta(doorOpenTestTime, millis());
      Serial.print("Door Seconds: ");
      Serial.print(timeDeltaSec);
      Serial.println();

      if (timeDeltaSec >= 10)
      {
        Serial.print("Tell user to close door");
        tellToCloseDoor();
        // reset timer for another loop
        doorOpenTestTime = millis();
      }
    }
    else
    {
      // start doorOpen timer
      doorOpen = true;
      doorOpenTestTime = millis();
      doorOpenStartTime = millis();
    }
  }
  delay(10);
}

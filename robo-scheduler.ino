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

int voiceNumber = 1;
const int defaultVoiceSpeed = 300;

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
boolean hasAnsweredState = true;
int mathNumberA;
int mathNumberB;
int mathAnswer;
String question;
String answer;

// Riddles/States
#define NUM_RIDDLES 25
#define NUM_STATES 50
int riddleCount = 0;
int stateCount = 0;

const PROGMEM String r1[2] = {"What has one head, one foot and four legs?", "A bed."};
const PROGMEM String r2[2] = {"How can you spell cold with two letters?", "eye. see. Icy. Get it?"};
const PROGMEM String r3[2] = {"If you were in a race and passed the person in second place, what place would you be in?", "Second place."};
const PROGMEM String r4[2] = {"What state is surrounded by the most water?", "Hawaii."};
const PROGMEM String r5[2] = {"How many months have 28 days?", "All of them."};
const PROGMEM String r6[2] = {"How many books can you put into an empty backpack?", "One. After that, it's not empty."};
const PROGMEM String r7[2] = {"Which weighs more, a pound of feathers or a pound of bricks?", "Neither, they both weigh a pound."};
const PROGMEM String r8[2] = {"What has two hands, a round face, always runs, but stays in place?", "A clock."};
const PROGMEM String r9[2] = {"A box with no hinges, latch, or lid. Inside a golden treasure is hid. What am I?", "An egg."};
const PROGMEM String r10[2] = {"Why did the pony cough?", "He was a little horse."};
const PROGMEM String r11[2] = {"Which tire doesn't move when a car turns right?", "The spare tire."};
const PROGMEM String r12[2] = {"What travels around the world staying in the same corner.", "A stamp."};
const PROGMEM String r13[2] = {"What goes up but never goes down.", "Your age."};
const PROGMEM String r14[2] = {"What is full of holes but still holds water?", "A sponge."};
const PROGMEM String r15[2] = {"When is a door not a door?", "When it is a jar."};
const PROGMEM String r16[2] = {"What invention lets you look right through a wall?", "A window."};
const PROGMEM String r17[2] = {"What did the snowman say to the other snowman?", "Do you smell carrots."};
const PROGMEM String r18[2] = {"Why can’t you give Elsa a balloon?", "She will let it go."};
const PROGMEM String r19[2] = {"What room doesn’t have doors?", "A mushroom."};
const PROGMEM String r20[2] = {"Why did the golfer wear two pairs of pants?", "In case he got a hole in one."};
const PROGMEM String r21[2] = {"Why did the little boy throw his clock out the window?", "Because he wanted to see time fly."};
const PROGMEM String r22[2] = {"What has two legs but can’t walk?", "A pair of pants."};
const PROGMEM String r23[2] = {"Why are fish so smart?", "Because they live in schools."};
const PROGMEM String r24[2] = {"What do porcupines say when they kiss?", "Ouch."};
const PROGMEM String r25[2] = {"Why do tigers have stripes?", "So they don't get spotted."};


extern String riddles[NUM_RIDDLES][2] = {r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, r12, r13, r14, r15, r16, r17, r18, r19, r20, r21, r22, r23, r24, r25};

//const String s1[2] = {"Alabama", "Montgomery"};
//const String s2[2] = {"Alaska", "Juneau"};
//const String s3[2] = {"Arizona", "Phoenix"};
//const String s4[2] = {"Arkansas", "Little Rock"};
//const String s5[2] = {"California", "Sacramento"};
//const String s6[2] = {"Colorado", "Denver"};
//const String s7[2] = {"Connecticut", "Hartford"};
//const String s8[2] = {"Delaware", "Dover"};
//const String s9[2] = {"Hawaii", "Honolulu"};
//const String s10[2] = {"Florida", "Tallahassee"};
//const String s11[2] = {"Georgia", "Atlanta"};
//const String s12[2] = {"Idaho", "Boise"};
//const String s13[2] = {"Illinois", "Springfield"};
//const String s14[2] = {"Indiana", "Indianapolis"};
//const String s15[2] = {"Iowa", "Des Moines"};
//const String s16[2] = {"Kansas", "Topeka"};
//const String s17[2] = {"Kentucky", "Frankfort"};
//const String s18[2] = {"Louisiana", "Baton Rouge"};
//const String s19[2] = {"Maine", "Augusta"};
//const String s20[2] = {"Maryland", "Annapolis"};
//const String s21[2] = {"Massachusetts", "Boston"};
//const String s22[2] = {"Michigan", "Lansing"};
//const String s23[2] = {"Minnesota", "St. Paul"};
//const String s24[2] = {"Mississippi", "Jackson"};
//const String s25[2] = {"Missouri", "Jefferson City"};
//const String s26[2] = {"Montana", "Helena"};
//const String s27[2] = {"Nebraska", "Lincoln"};
//const String s28[2] = {"Nevada", "Carson City"};
//const String s29[2] = {"New Hampshire", "Concord"};
//const String s30[2] = {"New Jersey", "Trenton"};
//const String s31[2] = {"New Mexico", "Santa Fe"};
//const String s32[2] = {"North Carolina", "Raleigh"};
//const String s33[2] = {"North Dakota", "Bismarck"};
//const String s34[2] = {"New York", "Albany"};
//const String s35[2] = {"Ohio", "Columbus"};
//const String s36[2] = {"Oklahoma", "Oklahoma City"};
//const String s37[2] = {"Oregon", "Salem"};
//const String s38[2] = {"Pennsylvania", "Harrisburg"};
//const String s39[2] = {"Rhode Island", "Providence"};
//const String s40[2] = {"South Carolina", "Columbia"};
//const String s41[2] = {"South Dakota", "Pierre"};
//const String s42[2] = {"Tennessee", "Nashville"};
//const String s43[2] = {"Texas", "Austin"};
//const String s44[2] = {"Utah", "Salt Lake City"};
//const String s45[2] = {"Vermont", "Montpelier"};
//const String s46[2] = {"Virginia", "Richmond"};
//const String s47[2] = {"Washington", "Olympia"};
//const String s48[2] = {"West Virginia", "Charleston"};
//const String s49[2] = {"Wisconsin", "Madison"};
//const String s50[2] = {"Wyoming", "Cheyenne"};

//extern String USStates[NUM_STATES][2] = {s1, s2, s3, s4, s5, s6, s7, s8, s9, s10, s11, s12, s13, s14, s15, s16, s17, s18, s19, s20, s21, s22, s23, s24, s25, s26, s27, s28, s29, s30, s31, s32, s33, s34, s35, s36, s37, s38, s39, s40, s41, s42, s43, s44, s45, s46, s47, s48, s49, s50};
//
// extern String USStates[2][2] = {{"a", "b"}, {"c", "d"}};
void setup () {

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

  Serial.print("Setup - button setup complete.");
  Serial.println();
 
  shuffleRiddles();

  Serial.print("Setup - riddles complete.");
  Serial.println();

//  shuffleStates();

  Serial.print("Setup - states complete.");

  setupAudio();

  Serial.print("Setup - audio complete.");
  Serial.println();
}

void loop () {
  // DateTime now = rtc.now();

  Serial.print("looping...");
  Serial.println();

  // logTime(now);

  //writeTimeToLED(now);

  // checkAlarms(now);

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
    voiceNumber = voiceNumber + 1;

    if (voiceNumber > 7) {
      voiceNumber = 1;
    }

    const String robotName = "FFreddy";

    switch (voiceNumber) {
      case 2:
        robotName = "Eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee lie ja";
        break;
      case 3:
        robotName = "Pop. corn";
        break;
      case 4:
        robotName = "Professor. Higgins";
        break;
      case 5:
        robotName = "Spoiled. brat";
        break;
      case 6:
        robotName = "Mister. Boring";
        break;
      case 7:
        robotName = "Filbert";
        break;
      default:
        // statements
        break;
    }

    emic2TtsModule.setWordsPerMinute(defaultVoiceSpeed);
    emic2TtsModule.setVoice(voiceNumber);
    const String message = "Hello. My name is " + robotName;
    emic2TtsModule.say(message);
  }


  delay(10);
}


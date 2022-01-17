/**
   Initialize the emic2 module
*/
void setupAudio()
{
  Serial.print(F("Initializing Emic..."));
  pinMode(emic2RxPin, INPUT);
  pinMode(emic2TxPin, OUTPUT);
  emic2Serial.begin(9600);
  emic2TtsModule.init();
  emic2TtsModule.setVolume(10);
  emic2TtsModule.setWordsPerMinute(defaultVoiceSpeed);
  emic2TtsModule.setLanguage(0);
  emic2TtsModule.setVoice(3);
  emic2TtsModule.say("Booting up. Checking system for");
  emic2TtsModule.setVoice(1);
  emic2TtsModule.say("Power");
  emic2TtsModule.setVoice(3);
  emic2TtsModule.say("Checking system for");
  emic2TtsModule.setVoice(1);
  emic2TtsModule.say("Memory.");
  emic2TtsModule.setVoice(3);
  emic2TtsModule.say("Checking system for");
  emic2TtsModule.setVoice(1);
  emic2TtsModule.say("Temperature. All systems go.");
  emic2TtsModule.setVoice(voiceNumber);
  Serial.print(F("emic2 OK"));
}


/**
 * Randomizes the array of riddles
 */
void shuffleRiddles() {
//    Serial.print(F("shuffling riddles...."));
//   for (int a = 0; a < NUM_RIDDLES; a++)
//   {
//     int r = random(a, NUM_RIDDLES - 1);
//     String temp[2] = riddles[a];
//     riddles[a][0] = riddles[r][0];
//     riddles[a][1] = riddles[r][1];
//     riddles[r][0] = temp[0];
//     riddles[r][1] = temp[1];
// //     Serial.print(F("shuffling riddle a " + String(a)));
// //     Serial.println();
// //     Serial.print(F("a0 " + String(riddles[a][0])));
// //     Serial.println();
// //     Serial.print(F("a1 " + String(riddles[a][1])));
// //     Serial.println();
//   }
}


/**
 * Randomizes the array of states
 */
void shuffleStates() {
//  Serial.print(F("shuffle states. "));
//  for (int a = 0; a < 2; a++)
//  {
//    int r = random(a, 2);
//    String temp[2] = USStates[a];
//    USStates[a][0] = USStates[r][0];
//    USStates[a][1] = USStates[r][1];
//    USStates[r][0] = temp[0];
//    USStates[r][1] = temp[1];
////    Serial.print("shuffling state a " + String(a));
////    Serial.println();
//  }
//  Serial.print(F("shuffle states done. "));
}

/**
   Pronounce the actual message audio using emic2 module.
   Then wait 1 minute so that the message does not repeat on the next loop.
*/
// void sayMessage(String message)
// {
//   Serial.print("say message: ");
//   Serial.print(message);
//   emic2TtsModule.say(message);

//   delay(60000);
// }


/**
   operator: plus, minus, times, divided by
*/
void tellMath(String mathType, int limit)
{
  emic2TtsModule.setWordsPerMinute(110);
  mathNumberA = random(limit + 1);
  mathNumberB = random(limit + 1);
  hasAnsweredRiddle = true;
  hasAnsweredUsState = true;

  if (mathType == "minus")
  {
    // minus / subtraction
    if (mathNumberB > mathNumberA)
    {
      int temp = mathNumberA;
      mathNumberA = mathNumberB;
      mathNumberB = temp;
    }
    mathAnswer = mathNumberA - mathNumberB;
  }
  else if (mathType == "times")
  {
    // times / multiplication
    mathAnswer = mathNumberA * mathNumberB;
  }
  else if (mathType == "divided by")
  {
    // divided by / division
    int tempAnswer = mathNumberA * mathNumberB;
    mathAnswer = mathNumberA;
    mathNumberA = tempAnswer;
  }
  else
  {
    // plus / addition
    mathAnswer = mathNumberA + mathNumberB;
  }
  const String q = String(mathNumberA) + " " + mathType + " " + String(mathNumberB);
  const String message = "What is " + q;
  answer = "The answer to " + q + " is " + String(mathAnswer);
  emic2TtsModule.say(message);
  emic2TtsModule.setWordsPerMinute(defaultVoiceSpeed);

}

void tellUSState() {
  emic2TtsModule.setWordsPerMinute(110);
  hasAnsweredRiddle = true;
  if (hasAnsweredUsState) {
    hasAnsweredUsState = false;   
    if (UsStateCount >= 50) {
      UsStateCount = 0;
      shuffleStates();
    } else {
      UsStateCount ++;
    }
  }
  
  question = String(getUSState(UsStateCount));
  answer = "The capital of " + question + " is " + String(getUSCapital(UsStateCount));
  emic2TtsModule.say("What is the capital of " + String(question));
  emic2TtsModule.setWordsPerMinute(defaultVoiceSpeed);





  // emic2TtsModule.say("Yo. was up, dude");
  // emic2TtsModule.setWordsPerMinute(defaultVoiceSpeed);
//  Serial.println("Tell US state");
//  emic2TtsModule.setWordsPerMinute(110);
//  hasAnsweredRiddle = true;
//  Serial.println("telling state");
//  if (hasAnsweredState) {
//    Serial.println("telling state 2");
//    hasAnsweredState = false;   
//    if (stateCount > 48) {
//      stateCount = 0;
//      shuffleStates();
//    } else {
//      stateCount ++;
//    }
//    answer = String(USStates[stateCount][1]);
//    question = String(USStates[stateCount][0]);
//    Serial.println("state count: " + String(stateCount));
//    Serial.println("question:");
//    Serial.print(String(question));
//    const String message = "What is the capital of " + String(question);
//    emic2TtsModule.say(message);
//  }
  
}


void tellRiddle() {
  emic2TtsModule.setWordsPerMinute(110);
  hasAnsweredUsState = true;
  if (hasAnsweredRiddle) {
    hasAnsweredRiddle = false;   
    if (riddleCount > NUM_RIDDLES + 1) {
      riddleCount = 0;
      shuffleRiddles();
    } else {
      riddleCount ++;
    }
  }
  answer = String(getRiddleAnswer(riddleCount)) + getLaugh();
  question = String(getRiddleQuestion(riddleCount));
  emic2TtsModule.say(question);
  emic2TtsModule.setWordsPerMinute(defaultVoiceSpeed);
}

/**
 * Returns a random laugh String
 */
String getLaugh() {
  const String laughs[11] = {"ha ha ha ha ha", "hee hee hee", "that was so funny", "that what hilarious", "hard dee har har", "whoo, that was a real knee slapper", "tee hee hee", "hoo hoo hee", "uh.. ok", "ha ha ha ha ha ha ha ha ha ha ha ha ha ha ha", "el. oh. el."};
  int randomLaughNumber = random(11);
  String laugh = String(laughs[randomLaughNumber]);
  return laugh;
}

/**
 * Answer to riddle or math question
 */
void tellAnswer() {
  hasAnsweredRiddle = true;
  hasAnsweredUsState = true;
  emic2TtsModule.setWordsPerMinute(80);
  emic2TtsModule.say(answer);
  emic2TtsModule.setWordsPerMinute(defaultVoiceSpeed);
}

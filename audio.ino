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
  emic2TtsModule.setWordsPerMinute(400);
  emic2TtsModule.setVoice(2);
  emic2TtsModule.playSingingDemo();
  emic2TtsModule.playSpanishDemo();
  emic2TtsModule.setLanguage(0);
  //emic2TtsModule.setLanguage(2); // latin spanish
  //emic2TtsModule.say("Alex go do somthing you hate being miserble bilds charactergfdsdfddsdsfsfdsdfssddsxvg hvnvcxxvv  x zvb   hgvnm,.fgnfzxcvbvbnbvccvbvcvcxcvvcvxxcvcvxcxdtghgfgfdsdfgfdsfsdfkjkjhjhhkjkjmjhggvvcgcvbcbbcbvc");
  //emic2TtsModule.say("Buenos días ");
  emic2TtsModule.say("Ready. All Systems go.");
  /*
    emic2TtsModule.say("Ok. I'm going to walk away now.");
    emic2TtsModule.setVolume(5);
    emic2TtsModule.say("I'm walking away");
    emic2TtsModule.setVolume(0);
    emic2TtsModule.say("See you later.");
    emic2TtsModule.setVolume(-5);
    emic2TtsModule.say("Bye");
    emic2TtsModule.setVolume(-10);
    emic2TtsModule.say("Later.");
    emic2TtsModule.setVolume(-15);
    emic2TtsModule.say("Ok. I'm gone.");
    emic2TtsModule.setVolume(10);
  */
  Serial.print(F("emic2 OK"));
}


/**
 * Randomizes the array of riddles
 */
void shuffleRiddles() {
  for (int a = 0; a < NUM_RIDDLES; a++)
  {
    int r = random(a, NUM_RIDDLES - 1);
    String temp[2] = riddles[a];
    riddles[a][0] = riddles[r][0];
    riddles[a][1] = riddles[r][1];
    riddles[r][0] = temp[0];
    riddles[r][1] = temp[1];
     Serial.print("shuffling riddle a " + String(a));
     Serial.println();
     Serial.print("a0 " + String(riddles[a][0]));
     Serial.println();
     Serial.print("a1 " + String(riddles[a][1]));
     Serial.println();
  }
}


/**
 * Randomizes the array of states
 */
void shuffleStates() {
  Serial.print("shuffle states. ");
  for (int a = 0; a < 2; a++)
  {
    int r = random(a, 2);
    String temp[2] = USStates[a];
    USStates[a][0] = USStates[r][0];
    USStates[a][1] = USStates[r][1];
    USStates[r][0] = temp[0];
    USStates[r][1] = temp[1];
    Serial.print("shuffling state a " + String(a));
    Serial.println();
  }
  Serial.print("shuffle states done. ");
}

/**
   Pronounce the actual message audio using emic2 module.
   Then wait 1 minute so that the message does not repeat on the next loop.
*/
void sayMessage(String message)
{
  Serial.print("say message: ");
  Serial.print(message);
  emic2TtsModule.say(message);

  delay(60000);
}

/**
   Turns current hour and minute into text, e.g. 17:03 -> "5 oh 3";
*/
String getTimeMessage(DateTime now)
{
  const String messageHour = (now.hour() > 12) ? String(now.hour() - 12) : String(now.hour());
  const String messageMin = (now.minute() < 10) ? "oh " + String(now.minute()) : String(now.minute());
  const String timeMessage = "It is " + messageHour + " " + messageMin + ".";
  return timeMessage;
}

void tellTime() {
 DateTime now = rtc.now();
 emic2TtsModule.setWordsPerMinute(110);
 emic2TtsModule.say(getTimeMessage(now)); 
}

/**
   operator: plus, minus, times, divided by
*/
void tellMath(String mathType, int limit)
{
  emic2TtsModule.setWordsPerMinute(110);
  mathNumberA = random(limit + 1);
  mathNumberB = random(limit + 1);
  hasAnsweredRiddle = true;
  hasAnsweredState = true;

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
  answer = "The answer is " + String(mathAnswer);
  const String message = "What is " + String(mathNumberA) + " " + mathType + " " + String(mathNumberB);
  emic2TtsModule.say(message);

}

void tellUSState() {
  Serial.println("Tell US state");
  emic2TtsModule.setWordsPerMinute(110);
  hasAnsweredRiddle = true;
  Serial.println("telling state");
  if (hasAnsweredState) {
    Serial.println("telling state 2");
    hasAnsweredState = false;   
    if (stateCount > 48) {
      stateCount = 0;
      shuffleStates();
    } else {
      stateCount ++;
    }
    answer = String(USStates[stateCount][1]);
    question = String(USStates[stateCount][0]);
    Serial.println("state count: " + String(stateCount));
    Serial.println("question:");
    Serial.print(String(question));
    const String message = "What is the capital of " + String(question);
    emic2TtsModule.say(message);
  }
  
}


void tellRiddle() {
  emic2TtsModule.setWordsPerMinute(110);
  hasAnsweredState = true;
  if (hasAnsweredRiddle) {
    hasAnsweredRiddle = false;   
    if (riddleCount > NUM_RIDDLES + 1) {
      riddleCount = 0;
      shuffleRiddles();
    } else {
      riddleCount ++;
    }
    answer = String(riddles[riddleCount][1]) + getLaugh();
    question = String(riddles[riddleCount][0]);
    Serial.print("** riddle ans");
    Serial.println();
    Serial.print(answer);
    emic2TtsModule.say(question);
  }
  
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
  hasAnsweredState = true;
  emic2TtsModule.setWordsPerMinute(80);
  emic2TtsModule.say(answer);
}

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
  emic2TtsModule.setVoice(4);
  emic2TtsModule.setWordsPerMinute(250);
  emic2TtsModule.say("Powering, up.. Battery. Check. Processor. Check. Sassy ness. Check.");
  Serial.print(F("emic2 OK"));
}

/**
   operator: plus, minus, times, divided by
*/
void tellMath(String mathType, int limit)
{
  emic2TtsModule.setWordsPerMinute(160);
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

/**
 * Returns a random laugh String
 */
String getLaugh()
{
  const String laughs[11] = {"ha ha", "hee hee hee", "that was so funny", "that what hilarious", "hard dee har har", "whoo, that was a real knee slapper", "HA HA", "hoo hoo hee", "uh.. ok", "ha ha ha", "el. oh. el."};
  int randomLaughNumber = random(11);
  String laugh = String(laughs[randomLaughNumber]);
  //  String laugh = String(laughs[6]);
  return laugh;
}

/**
 * Answer to riddle or math question
 */
void tellAnswer()
{
  hasAnsweredRiddle = true;
  hasAnsweredUsState = true;
  emic2TtsModule.setWordsPerMinute(80);
  emic2TtsModule.say(answer);
  emic2TtsModule.setWordsPerMinute(defaultVoiceSpeed);
}

/**
 * Tell to close door
 */
void tellToCloseDoor()
{
  emic2TtsModule.setVoice(4);
  emic2TtsModule.setWordsPerMinute(250);
  emic2TtsModule.say(getThanks());
  emic2TtsModule.setWordsPerMinute(defaultVoiceSpeed);
}

String getThanks()
{
  const String thanks[9]={"Thank you very much.", "Thanks.", "Danka.", "Thanks, champ.", "Well done.", "Finally. sheesh.", "Took ya long enough.", "Thanks, dude.", "I'm not, your maid."};
  return String(thanks[random(9)]);
}

void thankForClosingDoor(float sec)
{
  // emic2TtsModule.setVoice(1);
  emic2TtsModule.setWordsPerMinute(200);
  if (sec < 5) {
    const String praise = getPraise();
    int r = random(2);
    // vary the wording a bit...
    String msg;
    if (r < 1) {
     msg = String(praise) + ". You closed the cabinet in " + String(sec) + " seconds.";
    } else {
      msg = String(praise) + ". It only took you " + String(sec) + " seconds to close the cabinet.";
    }
    emic2TtsModule.say(msg);
  } else {
    emic2TtsModule.say(getThanks());
  }
  emic2TtsModule.setWordsPerMinute(defaultVoiceSpeed);
}
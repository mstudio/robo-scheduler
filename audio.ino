/**
   Initialize the emic2 module
*/
void setupAudio() {
  Serial.print(F("Initializing Emic..."));
  pinMode(emic2RxPin, INPUT);
  pinMode(emic2TxPin, OUTPUT);
  emic2Serial.begin(9600);
  emic2TtsModule.init();
  emic2TtsModule.setVolume(10);
  emic2TtsModule.setWordsPerMinute(250);
  emic2TtsModule.setVoice(1);
  //emic2TtsModule.playSingingDemo();
  //emic2TtsModule.playSpanishDemo();
  emic2TtsModule.setLanguage(0);
  //emic2TtsModule.setLanguage(2); // latin spanish
  //emic2TtsModule.say("Alex go do somthing you hate being miserble bilds character ");
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
   Pronounce the actual message audio using emic2 module.
   Then wait 1 minute so that the message does not repeat on the next loop.
*/
void sayMessage(String message) {
  Serial.print("say message: ");
  Serial.print(message);
  emic2TtsModule.say(message);

  delay(60000);
}



/**
   Turns current hour and minute into text, e.g. 17:03 -> "5 oh 3";
*/
String getTimeMessage(DateTime now) {
  const String messageHour = (now.hour() > 12) ? String(now.hour() - 12) : String(now.hour());
  const String messageMin = (now.minute() < 10) ? "oh " + String(now.minute()) : String(now.minute());
  const String timeMessage = "It is " + messageHour + " " + messageMin + ".";
  return timeMessage;
}

void tellAJoke(DateTime now) {


  emic2TtsModule.setWordsPerMinute(150);

  String timeMessage = getTimeMessage(now);

  int randomNumber = random(NUM_JOKES) + 1;


  String joke = joke1;
  if (randomNumber == 2) {
    joke = joke2;
  }
  if (randomNumber == 3) {
    joke = joke3;
  }
  if (randomNumber == 4) {
    joke = joke4;
  }

  Serial.print(joke);
  Serial.print(timeMessage);
  emic2TtsModule.say(timeMessage);// + "Here is a joke for you.          " + joke);
  //delay(2000);
  emic2TtsModule.say("Here is a joke for you.");
  //delay(3000);
  emic2TtsModule.say(joke);

  const String laugh1 = "ha ha ha ha ha";
  const String laugh2 = "hee hee hee";
  const String laugh3 = "that was so funny";
  const String laugh4 = "that what hilarious";

  delay(300);

  int randomLaughNumber = random(4) + 1;


  String laugh = laugh1;
  if (randomLaughNumber == 2) {
    laugh = laugh2;
  }
  if (randomLaughNumber == 3) {
    laugh = laugh3;
  }
  if (randomLaughNumber == 4) {
    laugh = laugh4;
  }

  emic2TtsModule.say(laugh);






}


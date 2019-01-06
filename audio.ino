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
  //emic2TtsModule.say("Alex go do somthing you hate being miserble bilds character ");
  //emic2TtsModule.say("Alex go do somthing you hate. being miserble builds character ");
  emic2TtsModule.say("Ready. All Systems go.");
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
  
  


}


// 0-8 Voices

void changeVoice() {
  voiceNumber = voiceNumber + 1;

  if (voiceNumber > 8) {
    voiceNumber = 0;
  }

  const String robotName = "";

  switch (voiceNumber) {
    case 0:
      robotName = "bozo";
      break;
    case 1:
      robotName = "Freddy";
      break;
    case 2:
      robotName = "Ee lie ja";
      break;
    case 3:
      robotName = "Pop corn";
      break;
    case 4:
      robotName = "Professor, Higgins";
      break;
    case 5:
      robotName = "Jimbo";
      break;
    case 6:
      robotName = "Mister Boring";
      break;
    case 7:
      robotName = "Filbert";
      break;
    case 8:
      robotName = "super man";
      break;
    default:
      break;
  }

  emic2TtsModule.setWordsPerMinute(defaultVoiceSpeed);
  emic2TtsModule.setVoice(voiceNumber);
  const String message = "Hello. My name is, " + robotName;
  emic2TtsModule.say(message);
}

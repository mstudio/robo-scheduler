// C++ code
//
// FILE: randomizeArray.ino
// AUTHOR: Rob Tillaart
// VERSION: 0.1.00
// PURPOSE: randomize an Array with in size steps
// DATE: 2012-11-18
// URL:
//
// Released to the public domain
//

void scrambleArray(int *array, int size)
{
  int last = 0;
  int temp = array[last];
  for (int i = 0; i < size; i++)
  {
    int index = random(size);
    array[last] = array[index];
    last = index;
  }
  array[last] = temp;
}

/**
 * @returns time difference, in seconds
 */
float getTimeDelta(unsigned long startTime, unsigned long nowTime)
{
  unsigned long timeDelta = nowTime - startTime;
  float timeDeltaSec = timeDelta / 1000.0;
  return timeDeltaSec;
}

/**
 * @returns a random phrase
 */
String getPraise() {
  const String praiseArray[12] = {"Great job", "Nice Job", "Excellent", "Well done", "Nice work", "Wow", "Fantastic", "Super", "Terrific", "Outstanding", "Way to go", "Wa wa, we wa."};
  int i = random(12);
  Serial.print(i);
  Serial.println();
  return praiseArray[i];
}

String getThanks()
{
  const String thanks[9]={"Thank you very much.", "Thanks.", "Danka.", "Thanks, champ.", "Well done.", "Finally. sheesh.", "Took ya long enough.", "Thanks, dude.", "I'm not, your maid."};
  return String(thanks[random(9)]);
}

String getAttention() {
  const String attArray[9] = {"Excuse me..", "Is anyone out there?", "Hello?", "Hey there..", "Is anyone listening?", "Come on..", "Attention..", "Alert. Alert..", "This is a public, service announcement.."};
  return attArray[random(9)];
}


/**
 *
 * JS to generate
 let output = '';
for (var i = 0; i<=49; i++) {
    output += String(i) + ', ';
}
*/
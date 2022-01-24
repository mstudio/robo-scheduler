int shuffledRiddleOrder[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93};
int RiddleTotal = 94;
int RiddleIndex = 0;

const char Riddle_q1[] PROGMEM = "Which letter of the alphabet has the most water?";
const char Riddle_a1[] PROGMEM = "C";
const char Riddle_q2[] PROGMEM = "What kind of dog keeps the best time?";
const char Riddle_a2[] PROGMEM = "Watchdog";
const char Riddle_q3[] PROGMEM = "What time of day, when written in a capital letters, is the same forwards, backwards and upside down?";
const char Riddle_a3[] PROGMEM = "Noon";
const char Riddle_q4[] PROGMEM = "If you were in a race and passed the person in second place, what place would you be in?";
const char Riddle_a4[] PROGMEM = "Second place.";
const char Riddle_q5[] PROGMEM = "How can you spell cold with two letters?";
const char Riddle_a5[] PROGMEM = "eye. see. Icy. Get it?";
const char Riddle_q6[] PROGMEM = "What state is surrounded by the most water?";
const char Riddle_a6[] PROGMEM = "Ha, why, eee.";
const char Riddle_q7[] PROGMEM = "How many months have 28 days?";
const char Riddle_a7[] PROGMEM = "All of them.";
const char Riddle_q8[] PROGMEM = "What has a face and two hands but no arms or legs?";
const char Riddle_a8[] PROGMEM = "Clock";
const char Riddle_q9[] PROGMEM = "What five-letter word becomes shorter when you add two letters to it?";
const char Riddle_a9[] PROGMEM = "Short";
const char Riddle_q10[] PROGMEM = "What word begins and ends with an 'E' but only has one letter?";
const char Riddle_a10[] PROGMEM = "Envelope";
const char Riddle_q11[] PROGMEM = "What has a neck but no head?";
const char Riddle_a11[] PROGMEM = "Bottle";
const char Riddle_q12[] PROGMEM = "What type of cheese is made backwards?";
const char Riddle_a12[] PROGMEM = "Edam. ee. dee. aye. em";
const char Riddle_q13[] PROGMEM = "What gets wetter as it dries?";
const char Riddle_a13[] PROGMEM = "A Towel";
const char Riddle_q14[] PROGMEM = "Which letter of the alphabet has the most water?";
const char Riddle_a14[] PROGMEM = "C";
const char Riddle_q15[] PROGMEM = "What starts with a 'P', ends with an 'E' and has thousands of letters?";
const char Riddle_a15[] PROGMEM = "Post Office";
const char Riddle_q16[] PROGMEM = "What has to be broken before you can eat it?";
const char Riddle_a16[] PROGMEM = "Egg";
const char Riddle_q17[] PROGMEM = "What begins with T, ends with T and has T in it?";
const char Riddle_a17[] PROGMEM = "Teapot";
const char Riddle_q18[] PROGMEM = "Teddy bears are never hungry because they are always what?";
const char Riddle_a18[] PROGMEM = "Stuffed";
const char Riddle_q19[] PROGMEM = "What belongs to you but others use it more than you do?";
const char Riddle_a19[] PROGMEM = "Name";
const char Riddle_q20[] PROGMEM = "The more you take aways, the larger it becomes? What is it?";
const char Riddle_a20[] PROGMEM = "Hole";
const char Riddle_q21[] PROGMEM = "What is full of holes, but can still hold a lot of water?";
const char Riddle_a21[] PROGMEM = "Sponge";
const char Riddle_q22[] PROGMEM = "How many books can you put into an empty backpack?";
const char Riddle_a22[] PROGMEM = "One. After that, it is not empty.";
const char Riddle_q23[] PROGMEM = "What do you get when you cross an automobile with a household animal?";
const char Riddle_a23[] PROGMEM = "Carpet";
const char Riddle_q24[] PROGMEM = "Mary's father has 4 children; three are named Nana, Nene, and Nini. So what is the 4th child's name?";
const char Riddle_a24[] PROGMEM = "Mary";
const char Riddle_q25[] PROGMEM = "Which weighs more, a pound of feathers or a pound of bricks?";
const char Riddle_a25[] PROGMEM = "Neither, they both weigh a pound.";
const char Riddle_q26[] PROGMEM = "The more of them you take, the more you leave behind. What are they?";
const char Riddle_a26[] PROGMEM = "Footsteps";
const char Riddle_q27[] PROGMEM = "What is that you will break everytime you name it?";
const char Riddle_a27[] PROGMEM = "Silence";
const char Riddle_q28[] PROGMEM = "What has four fingers and one thumb, but is not alive?";
const char Riddle_a28[] PROGMEM = "Glove";
const char Riddle_q29[] PROGMEM = "What flies without wings?";
const char Riddle_a29[] PROGMEM = "Time";
const char Riddle_q30[] PROGMEM = "What turns everything around, but does not move?";
const char Riddle_a30[] PROGMEM = "Mirror";
const char Riddle_q31[] PROGMEM = "Which tire doesnt move when a car turns right?";
const char Riddle_a31[] PROGMEM = "The spare tire.";
const char Riddle_q32[] PROGMEM = "What word looks the same upside down and backwards?";
const char Riddle_a32[] PROGMEM = "Swims";
const char Riddle_q33[] PROGMEM = "When is a door not a door?";
const char Riddle_a33[] PROGMEM = "When it is a jar";
const char Riddle_q34[] PROGMEM = "Your mother's brother's only brother-in-law is asleep on your coach. Who is asleep on your couch?";
const char Riddle_a34[] PROGMEM = "Dad";
const char Riddle_q35[] PROGMEM = "What's the difference between here and there?";
const char Riddle_a35[] PROGMEM = "The letter Tee";
const char Riddle_q36[] PROGMEM = "What goes up and down without moving?";
const char Riddle_a36[] PROGMEM = "Stairs";
const char Riddle_q37[] PROGMEM = "Take off my skin and I won't cry, but you will, What am I?";
const char Riddle_a37[] PROGMEM = "Onion";
const char Riddle_q38[] PROGMEM = "What doesn't get any wetter, no matter how much rain falls on it?";
const char Riddle_a38[] PROGMEM = "Water";
const char Riddle_q39[] PROGMEM = "What sits in a corner while traveling all around the world?";
const char Riddle_a39[] PROGMEM = "Stamp";
const char Riddle_q40[] PROGMEM = "I have a face, two arms, and two hands, yet I can not move. I count to twelve, yet I can not speak. I can still tell you something everyday.";
const char Riddle_a40[] PROGMEM = "Clock";
const char Riddle_q41[] PROGMEM = "You enter a dark room. You have only one match. There is an oil lamp, a furnace, and a stove in the room. Which would you light first?";
const char Riddle_a41[] PROGMEM = "Match";
const char Riddle_q42[] PROGMEM = "What did the snowman say to the other snowman?";
const char Riddle_a42[] PROGMEM = "Do you smell carrots.";
const char Riddle_q43[] PROGMEM = "What do you call a dog that sweats so much?";
const char Riddle_a43[] PROGMEM = "Hotdog";
const char Riddle_q44[] PROGMEM = "What do you call a rabbit with fleas?";
const char Riddle_a44[] PROGMEM = "Bugs Bunny";
const char Riddle_q45[] PROGMEM = "Why did the golfer wear two pairs of pants?";
const char Riddle_a45[] PROGMEM = "In case he got a hole in one.";
const char Riddle_q46[] PROGMEM = "What kind of apple has a short temper?";
const char Riddle_a46[] PROGMEM = "Crabapple";
const char Riddle_q47[] PROGMEM = "What do you do with a dead chemist?";
const char Riddle_a47[] PROGMEM = "Barium";
const char Riddle_q48[] PROGMEM = "What calls for help, when written in capital letters, is the same forwards, backwards and upside down?";
const char Riddle_a48[] PROGMEM = "ess Oh ess";
const char Riddle_q49[] PROGMEM = "What body part is pronounced as one letter but written with three, only two different letters are used?";
const char Riddle_a49[] PROGMEM = "Eye";
const char Riddle_q50[] PROGMEM = "Why are fish so smart?";
const char Riddle_a50[] PROGMEM = "Because they live in schools.";
const char Riddle_q51[] PROGMEM = "Feed me and I live, give me something to drink and i'll die, What am I?";
const char Riddle_a51[] PROGMEM = "Fire";
const char Riddle_q52[] PROGMEM = "What keeps things green and keeps kids occupied in the summertime?";
const char Riddle_a52[] PROGMEM = "Sprinkler";
const char Riddle_q53[] PROGMEM = "What do porcupines say when they kiss?";
const char Riddle_a53[] PROGMEM = "Ouch";
const char Riddle_q54[] PROGMEM = "Why do tigers have stripes?";
const char Riddle_a54[] PROGMEM = "So they dont get spotted";
const char Riddle_q55[] PROGMEM = "Brings you may flowers";
const char Riddle_a55[] PROGMEM = "Showers";
const char Riddle_q56[] PROGMEM = "A shower that lights up the sky";
const char Riddle_a56[] PROGMEM = "Meteor shower";
const char Riddle_q57[] PROGMEM = "Longer than a decade and shorter than a milennium";
const char Riddle_a57[] PROGMEM = "Century";
const char Riddle_q58[] PROGMEM = "Rolling on floor";
const char Riddle_a58[] PROGMEM = "Laughing";
const char Riddle_q59[] PROGMEM = "A box with no hinges, latch, or lid. Inside a golden treasure is hid. What am I?";
const char Riddle_a59[] PROGMEM = "An egg.";
const char Riddle_q60[] PROGMEM = "Why did the pony cough?";
const char Riddle_a60[] PROGMEM = "He was a little horse.";
const char Riddle_q61[] PROGMEM = "What goes up but never goes down.";
const char Riddle_a61[] PROGMEM = "Your age.";
const char Riddle_q62[] PROGMEM = "What Commits friendly home invasions one night a year";
const char Riddle_a62[] PROGMEM = "Santa claus";
const char Riddle_q63[] PROGMEM = "Treats said to be based on a shepherd's staff";
const char Riddle_a63[] PROGMEM = "Candy cane";
const char Riddle_q64[] PROGMEM = "What has a ring, but no finger?";
const char Riddle_a64[] PROGMEM = "Telephone";
const char Riddle_q65[] PROGMEM = "What has four legs, but can't walk?";
const char Riddle_a65[] PROGMEM = "Table";
const char Riddle_q66[] PROGMEM = "What is higher without the head, than with it?";
const char Riddle_a66[] PROGMEM = "A Pillow";
const char Riddle_q67[] PROGMEM = "What is harder to catch the faster you run?";
const char Riddle_a67[] PROGMEM = "Breath";
const char Riddle_q68[] PROGMEM = "What invention lets you look right through a wall?";
const char Riddle_a68[] PROGMEM = "Window";
const char Riddle_q69[] PROGMEM = "What is that you will break everytime you name it?";
const char Riddle_a69[] PROGMEM = "Silence";
const char Riddle_q70[] PROGMEM = "What is made of wood, but can't be sawed?";
const char Riddle_a70[] PROGMEM = "Sawdust";
const char Riddle_q71[] PROGMEM = "What is a witch's favorite school subject?";
const char Riddle_a71[] PROGMEM = "Spelling";
const char Riddle_q72[] PROGMEM = "What is an aliens favorite sport?";
const char Riddle_a72[] PROGMEM = "Spaceball";
const char Riddle_q73[] PROGMEM = "What is the saddest fruit?";
const char Riddle_a73[] PROGMEM = "Blueberry";
const char Riddle_q74[] PROGMEM = "What is black and white and read all over?";
const char Riddle_a74[] PROGMEM = "Newspaper";
const char Riddle_q75[] PROGMEM = "What is easy to get into, and hard to get out of?";
const char Riddle_a75[] PROGMEM = "Trouble";
const char Riddle_q76[] PROGMEM = "What is there more of the less you see?";
const char Riddle_a76[] PROGMEM = "Darkness";
const char Riddle_q77[] PROGMEM = "If two hours ago, it was as long after one o'clock in the afternoon as it was before one o'clock in the morning, what time would it be now?";
const char Riddle_a77[] PROGMEM = "Nine";
const char Riddle_q78[] PROGMEM = "What is as big as you are and yet does not weigh anything?";
const char Riddle_a78[] PROGMEM = "Shadow";
const char Riddle_q79[] PROGMEM = "What types of words are these: Madam, Civic, Eye, Level?";
const char Riddle_a79[] PROGMEM = "Palindrome. They are the same word spelled backwards.";
const char Riddle_q80[] PROGMEM = "When you have me, you feel like sharing me. But, if you do share me, you don't have me. What am I?";
const char Riddle_a80[] PROGMEM = "Secret";
const char Riddle_q81[] PROGMEM = "The person who makes it has no need for it. The person who purchases it does not use it. The person who does use it does not know he or she is using it. What is it?";
const char Riddle_a81[] PROGMEM = "Coffin";
const char Riddle_q82[] PROGMEM = "It is an insect, and the first part of its name is the name of another insect. What is it?";
const char Riddle_a82[] PROGMEM = "Beetle. Beeeeetle";
const char Riddle_q83[] PROGMEM = "What becomes white when it is dirty?";
const char Riddle_a83[] PROGMEM = "Blackboard";
const char Riddle_q84[] PROGMEM = "What word of five letters has only one left when two letters are removed?";
const char Riddle_a84[] PROGMEM = "Stone. s. t. o. n. ee. Stone.";
const char Riddle_q85[] PROGMEM = "How many 9's are there between 1 and 100?";
const char Riddle_a85[] PROGMEM = "Twenty. Dont forget all of the nineties";
const char Riddle_q86[] PROGMEM = "Which vehicle is spelled the same forwards and backwards?";
const char Riddle_a86[] PROGMEM = "Race car";
const char Riddle_q87[] PROGMEM = "I am lighter than air but a million men cannot lift me up, What am I?";
const char Riddle_a87[] PROGMEM = "Bubble";
const char Riddle_q88[] PROGMEM = "Five men were eating apples, a finished before B, but behind C. D finished before E, but behind B. What was the finishing order?";
const char Riddle_a88[] PROGMEM = "C. A. B. D. E.";
const char Riddle_q89[] PROGMEM = "David's father has three sons: Snap, Crackle, and who is the third?";
const char Riddle_a89[] PROGMEM = "David";
const char Riddle_q90[] PROGMEM = "It is everything to someone, and nothing to everyone else. What is it?";
const char Riddle_a90[] PROGMEM = "Mind";
const char Riddle_q91[] PROGMEM = "What has a mouth but can't chew?";
const char Riddle_a91[] PROGMEM = "River";
const char Riddle_q92[] PROGMEM = "If it is two hours later, then it will take half as much time till it's midnight as it would be if it were an hour later. What time is it?";
const char Riddle_a92[] PROGMEM = "Nine";
const char Riddle_q93[] PROGMEM = "Forward I am heavy, backwards I am not. What am I?";
const char Riddle_a93[] PROGMEM = "Ton";
const char Riddle_q94[] PROGMEM = "What object has keys that open no locks, space but no room, and you can enter but not go in?";
const char Riddle_a94[] PROGMEM = "A Keyboard";

const char * const RiddleQuestions[] PROGMEM = {Riddle_q1,Riddle_q2,Riddle_q3,Riddle_q4,Riddle_q5,Riddle_q6,Riddle_q7,Riddle_q8,Riddle_q9,Riddle_q10,Riddle_q11,Riddle_q12,Riddle_q13,Riddle_q14,Riddle_q15,Riddle_q16,Riddle_q17,Riddle_q18,Riddle_q19,Riddle_q20,Riddle_q21,Riddle_q22,Riddle_q23,Riddle_q24,Riddle_q25,Riddle_q26,Riddle_q27,Riddle_q28,Riddle_q29,Riddle_q30,Riddle_q31,Riddle_q32,Riddle_q33,Riddle_q34,Riddle_q35,Riddle_q36,Riddle_q37,Riddle_q38,Riddle_q39,Riddle_q40,Riddle_q41,Riddle_q42,Riddle_q43,Riddle_q44,Riddle_q45,Riddle_q46,Riddle_q47,Riddle_q48,Riddle_q49,Riddle_q50,Riddle_q51,Riddle_q52,Riddle_q53,Riddle_q54,Riddle_q55,Riddle_q56,Riddle_q57,Riddle_q58,Riddle_q59,Riddle_q60,Riddle_q61,Riddle_q62,Riddle_q63,Riddle_q64,Riddle_q65,Riddle_q66,Riddle_q67,Riddle_q68,Riddle_q69,Riddle_q70,Riddle_q71,Riddle_q72,Riddle_q73,Riddle_q74,Riddle_q75,Riddle_q76,Riddle_q77,Riddle_q78,Riddle_q79,Riddle_q80,Riddle_q81,Riddle_q82,Riddle_q83,Riddle_q84,Riddle_q85,Riddle_q86,Riddle_q87,Riddle_q88,Riddle_q89,Riddle_q90,Riddle_q91,Riddle_q92,Riddle_q93,Riddle_q94};
const char * const RiddleAnswers[] PROGMEM = {Riddle_a1,Riddle_a2,Riddle_a3,Riddle_a4,Riddle_a5,Riddle_a6,Riddle_a7,Riddle_a8,Riddle_a9,Riddle_a10,Riddle_a11,Riddle_a12,Riddle_a13,Riddle_a14,Riddle_a15,Riddle_a16,Riddle_a17,Riddle_a18,Riddle_a19,Riddle_a20,Riddle_a21,Riddle_a22,Riddle_a23,Riddle_a24,Riddle_a25,Riddle_a26,Riddle_a27,Riddle_a28,Riddle_a29,Riddle_a30,Riddle_a31,Riddle_a32,Riddle_a33,Riddle_a34,Riddle_a35,Riddle_a36,Riddle_a37,Riddle_a38,Riddle_a39,Riddle_a40,Riddle_a41,Riddle_a42,Riddle_a43,Riddle_a44,Riddle_a45,Riddle_a46,Riddle_a47,Riddle_a48,Riddle_a49,Riddle_a50,Riddle_a51,Riddle_a52,Riddle_a53,Riddle_a54,Riddle_a55,Riddle_a56,Riddle_a57,Riddle_a58,Riddle_a59,Riddle_a60,Riddle_a61,Riddle_a62,Riddle_a63,Riddle_a64,Riddle_a65,Riddle_a66,Riddle_a67,Riddle_a68,Riddle_a69,Riddle_a70,Riddle_a71,Riddle_a72,Riddle_a73,Riddle_a74,Riddle_a75,Riddle_a76,Riddle_a77,Riddle_a78,Riddle_a79,Riddle_a80,Riddle_a81,Riddle_a82,Riddle_a83,Riddle_a84,Riddle_a85,Riddle_a86,Riddle_a87,Riddle_a88,Riddle_a89,Riddle_a90,Riddle_a91,Riddle_a92,Riddle_a93,Riddle_a94};


String getRiddleQuestion(int i) {
  return (__FlashStringHelper *)pgm_read_word(&RiddleQuestions[i]);
}

String getRiddleAnswer(int i) {
  return (__FlashStringHelper *)pgm_read_word(&RiddleAnswers[i]);
}

void tellRiddle() {
  emic2TtsModule.setWordsPerMinute(110);
  hasAnsweredUsState = true;
  if (hasAnsweredRiddle) {
    hasAnsweredRiddle = false;   
    if (RiddleIndex >= 94) {
      RiddleIndex = 0;
      shuffleRiddles();
    } else {
      RiddleIndex ++;
    }
  }
  
  question = String(getRiddleQuestion(shuffledRiddleOrder[RiddleIndex]));
  answer = String(getRiddleAnswer(shuffledRiddleOrder[RiddleIndex])) + ", " + getLaugh();
  emic2TtsModule.say(String(question));
  emic2TtsModule.setWordsPerMinute(defaultVoiceSpeed);  
}

void shuffleRiddles() {
  scrambleArray(shuffledRiddleOrder, RiddleTotal);
}

/**
 * Returns a random laugh String
 */
String getLaugh() {
  const String laughs[11] = {"ha ha", "hee hee hee", "that was so a good one", "that what pretty clever", "hard dee har har", "whoo, that was a real brain teaser", "golly, my brain hurts after that one", "hoo hoo hee", "uh.. ok", "ha ha ha", "el. oh. el."};
  int randomLaughNumber = random(11);
  String laugh = String(laughs[randomLaughNumber]);
  return laugh;
}
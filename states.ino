// US States and Capitals

// This array will be shuffled into a random order
int shuffledUsStateOrder[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49 };
int usStateTotal = 50;
int usStateIndex = 0;

const char us_q1[] PROGMEM = "Alabama";
const char us_q2[] PROGMEM = "Alaska";
const char us_q3[] PROGMEM = "Arizona";
const char us_q4[] PROGMEM = "Arkansaw";
const char us_q5[] PROGMEM = "California";
const char us_q6[] PROGMEM = "Colorado";
const char us_q7[] PROGMEM = "Connecticut";
const char us_q8[] PROGMEM = "Delaware";
const char us_q9[] PROGMEM = "Florida";
const char us_q10[] PROGMEM = "George a";
const char us_q11[] PROGMEM = "Ha why ee";
const char us_q12[] PROGMEM = "eye da ho";
const char us_q13[] PROGMEM = "Ill i noy";
const char us_q14[] PROGMEM = "Indiana";
const char us_q15[] PROGMEM = "I oh wa";
const char us_q16[] PROGMEM = "Kansas";
const char us_q17[] PROGMEM = "Kentucky";
const char us_q18[] PROGMEM = "Lou ee see anna";
const char us_q19[] PROGMEM = "Main";
const char us_q20[] PROGMEM = "Mary land";
const char us_q21[] PROGMEM = "Mass a chew sets";
const char us_q22[] PROGMEM = "Mish igan";
const char us_q23[] PROGMEM = "Minn e so ta";
const char us_q24[] PROGMEM = "Mississipp ee";
const char us_q25[] PROGMEM = "Missouri";
const char us_q26[] PROGMEM = "Montana";
const char us_q27[] PROGMEM = "Nebraska";
const char us_q28[] PROGMEM = "Nevada";
const char us_q29[] PROGMEM = "New Hamp shire";
const char us_q30[] PROGMEM = "New Jersey";
const char us_q31[] PROGMEM = "New Mexico";
const char us_q32[] PROGMEM = "New York";
const char us_q33[] PROGMEM = "North Carolina";
const char us_q34[] PROGMEM = "North Dakota";
const char us_q35[] PROGMEM = "Ohio";
const char us_q36[] PROGMEM = "Oklahoma";
const char us_q37[] PROGMEM = "Oregon";
const char us_q38[] PROGMEM = "Pennsylvania";
const char us_q39[] PROGMEM = "Rode Island";
const char us_q40[] PROGMEM = "South Carolina";
const char us_q41[] PROGMEM = "South Dakota";
const char us_q42[] PROGMEM = "Tennessee";
const char us_q43[] PROGMEM = "Texas";
const char us_q44[] PROGMEM = "Utah";
const char us_q45[] PROGMEM = "Vermont";
const char us_q46[] PROGMEM = "Virginia";
const char us_q47[] PROGMEM = "Washington";
const char us_q48[] PROGMEM = "West Virginia";
const char us_q49[] PROGMEM = "Wisconsin";
const char us_q50[] PROGMEM = "Wyoming";

const char us_a1[] PROGMEM = "Montgomery";
const char us_a2[] PROGMEM = "Joo No";
const char us_a3[] PROGMEM = "Fee nicks";
const char us_a4[] PROGMEM = "Little Rock";
const char us_a5[] PROGMEM = "Sacramento";
const char us_a6[] PROGMEM = "Denver";
const char us_a7[] PROGMEM = "Hartford";
const char us_a8[] PROGMEM = "Dover";
const char us_a9[] PROGMEM = "Talla hass ee";
const char us_a10[] PROGMEM = "Atlanta";
const char us_a11[] PROGMEM = "Honolulu";
const char us_a12[] PROGMEM = "Boy see";
const char us_a13[] PROGMEM = "Springfield";
const char us_a14[] PROGMEM = "Indianapolis";
const char us_a15[] PROGMEM = "Dee Moin";
const char us_a16[] PROGMEM = "Topeka";
const char us_a17[] PROGMEM = "Frankfort";
const char us_a18[] PROGMEM = "Baton Rooj";
const char us_a19[] PROGMEM = "Augusta";
const char us_a20[] PROGMEM = "Annapolis";
const char us_a21[] PROGMEM = "Boston";
const char us_a22[] PROGMEM = "Lansing";
const char us_a23[] PROGMEM = "Saint Paul";
const char us_a24[] PROGMEM = "Jackson";
const char us_a25[] PROGMEM = "Jefferson City";
const char us_a26[] PROGMEM = "Helena";
const char us_a27[] PROGMEM = "Lincoln";
const char us_a28[] PROGMEM = "Carson City";
const char us_a29[] PROGMEM = "Concord";
const char us_a30[] PROGMEM = "Trenton";
const char us_a31[] PROGMEM = "Santa Fe";
const char us_a32[] PROGMEM = "Albany";
const char us_a33[] PROGMEM = "Raleee";
const char us_a34[] PROGMEM = "Bismarck";
const char us_a35[] PROGMEM = "Columbus";
const char us_a36[] PROGMEM = "Oklahoma City";
const char us_a37[] PROGMEM = "Salem";
const char us_a38[] PROGMEM = "Harrisburg";
const char us_a39[] PROGMEM = "Providence";
const char us_a40[] PROGMEM = "Columbia";
const char us_a41[] PROGMEM = "Pee err";
const char us_a42[] PROGMEM = "Nashville";
const char us_a43[] PROGMEM = "Austin";
const char us_a44[] PROGMEM = "Salt Lake City";
const char us_a45[] PROGMEM = "Montpelier";
const char us_a46[] PROGMEM = "Richmond";
const char us_a47[] PROGMEM = "Olympia";
const char us_a48[] PROGMEM = "Charleston";
const char us_a49[] PROGMEM = "Madison";
const char us_a50[] PROGMEM = "Cheyenne";

const char * const UsQuestions[] PROGMEM = {us_q1,us_q2,us_q3,us_q4,us_q5,us_q6,us_q7,us_q8,us_q9,us_q10,us_q11,us_q12,us_q13,us_q14,us_q15,us_q16,us_q17,us_q18,us_q19,us_q20,us_q21,us_q22,us_q23,us_q24,us_q25,us_q26,us_q27,us_q28,us_q29,us_q30,us_q31,us_q32,us_q33,us_q34,us_q35,us_q36,us_q37,us_q38,us_q39,us_q40,us_q41,us_q42,us_q43,us_q44,us_q45,us_q46,us_q47,us_q48,us_q49,us_q50};

const char * const UsAnswers[] PROGMEM = {us_a1,us_a2,us_a3,us_a4,us_a5,us_a6,us_a7,us_a8,us_a9,us_a10,us_a11,us_a12,us_a13,us_a14,us_a15,us_a16,us_a17,us_a18,us_a19,us_a20,us_a21,us_a22,us_a23,us_a24,us_a25,us_a26,us_a27,us_a28,us_a29,us_a30,us_a31,us_a32,us_a33,us_a34,us_a35,us_a36,us_a37,us_a38,us_a39,us_a40,us_a41,us_a42,us_a43,us_a44,us_a45,us_a46,us_a47,us_a48,us_a49,us_a50};

String getUsState(int i) {
  return (__FlashStringHelper *)pgm_read_word(&UsQuestions[i]);
}

String getUsCapital(int i) {
  return (__FlashStringHelper *)pgm_read_word(&UsAnswers[i]);
}

void tellUsState() {
  emic2TtsModule.setWordsPerMinute(110);
  hasAnsweredRiddle = true;
  if (hasAnsweredUsState) {
    hasAnsweredUsState = false;   
    if (usStateIndex >= 50) {
      usStateIndex = 0;
      shuffleUsStates();
    } else {
      usStateIndex ++;
    }
  }
  
  question = String(getUsState(shuffledUsStateOrder[usStateIndex]));
  answer = "The capital of " + question + " is " + String(getUsCapital(shuffledUsStateOrder[usStateIndex]));
  emic2TtsModule.say("What is the capital of " + String(question));
  emic2TtsModule.setWordsPerMinute(defaultVoiceSpeed);  
}

void shuffleUsStates() {
  scrambleArray(shuffledUsStateOrder, usStateTotal);
}

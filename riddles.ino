const char q1[] PROGMEM = "What has one head, one foot and four legs?";
const char a1[] PROGMEM = "A bed.";

const char q2[] PROGMEM = "How can you spell cold with two letters?";
const char a2[] PROGMEM = "eye. see. Icy. Get it?";

const char q3[] PROGMEM = "If you were in a race and passed the person in second place, what place would you be in?";
const char a3[] PROGMEM = "Second place.";

const char q4[] PROGMEM = "What state is surrounded by the most water?";
const char a4[] PROGMEM = "Ha, why, eee.";

const char q5[] PROGMEM = "How many months have 28 days?";
const char a5[] PROGMEM = "All of them.";

const char q6[] PROGMEM = "How many books can you put into an empty backpack?";
const char a6[] PROGMEM = "One. After that, it's not empty.";

const char q7[] PROGMEM = "Which weighs more, a pound of feathers or a pound of bricks?";
const char a7[] PROGMEM = "Neither, they both weigh a pound.";

const char q8[] PROGMEM = "What has two hands, a round face, always runs, but stays in place?";
const char a8[] PROGMEM = "A clock.";

const char q9[] PROGMEM = "A box with no hinges, latch, or lid. Inside a golden treasure is hid. What am I?";
const char a9[] PROGMEM = "An egg.";

const char q10[] PROGMEM = "Why did the pony cough?";
const char a10[] PROGMEM = "He was a little horse.";

const char q11[] PROGMEM = "Which tire doesn't move when a car turns right?";
const char a11[] PROGMEM = "The spare tire.";

const char q12[] PROGMEM = "What is full of holes but still holds water?";
const char a12[] PROGMEM = "A sponge.";

const char q13[] PROGMEM = "What goes up but never goes down.";
const char a13[] PROGMEM = "Your age.";

const char q14[] PROGMEM = "When is a door not a door?";
const char a14[] PROGMEM = "When it is a jar.";

const char q15[] PROGMEM = "What invention lets you look right through a wall?";
const char a15[] PROGMEM = "A window.";

const char q16[] PROGMEM = "What did the snowman say to the other snowman?";
const char a16[] PROGMEM = "Do you smell carrots.";

const char q17[] PROGMEM = "Why can’t you give Elsa a balloon?";
const char a17[] PROGMEM = "She will let it go.";

const char q18[] PROGMEM = "What room doesn’t have doors?";
const char a18[] PROGMEM = "A mushroom.";

const char q19[] PROGMEM = "Why did the golfer wear two pairs of pants?";
const char a19[] PROGMEM = "In case he got a hole in one.";

const char q20[] PROGMEM = "Why did the little boy throw his clock out the window?";
const char a20[] PROGMEM = "Because he wanted to see time fly.";

const char q21[] PROGMEM = "What has two legs but can’t walk?";
const char a21[] PROGMEM = "A pair of pants.";

const char q22[] PROGMEM = "Why are fish so smart?";
const char a22[] PROGMEM = "Because they live in schools.";

const char q23[] PROGMEM = "What do porcupines say when they kiss?";
const char a23[] PROGMEM = "Ouch.";

const char q24[] PROGMEM = "Why do tigers have stripes?";
const char a24[] PROGMEM = "So they don't get spotted.";

const char * const Questions[] PROGMEM = {q1, q2, q3, q4, q5, q6, q7, q8, q9, q10, q11, q12, q13, q14, q15, q16, q17, q18, q19, q20, q21, q22, q23, q24};
const char * const Answers[] PROGMEM = {a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24};

String getRiddleQuestion(int i) {
  return (__FlashStringHelper *)pgm_read_word(&Questions[i]);
}

String getRiddleAnswer(int i) {
  return (__FlashStringHelper *)pgm_read_word(&Answers[i]);
}



///*
// PROGMEM string demo
// How to store a table of strings in program memory (flash),
// and retrieve them.
//
// Information summarized from:
// http://www.nongnu.org/avr-libc/user-manual/pgmspace.html
//
// Setting up a table (array) of strings in program memory is slightly complicated, but
// here is a good template to follow.
//
// Setting up the strings is a two-step process. First define the strings.
//
//*/
//
//#include <avr/pgmspace.h>
//prog_char string_0[] PROGMEM = "String 0";   // "String 0" etc are strings to store - change to suit.
//prog_char string_1[] PROGMEM = "String 1";
//prog_char string_2[] PROGMEM = "String 2";
//prog_char string_3[] PROGMEM = "String 3";
//prog_char string_4[] PROGMEM = "String 4";
//prog_char string_5[] PROGMEM = "String 5";
//
//
//// Then set up a table to refer to your strings.
//
//PROGMEM const char *string_table[] =     // change "string_table" name to suit
//{
//  string_0,
//  string_1,
//  string_2,
//  string_3,
//  string_4,
//  string_5 };
//
//char buffer[30];    // make sure this is large enough for the largest string it must hold
//
//void getRiddle(int i) {
//  strcpy_P(buffer, (char*)pgm_read_word(&(string_table[i]))); // Necessary casts and dereferencing, just copy.
//  Serial.println( buffer );
//}

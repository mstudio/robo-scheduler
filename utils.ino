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

void scrambleArray(int * array, int size)
{
  int last = 0;
  int temp = array[last];
  for (int i=0; i<size; i++)
  {
    int index = random(size);
    array[last] = array[index];
    last = index;
  }
  array[last] = temp;
}

/** 
 * 
 * JS to generate
 let output = '';
for (var i = 0; i<=49; i++) {
    output += String(i) + ', ';
}
*/
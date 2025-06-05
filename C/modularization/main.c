#include <stdio.h>
#include <math.h>
#include "menu.h"
#include "clean_screen.h"
#include "counter.h"

/*
      'counter' stores how many times every function has been used
    and how many invalid inputs have been submitted:
      The schema is the following:
        [0]   invalid inputs
        [1] + addition
        [2] - substraction
        [3] * product
        [4] / difference
        [5] % modulus
        [6] x roots of quadratic polinomial formula.
        [7] f fibonacci number
        [8] ! factorial
        [9] ? counter of uses
  */

int main()
{
  unsigned int counter[10] =
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  cleanScreen();
  menu(counter);
  displayCounter(counter);
  return 0;
}

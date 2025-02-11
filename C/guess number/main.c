#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <time.h>
#define MIN_RAND_RANGE 1
#define MAX_RAND_RANGE 100

// cleans screen by using ANSI scape codes
void clearScreen() {
  printf("\033[H\033[J");
  return;
}

int main()
{
  clearScreen(); // Ensures a clean screen
  srand(time(NULL)); // Time seed for random number creation

  // Generates a random number between MIN_RAND_RANGE and MAX_RAND_RANGE
  const unsigned short int randNum
    = rand() % (MAX_RAND_RANGE - MIN_RAND_RANGE + 1) + MIN_RAND_RANGE;
  bool isCorrect = false;
  return 0;
}
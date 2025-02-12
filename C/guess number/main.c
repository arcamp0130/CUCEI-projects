#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <time.h>
#define MIN_RAND_RANGE 1
#define MAX_RAND_RANGE 100

// cleans screen by using ANSI scape codes
void clearScreen()
{
  printf("\033[H\033[J");
  return;
}

void printLastHint(int guessTry, unsigned short int randNum)
{
  printf("3. ");
  if (guessTry <= MAX_RAND_RANGE)
  {
    // if guessTry is in range, then print this hint
    if (guessTry >= MIN_RAND_RANGE)
      printf("El numero secreto es %s al numero que ingresaste por ultima vez (%d)\n",
             randNum > guessTry ? "mayor" : "menor",
             guessTry);

    // if guessTry is lower than MIN_RAND_RANGE, then alert
    else
      printf("El numero que ingresaste (%d) es menor que el limite inferior permitido (%d)\n",
             guessTry, MIN_RAND_RANGE);
  }
  // if guessTry is greater than MIN_RAND_RANGE, then alert
  else
    printf("El numero que ingresaste (%d) es mayor que el limite superior permitido (%d)\n",
           guessTry, MAX_RAND_RANGE);
}

int main()
{
  clearScreen();     // Starting with a clean screen
  srand(time(NULL)); // Time seed for random number creation

  // Generates a random number between MIN_RAND_RANGE and MAX_RAND_RANGE
  const unsigned short int randNum = rand() % (MAX_RAND_RANGE - MIN_RAND_RANGE + 1) + MIN_RAND_RANGE;
  bool isCorrect = false;
  int guessTry = 0;
  unsigned int attempts = 0;

  // print 'home page'
  printf("      ================      \n");
  printf("  ========================  \n");
  printf("  ||| Numero aleatorio |||  \n");
  printf("  ========================  \n");
  printf("      ================    \n\n");
  printf("Se obtendra un numero aleatorio en cierto rango,\n");
  printf("numero el cual debes adivinar. El programa acabara\n");
  printf("cuando consigas tu objetivo.\n");
  printf("Tendras algunas pistas para facilitar tu tarea.\n\n");
  printf("Presiona cualquier tecla para comenzar.\n...");
  getch();

  while (!isCorrect)
  {
    clearScreen();
    attempts++;
    printf("Pistas\n");
    printf("---------------\n");
    // Check if randNum is even (true) or odd (false)
    printf("1. Estoy pensando en un numero %s\n",
           randNum & 1 ? "impar" : "par",
           randNum);
    // print range
    printf("2. Mi numero esta entre %d y %d\n", MIN_RAND_RANGE, MAX_RAND_RANGE);
    // print variable hint
    if (attempts > 1)
      printLastHint(guessTry, randNum);

    printf("---------------\n");
    printf("Adivina! Cual es el numero? \n > ");
    scanf("%d", &guessTry);
    isCorrect = guessTry == randNum;
  }

  // Only reachable when user guesses the secret number
  clearScreen();
  printf("    ===============    \n");
  printf("  ===================  \n");
  printf("=======================\n");
  printf("|||   Felicidades   |||\n");
  printf("=======================\n");
  printf("  ===================  \n");
  printf("    ===============    \n\n");
  printf("El numero que adivinaste es %d.\n", randNum);
  printf("Adivinaste despues de %d intento%c\n", attempts, attempts > 1 ? 's' : '!');
  getch();
  return 0;
}
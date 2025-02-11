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

int main()
{
  clearScreen();     // Ensures a clean screen
  srand(time(NULL)); // Time seed for random number creation

  // Generates a random number between MIN_RAND_RANGE and MAX_RAND_RANGE
  const unsigned short int randNum
    = rand() % (MAX_RAND_RANGE - MIN_RAND_RANGE + 1) + MIN_RAND_RANGE;
  bool isCorrect = false;
  int guessTry = 0;
  unsigned int attempts = 0;

  printf("      ================\n");
  printf("  ========================\n");
  printf("  ||| Numero aleatorio |||\n");
  printf("  ========================\n");
  printf("      ================\n\n");
  printf("Se obtendra un numero aleatorio entre 1 y 100\n");
  printf("el cual debes adivinar, el programa acabara\n");
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
    // Check if randNum is odd (true) or even (false)
    printf("Estoy pensando en un numero %s\n",
           randNum & 1 ? "impar" : "par", randNum);
    printf("Mi numero esta entre 1 y 100\n");
    printf("---------------\n");
    printf("Adivina! Cual es el numero? \n > ");
    scanf("%d", &guessTry);
    isCorrect = guessTry == randNum;
  }

  clearScreen();
  printf("Felicidades! El numero que adivinaste es %d.\n", randNum);
  printf("Adivinaste despues de %d intento%c\n", attempts, attempts > 1 ? 's' : '!');
  getch();
  return 0;
}
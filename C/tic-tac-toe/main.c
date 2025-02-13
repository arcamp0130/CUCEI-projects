#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void clearScreen()
{
  printf("\033[H\033[J");
  return;
}

void printBoard(unsigned short int board[3][3]) {
  printf("--------------------\n\n");
  printf("     1 | 2 | 3   x\n\n");
  for (int i = 0; i < 3; i++)
  {
    printf(" %i  ", i + 1);
    for (int j = 0; j < 3; j++)
    {
      if (board[i][j] != 0) {
        printf(" %c", board[i][j] == 1 ? "O" : "X");
      } else {
        printf("  ");
      }
      if (j < 2)
        printf(" |");
    }
    printf("\n");
    if (i < 2)
      printf("    ---|---|---");
    printf("\n");
  }
  printf(" y\n\n");
  printf("--------------------\n");
}

int main()
{
  unsigned short int board[3][3], turn = 0;
  int coordinate[2]; // (x, y). User input
  bool theresWinner = false;
  // Initialize in 0 to support verification
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      board[i][j] = 0;
    }
  }

  do {
    clearScreen();
    printf("Gato!\n");
    printBoard(board);
    theresWinner = true;
  } while (!theresWinner);
  // Print game board
  
}
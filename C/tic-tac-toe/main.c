#include <stdio.h>
#include <stdlib.h>

void clearScreen()
{
  printf("\033[H\033[J");
  return;
}

int main()
{
  clearScreen();

  int board[3][3];

  // Initialize in -1 to support verification
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      board[i][j] = -1;
    }
  }

  // Print game board

  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      printf("%i", board[i][j]);
      if (j < 2)
        printf(" |");
    }
    printf("\n");
    if (i < 2)
      printf("---|---|---");
    printf("\n");
  }
}
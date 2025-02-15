#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void clearScreen()
{
  printf("\033[H\033[J");
  return;
}

void printBoard(unsigned short int board[3][3])
{
  printf("--------------------\n\n");
  printf("     1 | 2 | 3   x\n\n");
  for (int i = 0; i < 3; i++)
  {
    printf(" %i  ", i + 1);
    for (int j = 0; j < 3; j++)
    {
      if (board[i][j] != 0)
      {
        printf(" %c", board[i][j] == 1 ? 'X' : 'O');
      }
      else
      {
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
  unsigned short int board[3][3], winner = 0;
  int coord[2];      // (x, y). User input;
  bool turn = false; // false for 1st, true for 2st
  // Initialize in 0 to support verification
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      board[i][j] = 0;
    }
  }

  do
  {
    clearScreen();
    printf("Gato!\n");
    printBoard(board);
    printf("Jugador %i\n", !turn ? 1 : 2);
    printf("Escriba coordenadas para su juego:\n");
    printf(" x > ");
    scanf("%d", &coord[0]);
    printf(" y > ");
    scanf("%d", &coord[1]);

    // Check if valid coords
    if (coord[0] >= 1 && coord[1] >= 1)
    {
      if (coord[0] <= 3 && coord[1] <= 3)
      {
        coord[0] -= 1; // x
        coord[1] -= 1; // y
        if (board[coord[1]][coord[0]] == 0)
        {
          board[coord[1]][coord[0]] = !turn ? 1 : 2;
          turn = !turn;
        }
        else
          printf("Espacio ocupado");
      }
      else
        printf("Coordenadas fuera de rango");
    }
    else
    {
      printf("Coordenadas fuera de rango");
    }
    // winner = 1;
  } while (winner == 0);
  // Print game board
}
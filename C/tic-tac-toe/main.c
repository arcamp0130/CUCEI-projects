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

void printWarn(unsigned short int inputStatus)
{
  if (inputStatus != 0)
  {
    printf("----------\n");
    printf("## Error ##\n");
    if (inputStatus == 1)
      printf("Espacio ocupado");
    else if (inputStatus == 2)
      printf("Coordenadas fuera de rango");
    else
      printf("Entrada inesperada");
  }

  printf("\n----------\n");
  return;
}

unsigned short int verifyCoordinates(
    int coords[2],
    unsigned short int board[3][3])
{
  if (coords[0] >= 1 && coords[1] >= 1)
  {
    if (coords[0] <= 3 && coords[1] <= 3)
    {                 // When valid coordinates
      coords[0] -= 1; // x
      coords[1] -= 1; // y
      if (board[coords[1]][coords[0]] == 0)
        // if not busy space
        return 0;
      else // if busy space
        return 1;
    }
    else // if invalid coordinates
      return 2;
  }
  else // if invalid coordinates
    return 2;
}

int main()
{
  unsigned short int
      board[3][3],      // Game board
      games = 0,        // Games played
      inputStatus = 0;  // Game status
  int coords[2];        // (x, y). User input
  bool turn = false,    // false for 1st, true for 2st
       winner = false;  // if there's winner
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
    printWarn(inputStatus);
    printf("Escriba coordenadas para su juego:\n");
    printf(" x > ");
    scanf("%d", &coords[0]);
    printf(" y > ");
    scanf("%d", &coords[1]);

    // Check if valid coords
    inputStatus = verifyCoordinates(coords, board);
    if (inputStatus == 0)
    {
      board[coords[1]][coords[0]] = !turn ? 1 : 2;
      turn = !turn;
      games++;
    }

  } while (!winner && games < 9);
  clearScreen();
  printBoard(board);
  if (!winner)
  {
    printf("Empate!\n");
  }
  else
  {
    printf("Gano el jugador %i\n", !turn ? 1 : 2);
  }
  return 0;
}
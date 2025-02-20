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
      printf("Coordenada x fuera de rango");
    else if (inputStatus == 3)
      printf("Coordenada y fuera de rango");
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
  if (1 <= coords[1] && coords[1] <= 3)
  { // coordinates in y
    if (1 <= coords[0] && coords[0] <= 3)
    { // coordinates in x
      // When valid coordinates
      coords[0] -= 1; // x
      coords[1] -= 1; // y
      if (board[coords[1]][coords[0]] == 0)
        return 0; // if available space
      else
        return 1; // if busy space
    }
    else // if invalid x coordinate
      return 2;
  }
  else // if invalid y coordinate
    return 3;
}

// Only reachable when valid coordinates.
unsigned short int checkForWinner(
    unsigned short int board[3][3],
    int turn)
{

  // Initialize colBreak with false
  bool colBreak[3] = {false, false, false};

  for (int y = 0; y < 3; y++)
  { // y axis
    int counter = 0;
    for (int x = 0; x < 3; x++)
    { // x axis
      if (board[y][x] == turn)
        counter++;
      else
        colBreak[x] = true;
    }
    if (counter == 3)
      return true;
  }

  // Check if theres complete column with previous 'for' sentences
  for (int i = 0; i < 3; i++)
    if (!colBreak[i])
      return true;

  return false;
}

int main()
{
  unsigned short int
      board[3][3],     // Game board
      games = 0,       // Games played
      inputStatus = 0, // Game input status
      winner = 0;      // if there's winner
  int coords[2];       // (x, y). User input
  bool turn = false;   // false for 1st, true for 2st

  // Initialize game board in 0 to support verification
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      board[i][j] = 0;

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
      board[coords[1]][coords[0]] = turn ? 2 : 1;
      turn = !turn;
      games++;
    }

    if (games >= 5)
      // We deny 'turn' 'cause at this point it's opposite
      winner = checkForWinner(board, !turn ? 2 : 1);

  } while (!winner && games < 9);

  clearScreen();
  printBoard(board);

  if (!winner)
    printf("Empate!\n");
  else
    // Here, 'turn' value reaches opposite turn:
    // if P1 wins, we get that P2 wins (???).
    // So we deny value to write correct turn
    // Finally, this' writting the correct winner
    printf("Gana el jugador %i\n", !turn ? 2 : 1);

  return 0;
}
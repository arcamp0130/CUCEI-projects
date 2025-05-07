#include <stdio.h>

void cleanScreen()
{
  printf("\033[H\033[J");
  return;
}

void printPattern(int n)
{
  for (int i = 0; i <= n - 1; i++)
  {
    //Only to keep symmetry when n = 10
    if (i < 9) 
      printf(" ");
    
    // Print spaces before first term of row
    for (int j = 1; j < n - i; j++)
      printf("  ");
    
    // print ascendant terms (n to 1)
    for (int j = 0; j <= i; j++) 
      printf("%i ", i - j + 1);
    
    // print ascendant terms from 2nd row (2 to n)
    for (int j = 1; j <= i; j++) 
      printf("%i ", j + 1);
    
    printf("\n");
  }
  printf("------\n");
  return;
}

int main()
{
  cleanScreen();
  int rows = 0;
  printf("Imprimir patron numerico\n");
  printf("----------------\n");
  printf("Escriba un numero entre 3 y 10 para imprimir su patron numerico\n > ");
  scanf("%d", &rows);
  printf("----------------\n\n");
  
  if (3 <= rows && rows <= 10)
    printPattern(rows);
  else
    printf("El numero ingresado no es valido\n");

  printf("Fin del patron\n");
  printf("----------------\n");

  return 0;
}
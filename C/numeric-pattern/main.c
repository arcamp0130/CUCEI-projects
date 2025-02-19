#include <stdio.h>
#include <stdlib.h>

void cleanScreen() {
  printf("\033[H\033[J");
  return;
}

// Task: print the following pattern with iterative cycles
// This example is for n = 4
//       1
//     2 1 2
//   3 2 1 2 3
// 4 3 2 1 2 3 4
//      ...
// With a range provided for user, 
// 3 <= n <= 10, with out-of-range detection
//
// - At least 2 nested cycles
// - Verify n to be in-range
// - Use proper spacing when printing pyramid
// - DON'T USE ARRAYS

void printPattern(int n) {
  
  return;
}

int main() {
  cleanScreen();
  int size = 0;
  printf("Imprimir patron numerico\n");
  printf("----------------\n");
  printf("Escriba un numero entre 3 y 10 para imprimir su patron numerico\n > ");
  scanf("%d", &size);
  if (3 <= size && size <= 10) 
    printPattern(size);
  else 
    printf("El numero ingresado no es valido\n");

  system("PAUSE");
  return 0;
}
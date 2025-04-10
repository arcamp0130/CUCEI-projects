#include <stdio.h>
void displayCounter(unsigned int *counter)
{
  printf("Has utilizado cada funcion estas veces:\n");
  printf(" +  Suma: %i\n", counter[1]);
  printf(" -  Resta: %i\n", counter[2]);
  printf(" *  Multiplicacion: %i\n", counter[3]);
  printf(" /  Division: %i\n", counter[4]);
  printf(" %%  Modulo: %i\n", counter[5]);
  printf(" x  Raices de polinomio cuadratico: %i\n", counter[6]);
  printf(" f  Fibonacci: %i\n", counter[7]);
  printf(" !  Factorial: %i\n", counter[8]);
  printf("----------\n");
  printf(" ?  Conteo de consultas: %i\n", counter[9]);
  printf(" %c  Opciones invalidas: %i\n\n", 178, counter[0]);
  return;
  printf("\n");
}

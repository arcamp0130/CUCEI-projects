#include <stdbool.h>
#include <stdio.h>
#include "clean_screen.h"
#include "dialogs.h"
#include "counter.h"

void menu(unsigned int *counter)
{
  cleanScreen();
  char opt = '\0';
  bool exit = false;
  do
  {
    printf("Calculadora multifuncional:\nSelecciona una operacion\n");
    printf("--------------------\n");
    printf(" +  Suma\n -  Resta\n *  Multiplicacion\n /  Division\n %%  Modulo\n x  Raices de polinomio cuadratico\n f  Suma de Fibonacci\n !  Factorial\n -----\n ?  Contador de consultas\n s  Salir\n\n > ");
    scanf(" %c", &opt);
    cleanScreen();
    switch (opt)
    {
    case '+':
      *(counter + 1) += 1;
      additionDialog();
      break;
    case '-':
      *(counter + 2) += 1;
      substractionDialog();
      break;
    case '*':
      *(counter + 3) += 1;
      productDialog();
      break;
    case '/':
      *(counter + 4) += 1;
      differenceDialog();
      break;
    case '%':
      *(counter + 5) += 1;
      modulusMathDialog();
      break;
    case 'x':
      *(counter + 6) += 1;
      quadraticFormulaDialog();
      break;
    case 'f':
      *(counter + 7) += 1;
      fibonacciDialog();
      break;
    case '!':
      *(counter + 8) += 1;
      factorialDialog();
      break;
    case '?':
      *(counter + 9) += 1;
      displayCounter(counter);
      break;
    case 's':
      cleanScreen();
      exit = true;
      break;
    default:
      *(counter) += 1;
      printf("Opcion invalida, intenta de nuevo\n-----\n");
      break;
    }

  } while (!exit);
}
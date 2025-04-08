#include <stdbool.h>
#include <stdio.h>
#include "clean_screen.h"
#include "dialogs.h"

void menu()
{
  cleanScreen();
  char opt = '\0';
  bool exit = false;
  do
  {
    printf("Calculadora multifuncional:\nSelecciona una operacion\n");
    printf("--------------------\n");
    printf(" +  Suma\n -  Resta\n *  Multiplicacion\n /  Division\n %%  Modulo\n x  Raices de polinomio cuadratico\n f  Suma de Fibonacci\n !  Factorial\n -----\n s  Salir\n\n > ");
    scanf(" %c", &opt);
    cleanScreen();
    switch (opt)
    {
    case '+':
      additionDialog();
      break;
    case '-':
      substractionDialog();
      break;
    case '*':
      productDialog();
      break;
    case '/':
      differenceDialog();
      break;
    case '%':
      moduleMathDialog();
      break;
    case 'x':
      quadraticFormulaDialog();
      break;
    case 'f':
      fibonacciDialog();
      break;
    case '!':
      factorialDialog();
      break;
    case 's':
      exit = true;
      break;
    default:
    printf("Opcion invalida, intenta de nuevo\n-----\n");
      break;
    }

  } while (!exit);
}
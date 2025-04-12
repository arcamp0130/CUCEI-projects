#include <stdio.h>
#include "clean_screen.h"
#include "math/addition.h"
#include "math/difference.h"
#include "math/factorial.h"
#include "math/fibonacci.h"
#include "math/modulus.h"
#include "math/product.h"
#include "math/quadratic_formula.h"
#include "math/substraction.h"

void additionDialog()
{
  printf("Suma\n-----\n");
  float a, b, result;
  printf("Ingresa el primer valor\n > ");
  scanf("%f", &a);
  printf("Ingresa el segundo valor\n > ");
  scanf("%f", &b);
  result = addition(a, b);

  cleanScreen();
  printf("Resultado de la suma\n %f\n-----\n", result);
  return;
}

void differenceDialog()
{
  printf("Division\n-----\n");
  float a, b, result;
  printf("Ingresa el primer valor\n > ");
  scanf(" %f", &a);
  printf("Ingresa el segundo valor\n");
  do
  {
    printf("Debe ser disntinto de 0\n > ");
    scanf(" %f", &b);
  } while (b == 0);
  result = difference(a, b);

  cleanScreen();
  printf("Resultado de la division\n %f\n-----\n", result);
  return;
}

void modulusMathDialog()
{
  printf("Modulo\n-----\n");
  float a, b;
  int result;
  printf("Ingresa el primer valor\n");
  do
  {
    printf("Debe ser entero\n > ");
    scanf(" %f", &a);
  } while ((int)a != a);

  printf("Ingresa el segundo valor\n");
  do
  {
    printf("Debe ser entero\n > ");
    scanf(" %f", &b);
  } while ((int)b != b);

  result = modulusMath((int)a, (int)b);

  cleanScreen();
  printf("Resultado del modulo\n %i\n-----\n", result);
  return;
}

void productDialog()
{
  printf("Multiplicacion\n-----\n");
  float a, b, result;
  printf("Ingresa el primer valor\n > ");
  scanf("%f", &a);
  printf("Ingresa el segundo valor\n > ");
  scanf("%f", &b);
  result = product(a, b);

  cleanScreen();
  printf("Resultado de la multiplicacion\n %f\n-----\n", result);
  return;
  return;
}

void quadraticFormulaDialog()
{
  float a = 0, b = 0, c = 0, delta = 0, result[2] = {0, 0};
  printf("Sea la ecuacion ax^2 + bx + c = 0.\nIngrese los valores de a, b y c para calcular las raices de la ecuacion:\n-----\n");
  printf(" a > ");
  scanf(" %f", &a);
  printf(" b > ");
  scanf(" %f", &b);
  printf(" c > ");
  scanf(" %f", &c);
  delta = (b * b) - 4 * (a * c);
  cleanScreen();
  printf("Raices del polinomio cuadratico\n");
  if (delta < 0)
    printf(" [!] complejos, incalculables por ahora\n");
  else
  {
    quadraticFormula(a, b, c, result);
    if (result[0] == result[1])
      printf("x = %0.2f", result[0]);
    else
      printf( " x_1 = %0.2f\n x_2 = %0.2f", result[0], result[1]);
  }
  printf("\n-----\n");
  return;
}

void substractionDialog()
{
  printf("Suma\n-----\n");
  float a, b, result;
  printf("Ingresa el primer valor\n > ");
  scanf("%f", &a);
  printf("Ingresa el segundo valor\n > ");
  scanf("%f", &b);
  result = substraction(a, b);

  cleanScreen();
  printf("Resultado de la resta\n %f\n-----\n", result);
  return;
  return;
}

void fibonacciDialog()
{
  float n = 0;
  int result = 0;
  printf("Numero de fibonacci\n-----\n");
  printf("Introduza un numero n para calcular su suma de fibonacci\n");
  do
  {
    printf("Debe ser entero\n > ");
    scanf(" %f", &n);
  } while ((int)n != n);

  result = fibonacci((int)n);
  cleanScreen();
  printf("El resultado de fibonacci es\n%i\n-----\n", result);
  
  return;
}

void factorialDialog()
{
  return;
}

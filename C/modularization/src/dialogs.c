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

  return;
}

void factorialDialog()
{
  return;
}

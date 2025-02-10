#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void performAddition()
{ // Suma
  printf("Suma de dos numeros\n----------\n\n");
  float x = 0, y = 0;

  printf("Ingese el primer numero\n > ");
  scanf("%f", &x);

  printf("Ingese el segundo numero\n > ");
  scanf("%f", &y);

  printf("\n-----\nResultado: %f\n\n...", x + y);
  getch(); // Espera cualquier tecla para continuar
  return;
}

void performSubstraction()
{ // Resta
  printf("Diferencia de dos numeros\n----------\n\n");
  float x = 0, y = 0;

  printf("Ingese el primer numero\n > ");
  scanf("%f", &x);

  printf("Ingese el segundo numero\n > ");
  scanf("%f", &y);

  printf("\n-----\nResultado: %f\n\n...", x - y);
  getch(); // Espera cualquier tecla para continuar
  return;
}

void performMultiplication()
{ // Multiplicación
  printf("Multiplicacion de dos numeros\n----------\n\n");

  float a = 0, b = 0;

  printf("Ingese el primer numero\n > ");
  scanf("%f", &a);

  printf("Ingese el segundo numero\n > ");
  scanf("%f", &b);

  printf("\n-----\nResultado: %f\n\n...", a * b);
  getch(); // Espera cualquier tecla para continuar
  return;
}

void performDivision()
{ // División
  printf("Division de dos numeros\n----------\n\n");

  // Dividendo, divisor
  float a = 0, b = 0;

  printf("Ingese dividendo\n > ");
  scanf("%f", &a);

  printf("Ingese divisor\n > ");
  scanf("%f", &b);

  // Si trata de dividir entre 0
  if (b == 0)
  {
    printf("No es posible dividir entre 0!\n\n");
    getch(); // Espera cualquier tecla para continuar
    return;
  }

  printf("\n-----\nResultado: %f\n\n...", a / b);
  getch(); // Espera cualquier tecla para continuar
  return;
}

void performPow()
{ // Potencia
  printf("Potencia de un numero\n----------\n\n");

  // base, potencia
  float a, n;
  double res = 0;

  printf("Ingese base\n > ");
  scanf("%f", &a);

  printf("Ingese potencia\n > ");
  scanf("%f", &n);

  // Detecta si se trata de calcular inverso
  if (n < 0)
  {
    printf("Potencia negativa no valida\n\n...");
    getch();
    return;
  }

  /// Detecta si la potencia ingresada es decimal
  /// si el cambio a int hace que el valor de 'n' cambie
  if (n != (int)n)
  {
    printf("No es posible elevar a potencia decimal\n\n...");
    getch();
    return;
  }

  if (n == 0) // Cualquier número de potencia 0 es 1
    res = 1;
  else
  {
    // Potencia igual o mayor que 1 en los naturales 
    // Solo entra al while cuando la potencia sea mayor que 1
    res = a;
    int i = 1;
    while (i < n)
    {
      res *= a;
      i++;
    }
  }

  printf("Resultado: %f", res);
  getch();
  return;
}

int main()
{
  char c = '\0';
  do
  {
    system("CLS");
    printf("Calculadora\n----------\n");
    printf("Elige una operacion\n-------\n");
    printf(" [1] Suma\n");
    printf(" [2] Resta\n");
    printf(" [3] Multiplicacion\n");
    printf(" [4] Division\n");
    printf(" [5] Potencia\n");
    printf(" ------\n");
    printf(" [6] Salir\n");
    c = getch();

    system("CLS");
    switch (c)
    {
    case '1': // Suma
      performAddition();
      break;
    case '2': // Resta
      performSubstraction();
      break;
    case '3': // Multiplicación
      performMultiplication();
      break;
    case '4': // División
      performDivision();
      break;
    case '5': // Número a una potencia
      performPow();
      break;
    case '6': // Finalizar ejecución
      printf("Finalizando programa\n\n...");
      getch();
      break;
    default:
      break;
    }

  } while (c != '6');

  return 0;
}

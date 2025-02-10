#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void DuplicateNumber()
{
  int val = 0;
  printf("Duplicar numero\n");
  printf("--------\n");
  printf("Ingresa un numero\n > ");
  scanf("%d", &val);

  printf("--------\n");
  printf("Resultado: %d\n\n...", val << 1);
  getch();
  return;
}

void SquareRootNumber()
{
  long int val = 0;
  printf("Raiz de un numero\n");
  printf("--------\n");
  printf("Ingresa un numero\n > ");
  scanf("%d", &val);
  printf("--------\n");

  if (val < 0)
  {
    printf("No es posible calcular para negativos.\n\n...");
    getch();
    return;
  }

  float x = val;
  float precision = 0.00001;

  while (((x * x) - val) > precision ||
         val - (x * x) > precision)
  {
    x = (x + (val / x)) / 2;
  }

  printf("Resultado: %0.5f\n\n...", x);
  getch();
  return;
}

void OddOrEven()
{
  printf("Ingresa un numero\n > ");

  int val = 0;
  scanf("%d", &val);
  printf("--------\n");

  if (val % 2 != 1)
    printf("Es par");
  else
    printf("Es impar");

  printf("\n\n...");
  getch();
}

void SquareNumber()
{
  int val = 0;
  printf("Cuadrado de un numero\n");
  printf("--------\n");
  printf("Ingresa un numero\n > ");
  scanf("%d", &val);
  printf("--------\n");

  // int res = val*val;
  int res = 0,
      temp = val,
      count = 0; 

  while(temp != 0) {
    if (temp & 1) 
      res += (val << count);
    count++;
    temp >>= 1;
  }

  printf("Resultado: %d\n\n...", res);
  getch();
  return;
}

int main()
{
  char c = '\0';

  do
  {
    system("CLS");
    printf("Elige una opcion:\n");
    printf("  [1] Calcular el doble de un numero.\n");
    printf("  [2] Calcular raiz cuadrada.\n");
    printf("  [3] Verificar numero par o impar.\n");
    printf("  [4] Calcular cuadrado de un numero.\n");
    printf("  ---------------\n");
    printf("  [5] Salir.\n");
    printf("> ");
    c = getch();
    system("CLS");

    switch (c)
    {
    case '1':
      DuplicateNumber();
      break;
    case '2':
      SquareRootNumber();
      break;
    case '3':
      OddOrEven();
      break;
    case '4':
      SquareNumber();
      break;
    case '5':
      printf("Saliendo\n\n...");
      getch();
      break;
    default: // Do nothing
      break;
    }

  } while (c != '5');

  return 0;
}

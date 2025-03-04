#include <stdio.h>
#include <stdbool.h>
#define prod 10

int main()
{
  bool exit = false;
  char option;
  int ID[prod];
  float precios[prod];
  int existencia[prod][3];
  do
  {
    printf("Ingresa la opcion deseada: \n a. Cargar datos de productos \n b. Mostrar inventario completo \n c. Calcular valor total del inventario \n d. Encontrar el producto con mayor y menor existencia total \n e. Actualizar existencias de un producto específico en una sucursal \n");
    scanf("%c", &option);
    switch (option)
    {
    case 'a':
      break;
    case 'b':
      break;
    case 'c':
      break;
    case 'd':
      break;
    case 'e':
      break;
    case 'f':
      exit = true;
      break;
    default:
      printf("Opcion no valida\n");
      break;
    }
  } while (!exit);

  return 0;
}
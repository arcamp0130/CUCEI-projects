#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define ITEMS 10
#define STORES 3

// Clear console screen. Only works in the newest platforms.
void cleanScreen()
{
  printf("\033[H\033[J");
  return;
}

// Print full inventory, with IDs, prices and stock per store
void printInventory(int *IDs, float *prices)
{
  for (int i = 0; i < ITEMS; i++)
  {
    printf("ID %i:\n", IDs[i]);
    printf("  Precio: $%0.2f\n", prices[i]);
    printf("-----\n\n");
    // TODO: print price and stock per store
  }

  return;
}

// Check if sumbitted ID already exists
bool idExists(int *IDs, int input)
{
  for (int i = 0; i < ITEMS; i++)
    if (IDs[i] == input)
      return true;

  return false;
}

// Verify if input is a positive integer;
// belongs to Natural numbers.
bool isPositiveInteger(float input)
{
  return (int)input == input && input > 0;
}

// Set product data with ID, price and stock per store
bool setData(int *IDs, float *prices)
{
  // Create product
  for (int i = 0; i < ITEMS; i++)
  {
    float input = 0;
    bool err = false;
    // Set ID
    do
    {
      cleanScreen();
      if (err)
        printf("ID invalido, intente de nuevo\n-----\n");

      printf("Ingresa el ID del producto %i\n > ", i + 1);
      scanf(" %f", &input);
      err = idExists(IDs, input) || !isPositiveInteger(input);
    } while (err);
    IDs[i] = (int)input;

    // Set price
    do
    {
      cleanScreen();
      if (err)
        printf("Precio invalido, intente de nuevo\n----\n");

      printf("Ingresa el precio del producto %i\n > $", i + 1);
      scanf(" %f", &input);
      err = input <= 0;
    } while (err);
    prices[i] = input;


    // Set stock
    // do
    // {
    //   clearScreen();
    //   /* TODO */
    // } while (err);
  }

  return true;
}

int main()
{
  cleanScreen();
  bool exit = false,
       isDataSetted = false;
  unsigned int ID[ITEMS], products = 0;
  float prices[ITEMS];
  unsigned int stock[ITEMS][STORES];
  do
  {
    char c;
    printf("Ingresa la opcion deseada:\n [a]. Cargar datos de productos\n [b]. Mostrar inventario completo\n [c]. Calcular valor total del inventario\n [d]. Encontrar el producto con mayor y menor existencia total\n [e]. Actualizar existencias de un producto especifico en una sucursal\n [f]. Salir\n  > ");
    scanf(" %c", &c);
    cleanScreen();
    switch (c)
    {
    case 'a':
      isDataSetted = setData(ID, prices);
      break;
    case 'b':
      if (isDataSetted)
        printInventory(ID, prices);
      else
        printf("No hay datos por mostrar\n");
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
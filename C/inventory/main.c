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

// Initialize every data set with 0's
void initData(int *ID, float *prices, unsigned int stock[][STORES])
{
  for (int i = 0; i < ITEMS; i++)
  {
    ID[i] = 0;
    prices[i] = 0;
    for (int j = 0; j < STORES; j++)
      stock[i][j] = 0;
  }
  return;
}

// Prints full inventory, with IDs, prices and stock per store
void printInventory(unsigned int *IDs, float *prices, unsigned int stock[][STORES])
{
  cleanScreen();
  for (int i = 0; i < ITEMS; i++)
  {
    int totalExistences = 0;
    printf("ID %i:\n", IDs[i]);
    printf("  Precio: $%0.2f\n", prices[i]);
    printf("  Existencias:\n");
    for (int j = 0; j < STORES; j++)
    {
      printf("    Tienda %i: %i\n", j + 1, stock[i][j]);
      totalExistences += stock[i][j];
    }
    printf("    ----\n");
    printf("    Total: %i\n", totalExistences);
    printf("-----\n\n");
    // TODO: print price and stock per store
  }

  return;
}

// Prints value of the inventory across and for every store
void printInventoryValue(float *prices, unsigned int stock[][STORES])
{
  cleanScreen();
  double totalValue = 0;
  // Search in store
  for (int i = 0; i < STORES; i++)
  {
    double storeValue = 0;
    // Search item in store
    for (int j = 0; j < ITEMS; j++)
      // Check for stock of j product in i store
      // and multiplies it for the price of the product j
      storeValue += stock[j][i] * prices[j];

    printf("Valor calculado para tienda %i:\n  $%0.2lf", i + 1, storeValue);
    printf("\n----------\n");
    totalValue += storeValue;
  }

  printf("\n----------\n");
  printf("Valor calculado de la suma de todas las tiendas:\n  $%0.2lf", totalValue);
  return;
}

// Searches for products with less and more stock across all stores
// and prints product data and location (ID, stock and store).
void printMinMaxProductStock(int *ID, unsigned int stock[][STORES])
{
  cleanScreen();
  // min-max item is organized as [ID, stock, store]
  // Initialize with first item data and store 1.
  int
      minItem[3] = {ID[0], stock[0][0], 0},
      maxItem[3] = {ID[0], stock[0][0], 0};

  // Search items
  for (int i = 0; i < ITEMS; i++)
  {
    // Search items' store
    for (int j = 0; j < STORES; j++)
    {
      // When finding a lower stock than last found
      if (stock[i][j] < minItem[1])
      {
        minItem[0] = ID[i];
        minItem[1] = stock[i][j];
        minItem[2] = j;
      }

      // When finding a higher stock than last found
      if (stock[i][j] > maxItem[1])
      {
        maxItem[0] = ID[i];
        maxItem[1] = stock[i][j];
        maxItem[2] = j;
      }
    }
  }

  // Printing results
  printf("Producto con menor existencias:\n");
  printf(" ID: %i\n existencias: %i\n tienda %i\n-----\n", minItem[0], minItem[1], minItem[2] + 1);

  printf("Producto con mayor existencias:\n");
  printf(" ID: %i\n existencias: %i\n tienda %i\n", maxItem[0], maxItem[1], maxItem[2] + 1);

  return;
}

// Check if sumbitted ID already exists
bool idExists(unsigned int *IDs, int input)
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
  // Evaluating if input has decimal part and
  // being higer than 0
  return (int)input == input && input > 0;
}

// Set product data with ID, price and stock per store
bool setData(unsigned int *IDs, float *prices, unsigned int stock[][STORES])
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

    // Set stock store by store
    for (int j = 0; j < STORES; j++)
    {
      do
      {
        cleanScreen();
        if (err)
          printf("Numero de existencias invalido, intente de nuevo\n-----\n");

        printf("Ingrese existencias para el producto %i en la tienda %i:\n > ", i + 1, j + 1);
        scanf(" %f", &input);
        // With capacity to have no stock of the relative product
        err = !isPositiveInteger(input) && input != 0;
      } while (err);
      stock[i][j] = input;
    }
  }
  cleanScreen();
  printf("Datos cargados correctamente\n");

  return true;
}

int main()
{
  bool exit = false,
       isDataSetted = false;
  unsigned int ID[ITEMS];
  float prices[ITEMS];
  unsigned int stock[ITEMS][STORES];
  cleanScreen();
  do
  {
    char c = '\0';
    printf("\n----------\n");
    printf("Ingresa la opcion deseada:\n [a]. Cargar datos de productos\n [b]. Mostrar inventario completo\n [c]. Calcular valor total del inventario\n [d]. Encontrar el producto con mayor y menor existencia total\n [e]. Actualizar existencias de un producto especifico en una sucursal\n [f]. Salir\n  > ");
    scanf(" %c", &c);
    fflush(stdin);
    cleanScreen();
    switch (c)
    {
    case 'a':
      isDataSetted = false;
      initData(ID, prices, stock);
      isDataSetted = setData(ID, prices, stock);
      break;
    case 'b':
      if (isDataSetted)
        printInventory(ID, prices, stock);
      else
        printf("No hay datos por mostrar\n");
      break;
    case 'c':
      if (isDataSetted)
        printInventoryValue(prices, stock);
      else
        printf("No hay datos por mostrar\n");
      break;
    case 'd':
      if (isDataSetted)
        printMinMaxProductStock(ID, stock);
      else
        printf("No hay datos por mostrar\n");
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

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#define NAME_MAX_LEN 10
#define PROD_MAX_LEN 10

int main()
{
    const float IVA = 0.16;

    char productName[PROD_MAX_LEN][NAME_MAX_LEN];
    unsigned int amount[PROD_MAX_LEN];
    float price[PROD_MAX_LEN];

    printf("Inventario de productos.\n-----\n\n...");
    getch();

    for(int i = 0; i < PROD_MAX_LEN; i++) {
        system("CLS");
        char buffer[NAME_MAX_LEN];
        printf("Producto N. %d\n------\n", i + 1);

        //Nombre del producto
        printf("Ingrese nombre del prodocto\n > ");
        scanf("%s", &buffer);
        fflush(stdin);
        strcpy(productName[i], buffer);

        //Precio
        printf("Ingrese precio del producto antes de IVA\n > ");
        scanf("%f", &price[i]);
        price[i] += price[i] * IVA;
        fflush(stdin);

        //Cantidad
        printf("Ingrese cantidad en existencia\n > ");
        scanf("%i", &amount[i]);
        fflush(stdin);
    }

    system("CLS");
    printf("Inventario final\n----------\n");
    for (int i = 0; i < PROD_MAX_LEN; i++) {
        printf("Producto %d\n", i + 1);
        printf("\tNombre: %s\n", productName[i]);
        printf("\tPrecio (IVA %0.2f%%): $%0.2f\n", IVA, price[i]);
        printf("\tElementos en existencia: %d\n", amount[i]);
        printf("-----\n");
    }
    printf("\nFin del inventario");
    getch();

    return 0;
}
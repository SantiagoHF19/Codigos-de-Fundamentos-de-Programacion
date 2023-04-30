#include <conio.h>
#include <stdio.h>

int main ()
{
    int numero;

    printf("\n Introduzca un numero entero: ");
    scanf("%d", &numero);

    if (numero % 2 == 0)
        printf("\n Es par");
    else
        printf("\n Es impar");

    getch(); /* Pausa */

    return 0;
}

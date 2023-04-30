#include <conio.h>
#include <stdio.h>

#define euro 1.66386

int main ()
{
    int dolares;
    float euros;

    printf("\n Escriba la cantidad en dolares: ");
    scanf("%d", &dolares);

    euros = dolares / euro;

    printf("\n Equivalen a: %.2f euros", euros);

    getch(); /* Pausa */

    return 0;

}

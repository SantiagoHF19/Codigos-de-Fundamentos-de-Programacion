#include <stdio.h>
#define pi 3.1416
#define escribe printf

main() /* Calcula el perimetro */
{
    int r;
    escribe("Introduce el radio: ");
    scanf("%d", &r);
    escribe("El perimetro es: %f", 2*pi*r);

    return 0;
}

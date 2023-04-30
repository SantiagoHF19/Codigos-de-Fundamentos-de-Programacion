#include <stdio.h>

int main()
{
    float arista, resultado;

    printf("introduzca la arista del cubo: ");
    scanf("%f", &arista);

    resultado = (arista * arista * arista);

    printf("Resultado: %f", resultado);

    return 0;
}

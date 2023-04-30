#include <stdio.h>

int main() {
    float cantidad_euros, cantidad_dolares, sobrante, kilos_azucar, kilos_cafe;

    printf("Introduce una cantidad en euros: ");
    scanf("%f", &cantidad_euros);

    cantidad_dolares = cantidad_euros * 1.19;

    kilos_azucar = (cantidad_dolares / 2) / 3;
    kilos_cafe = (cantidad_dolares / 3) / 0.72;

    sobrante = cantidad_dolares - ((kilos_azucar * 3) / 2 + (kilos_cafe * 0.72) / 3);

    printf("Con %.2f euros se pueden comprar:\n", cantidad_euros);
    printf("- %.2f kilos de azucar\n", kilos_azucar);
    printf("- %.2f kilos de cafe\n", kilos_cafe);
    printf("Dinero sobrante: %.2f euros\n", sobrante);

    return 0;

}


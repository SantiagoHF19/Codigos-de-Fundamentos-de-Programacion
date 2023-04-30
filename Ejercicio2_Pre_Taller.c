#include <stdio.h>

int main() {
    int n, digito, aux, cont_3 = 0, cont_5 = 0;

    printf("Ingrese la cantidad de numeros a procesar: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Ingrese un numero: ");
        scanf("%d", &digito);


        if (digito > 99 || digito <= -999) {

            aux = 0;
            int temp = digito;
            while (temp != 0) {
                aux = aux * 10 + temp % 10;
                temp = temp / 10;
            }
            printf("El numero invertido es %d\n", aux);
        }


        while (digito != 0) {
            if (digito % 10 == 3) {
                cont_3++;
            } else if (digito % 10 == 5) {
                cont_5++;
            }
            digito = digito / 10;
        }
    }

    printf("\nLa cantidad de 3 que ingresaste es %d\n", cont_3);
    printf("La cantidad de 5 que ingresaste %d\n", cont_5);

    return 0;
}

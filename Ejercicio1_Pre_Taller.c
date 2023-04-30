#include <stdio.h>

int suma_de_divisores(int num) {
    int suma = 0;
    for (int i = 1; i <= num / 2; i++) {
        if (num % i == 0) {
            suma += i;
        }
    }
    return suma;
}

int main() {
    int num1, num2;

    printf("Ingrese el primer numero: \n ");
    scanf("%d", &num1);
    printf("Ingrese el segundo numero: \n");
    scanf("%d", &num2);

    int suma = suma_de_divisores(num1);

    if (num2 == suma) {
        printf("\n%d y %d son amigos!\n", num1, num2);
    } else {
        printf("\n%d y %d no son amigos!\n", num1, num2);
    }

    return 0;
}

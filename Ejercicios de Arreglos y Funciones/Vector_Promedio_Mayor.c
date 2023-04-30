#include <stdio.h>


void leerVector(int vector[], int n) {
    printf("Ingrese los elementos del vector:\n");
    for (int i = 0; i < n; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &vector[i]);
    }
}


float calcularPromedio(int vector[], int n) {
    int suma = 0;
    for (int i = 0; i < n; i++) {
        suma += vector[i];
    }
    return (float)suma / n;
}


int encontrarMaximo(int vector[], int n) {
    int maximo = vector[0];
    for (int i = 1; i < n; i++) {
        if (vector[i] > maximo) {
            maximo = vector[i];
        }
    }
    return maximo;
}

int main() {
    int n;
    int vector[10];

    printf("Ingrese el tamaño del vector (max. 10): ");
    scanf("%d", &n);


    if (n <= 0 || n > 10) {
        printf("El tamaño del vector debe estar entre 1 y 10.\n");
        return 1;
    }

    leerVector(vector, n);


    float promedio = calcularPromedio(vector, n);
    int maximo = encontrarMaximo(vector, n);


    printf("Vector: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", vector[i]);
    }
    printf("\nPromedio: %.2f\n", promedio);
    printf("Valor maximo: %d\n", maximo);

    return 0;
}

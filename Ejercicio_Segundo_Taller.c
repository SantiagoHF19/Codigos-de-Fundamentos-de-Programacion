#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALUMNOS 100

typedef struct {
    char nombre[50];
    float notas[3];
    float promedio;
} Alumno;

 int leer_alumnos(Alumno alumnos[]);
 void calcular_promedio(Alumno alumnos[], int n);
 void ordenar_alumnos(Alumno alumnos[], int n);
 void generar_resultados(Alumno alumnos[], int n);

int main() {
    Alumno alumnos[MAX_ALUMNOS];
    int n;
    n = leer_alumnos(alumnos);
    calcular_promedio(alumnos, n);
    ordenar_alumnos(alumnos, n);
    generar_resultados(alumnos, n);
    return 0;
}

int leer_alumnos(Alumno alumnos[]) {
    FILE *fp;
    int i = 0;
    fp = fopen("notas_alumnos.txt", "r");
    if (fp == NULL) {
        printf("No se pudo abrir el archivo de entrada\n");
        exit(1);
    }
    while (!feof(fp) && i < MAX_ALUMNOS) {
        fscanf(fp, "%s %f %f %f", alumnos[i].nombre, &alumnos[i].notas[0], &alumnos[i].notas[1], &alumnos[i].notas[2]);
        i++;
    }
    fclose(fp);
    return i;
}

void calcular_promedio(Alumno alumnos[], int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        float suma = 0;
        for (j = 0; j < 3; j++) {
            suma += alumnos[i].notas[j];
        }
        alumnos[i].promedio = suma / 3;
    }
}

void ordenar_alumnos(Alumno alumnos[], int n) {
    int i, j;
    Alumno temp;
    for (i = 0; i < n-1; i++) {
        for (j = i+1; j < n; j++) {
            if (alumnos[i].promedio < alumnos[j].promedio) {
                temp = alumnos[i];
                alumnos[i] = alumnos[j];
                alumnos[j] = temp;
            }
        }
    }
}

void generar_resultados(Alumno alumnos[], int n) {
    FILE *fp;
    int i;
    fp = fopen("resultados.txt", "w");
    if (fp == NULL) {
        printf("No se pudo abrir el archivo de salida\n");
        exit(1);
    }
    fprintf(fp, "Posicion academica\t Nombre\t      Nota Final\n");
    for (i = 0; i < n; i++) {
        fprintf(fp, "  %d\t               %s\t        %.2f\n", i+1, alumnos[i].nombre, alumnos[i].promedio);
    }
    fclose(fp);
}

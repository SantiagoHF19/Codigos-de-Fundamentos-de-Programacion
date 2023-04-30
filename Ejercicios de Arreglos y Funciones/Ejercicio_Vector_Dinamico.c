#include <stdio.h>
#include <stdlib.h>

int main() {
  int *vector;
  int tam;
   printf("Introduce el tamaño del vector: ");
   scanf("%d", &tam);
   vector = (int*) malloc(tam * sizeof(int));

  if (vector == NULL) {
   printf("Error: no se ha podido asignar memoria.\n");
  return 1;
 }

  printf("Introduce los elementos del vector:\n");
  for (int i = 0; i < tam; i++) {
  scanf("%d", &vector[i]);
 }

  printf("El vector es: ");
   for (int i = 0; i < tam; i++) {
  printf("%d ", vector[i]);
 }
  printf("\n");
  free(vector);

return 0;
}

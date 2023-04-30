#include <stdio.h>

int main()
{
float exam1, exam2, exam3, media;

printf("Introduzca la nota del primer examen: ");
scanf("%f", &exam1);
printf("Introduzca la nota del segundo examen: ");
scanf("%f", &exam2);
printf("Introduzca la nota del tercer examen: ");
scanf("%f", &exam3);

media = ((exam1 + exam2 + exam3)/3);

printf("La media es: %f\n", media);

return 0;
}

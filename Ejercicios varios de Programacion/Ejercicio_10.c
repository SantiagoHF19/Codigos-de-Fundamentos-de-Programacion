/* Programa: Calificacion segun nota valida */
#include <conio.h>
#include <stdio.h>
int main()
{
    float nota;

    printf("\n Introduca nota (real): ");
    scanf("%f", &nota);

    /* Si la primera nota initroducida por el usuario es correcta,
       el bucle no itera ninguna vez. */

       while (nota < 0 || nota > 10)
       {
           printf("\n ERROR: Nota incorrecta, debe ser >= 0 y <= 10\n");
           printf("\n Introduza nota (real): ");
           scanf("%f", &nota);
       }

           /* Mientras que el usuario introduza una nota incorrecta,
           el bucle iterara. Y cuando introduzca una nota correcta,
           el bucle finalizara. */

        if (nota >= 5)
            printf("\n APROBADO");
        else
            printf("\n SUSPENDIDO");

        getch(); /* Pausa */

        return 0;
}

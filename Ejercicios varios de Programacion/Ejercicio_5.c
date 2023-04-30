#include <stdio.h>

int main()
{
    int v1, v2;

    printf("Introduzca el primer numero: ");
    scanf("%d", &v1);
    printf("Introduzca el segundo numero: ");
    scanf("%d", &v2);

    v1 = v1 + v2;
    v2 = v1 - v2;
    v1 = v1 - v2;

    printf("%d, %d", v1,v2);

    return 0;
}

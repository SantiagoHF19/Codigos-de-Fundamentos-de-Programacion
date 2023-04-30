#include <stdio.h>

int main() {
    int num_clientes, Total_Ganadores = 0, Ganadores_del5 = 0, Ganadores_del3 = 0, Ganadores_Gif_Card = 0;
    double Cantidad_total_descontada = 0.0;

    printf("Introduzca el numero de clientes: ");
    scanf("%d", &num_clientes);

    for (int i = 1; i <= num_clientes; i++) {
        int Cedula_cliente, num_productos;
        double Monto_factura, Cantidad_descontada;
        char Etiqueta_producto;

        printf("Introduzca la cedula del cliente: ");
        scanf("%d", &Cedula_cliente);

        printf("Introduzca el monto de la factura: ");
        scanf("%lf", &Monto_factura);

        printf("Introduzca el numero de productos: ");
        scanf("%d", &num_productos);

        printf("Introduzca la etiqueta del producto (M para Morado, A para Amarillo): ");
        scanf(" %c", &Etiqueta_producto);

        if (Monto_factura >= 1000 && Monto_factura <= 5000 && (Etiqueta_producto == 'M' || Etiqueta_producto == 'A') && num_productos >= 3) {
            Cantidad_descontada = Monto_factura * 0.5;

            if (Cedula_cliente % 2 == 0) {
                Cantidad_descontada += Monto_factura * 0.05;
                Ganadores_del5++;
            } else {
                Cantidad_descontada += Monto_factura * 0.03;
                Ganadores_del3++;
            }

            Cantidad_total_descontada += Cantidad_descontada;
            Total_Ganadores++;

            if (Monto_factura > Ganadores_Gif_Card) {
                Ganadores_Gif_Card = Monto_factura;
            }
        }
    }

    double Porcentaje_Ganadores_descuento = (double) Total_Ganadores / num_clientes * 100;
    printf("\nPorcentaje de clientes que ganaron el 50%% de descuento: %2.f%%\n", Porcentaje_Ganadores_descuento);
    printf("Numero de ganadores de la GIF card: %d\n", (Ganadores_Gif_Card > 0) ? 1 : 0);
    printf("Numero de clientes que obtuvo 5%% mas de descuento: %d\n", Ganadores_del5);
    printf("Numero de clientes que obtuvo 3%% mas de descuento: %d\n", Ganadores_del3);

    return 0;
}

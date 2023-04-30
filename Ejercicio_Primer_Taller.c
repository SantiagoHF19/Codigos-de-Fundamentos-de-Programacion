#include <stdio.h>

int main() {
  int tiempo_compra;
  char tipo_malla;
  float metros_comprados, costo_metro, descuento, costo_total, ingreso_total = 0, descuento_total = 0;
  int cont_beisbol = 0, cont_tenis = 0, cont_descuentos = 0, cont_compras = 0;

  printf("Bienvenido a TuMalla.com\n");

  do {
    printf("\nIngrese cuanto tiempo en años lleva comprando el cliente (0 para salir): ");
    scanf("%d", &tiempo_compra);

    if (tiempo_compra > 0) {
      printf("Ingrese el tipo de malla (B para beisbol, T para tenis): ");
      scanf(" %c", &tipo_malla);

      printf("Ingrese la cantidad de metros comprados: ");
      scanf("%f", &metros_comprados);

      if (tipo_malla == 'B') {
        costo_metro = 50;
        cont_beisbol++;
      } else {
        costo_metro = 80;
        cont_tenis++;
      }

      costo_total = costo_metro * metros_comprados;

      if (tiempo_compra > 15) {
        descuento = 0.3;
      } else if (tipo_malla == 'B' && tiempo_compra > 5) {
        descuento = 0.08;
      } else if (tipo_malla == 'T' && tiempo_compra > 5) {
        descuento = 0.06;
      } else {
        descuento = 0;
      }

      if (descuento > 0) {
        descuento_total += costo_total * descuento;
        cont_descuentos++;
      }

      costo_total -= costo_total * descuento;
      ingreso_total += costo_total;
      cont_compras++;

      printf("El costo de la compra es: $%.2f\n", costo_total);
    }

  } while (tiempo_compra != 0);

  printf("\nResumen del dia:\n");
  printf("Ingreso total: $%.2f\n", ingreso_total);
  printf("Cantidad de mallas para beisbol vendidas: %d\n", cont_beisbol);
  printf("Cantidad de mallas para tenis vendidas: %d\n", cont_tenis);

  if (cont_beisbol > cont_tenis) {
    printf("Se vendieron mas mallas de beisbol\n");
  } else if (cont_tenis > cont_beisbol) {
    printf("Se vendieron mas mallas de tenis\n");
  } else {
    printf("Se vendieron la misma cantidad de mallas de beisbol y tenis\n");
  }

  printf("Cantidad de clientes que obtuvieron descuento: %d\n", cont_descuentos);
  printf("Total de descuentos otorgados: $%.2f\n", descuento_total);
  printf("Cantidad total de compras: %d\n", cont_compras);

  return 0;
}

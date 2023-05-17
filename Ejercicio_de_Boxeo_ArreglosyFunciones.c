#include <stdio.h>


   void calcularPuntuacionFinal(int puntuacion[], int caidas[], int ganador, int *puntuacionFinalGanador, int *puntuacionFinalPerdedor) {
    *puntuacionFinalGanador = 0;
    *puntuacionFinalPerdedor = 0;

    for (int i = 0; i < 12; i++) {

        *puntuacionFinalGanador += puntuacion[i];

         if (caidas[i] > 0) {
            *puntuacionFinalPerdedor += (puntuacion[i] - (2 * caidas[i]));
        } else {
            *puntuacionFinalPerdedor += puntuacion[i];
        }
    }
}


   void contarRounds(int puntuacion[], int ganador, int *roundsGanadosGanador, int *roundsPerdidosGanador, int *roundsGanadosPerdedor, int *roundsPerdidosPerdedor) {
    *roundsGanadosGanador = 0;
    *roundsPerdidosGanador = 0;
    *roundsGanadosPerdedor = 0;
    *roundsPerdidosPerdedor = 0;

    for (int i = 0; i < 12; i++) {
        if (i == ganador) {
            *roundsGanadosGanador += 1;
            *roundsPerdidosPerdedor += 1;
        } else {
            *roundsGanadosPerdedor += 1;
            *roundsPerdidosGanador += 1;
        }
    }
}


 char* determinarTipoVictoria(int ganador, int puntuacionFinalGanador, int puntuacionFinalPerdedor) {
    if (puntuacionFinalGanador == puntuacionFinalPerdedor) {
        return "Decision por mayoria (MD)";
    } else if (puntuacionFinalGanador > puntuacionFinalPerdedor) {
        return "Decision unanime (UD)";
    } else {
        return "Decision dividida (SD)";
    }
}


  void determinarTarjetas(int puntuacion[], int *tarjetaMayor, int *tarjetaMenor) {
    *tarjetaMayor = 0;
    *tarjetaMenor = 0;

    for (int i = 1; i < 12; i++) {
        if (puntuacion[i] > puntuacion[*tarjetaMayor]) {
            *tarjetaMayor = i;
        }

        if (puntuacion[i] < puntuacion[*tarjetaMenor]) {
            *tarjetaMenor = i;
        }
    }
}


  void calcularBolsaFinal(int bolsaInicial, int tipoVictoria, int roundsGanados, int *bolsaFinalGanador, int *bolsaFinalPerdedor) {
    float porcentajeIncremento = 0;

    if (tipoVictoria == 0) {
        porcentajeIncremento = 0.05;
    } else if (tipoVictoria == 1) {
        porcentajeIncremento = 0.10;
    } else if (tipoVictoria == 2) {
        porcentajeIncremento = 0.15;
    }

    *bolsaFinalGanador = bolsaInicial + (int)(bolsaInicial * porcentajeIncremento * roundsGanados);
    *bolsaFinalPerdedor = (int)(0.6 * bolsaInicial) - (int)(bolsaInicial * porcentajeIncremento * roundsGanados);
}

  int main() {
    int puntuacion[12];
    int caidas[12];
    int ganador;


    printf("Ingrese la puntuación de cada round:\n");
    for (int i = 0; i < 12; i++) {
        printf("Round %d: ", i+1);
        scanf("%d", &puntuacion[i]);
    }


    printf("\nIngrese las caidas de cada round:\n");
    for (int i = 0; i < 12; i++) {
        printf("Round %d: ", i+1);
        scanf("%d", &caidas[i]);
    }


    printf("\nIngrese el numero del ganador (1-12): ");
    scanf("%d", &ganador);
    ganador--;


    int puntuacionFinalGanador, puntuacionFinalPerdedor;
    calcularPuntuacionFinal(puntuacion, caidas, ganador, &puntuacionFinalGanador, &puntuacionFinalPerdedor);


    int roundsGanadosGanador, roundsPerdidosGanador, roundsGanadosPerdedor, roundsPerdidosPerdedor;
    contarRounds(puntuacion, ganador, &roundsGanadosGanador, &roundsPerdidosGanador, &roundsGanadosPerdedor, &roundsPerdidosPerdedor);


    char* tipoVictoria = determinarTipoVictoria(ganador, puntuacionFinalGanador, puntuacionFinalPerdedor);


    int tarjetaMayor, tarjetaMenor;
    determinarTarjetas(puntuacion, &tarjetaMayor, &tarjetaMenor);


    int bolsaInicial = 100000;
    int bolsaFinalGanador, bolsaFinalPerdedor;
    calcularBolsaFinal(bolsaInicial, tarjetaMayor, roundsGanadosGanador, &bolsaFinalGanador, &bolsaFinalPerdedor);


    printf("\nPuntuación final:\n");
    printf("Ganador: %d\n", puntuacionFinalGanador);
    printf("Perdedor: %d\n", puntuacionFinalPerdedor);


    printf("\nRounds ganados y perdidos:\n");
    printf("Ganador - Rounds ganados: %d, Rounds perdidos: %d\n", roundsGanadosGanador, roundsPerdidosGanador);
    printf("Perdedor - Rounds ganados: %d, Rounds perdidos: %d\n", roundsGanadosPerdedor, roundsPerdidosPerdedor);


    printf("\nTipo de victoria: %s\n", tipoVictoria);


    printf("\nTarjeta de mayor puntuacion: Round %d\n", tarjetaMayor + 1);
    printf("Tarjeta de menor puntuacion: Round %d\n", tarjetaMenor + 1);


    printf("\nBolsa final:\n");
    printf("Ganador: $%d\n", bolsaFinalGanador);
    printf("Perdedor: $%d\n", bolsaFinalPerdedor);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <complex.h>
#include <unistd.h>

#include "interfaz.h"
#include "global.h"

#define CAR_LLENO "██"
#define CAR_VACIO "░░"

#define ROJO "\x1B[1;31m"
#define NORMAL "\x1B[0m"
#define AMARILLO "\x1B[1;33m"
#define VERDE "\x1B[1;32m"
#define AZUL "\x1B[1;34m"
#define NEGRITA "\x1B[1m"
#define AZULETE "\x1B[1;36m"

void barra(){

     system("clear");
     system("toilet --gay -fpagga CELUVITA\n\n");
     system("toilet -fpagga El juego de la vida\n");
     system("setterm -cursor off"); // OCULTA EL CURSOR
     sleep(2);

     for (int porcen  = 0; porcen <= 100; porcen++) {
          printf("\r");
            for (int progre = 0; progre <= porcen; progre++){
                 printf(AZUL "▬" NORMAL);
                 fflush(stdout);
                 usleep(1000);
             }
      printf(AZUL "▶ " NORMAL NEGRITA"%i%%" NORMAL, porcen);
     }

     printf("\n\n");

     system("setterm -cursor on"); // MUESTRA EL CURSOR

}

void inicio(){

    system("setterm -cursor off"); // OCULTA EL CURSOR

    time_t tiempo = time(0);
    struct tm *tlocal = localtime(&tiempo);

    char output[128];
    strftime(output, 128, "%d/%m/%y a las %H:%M:%S", tlocal);

    system("clear");
    system("toilet --gay -fpagga CELUVITA\n\n");
    printf("\n");
    sleep(2);
    printf(AMARILLO "❱     Te damos la bienvenida ");
    printf("%s", getenv("USER"));
    printf("\n" NORMAL);
    sleep(1);
    printf(VERDE "❱     CELUVITA v1.6 · Versión CONWAY 'ESTABLE'\n" NORMAL);
    sleep(1);
    printf(AZULETE "❱     Iniciada el %s\n" NORMAL,output);
    sleep(3);

    barra();
}

void menu(){

        printf(
        "+---------------------------------------------------------------------+\n"
        "|"      VERDE "\t\t¿Qué operación deseas realizar?" NORMAL     "\t\t\t      |\n"
        "+---------------------------------------------------------------------+\n"
        "|" NEGRITA "\t  Pulsa 1 " NORMAL "si quieres un juego automático" "\t\t\t      |\n"
        "|" NEGRITA "\t  Pulsa 2 " NORMAL "para ver el juego detenidamente"   "\t\t\t      |\n"
        "|" NEGRITA "\t  Pulsa 0 " NORMAL "si deseas salir" "\t\t\t\t      |\n"
        "+---------------------------------------------------------------------+\n");


}

void pintar(int matriz[M][N]) {
    for (int fila=0; fila<M; fila++) {
        for (int col=0; col<N; col++)
            printf(NEGRITA "%s" NORMAL, matriz[fila][col]? CAR_LLENO : CAR_VACIO);
        printf("\n");
    }
}

void dame_coord(int *x, int *y) {
        printf(ROJO "\tPara terminar, introduce coordenadas invalidas\n" NORMAL);
        printf("\n\n\tIntroduce tus cordenadas (x,y): ");
        scanf(" %i, %i", x, y);
        --*x, --*y;
}

void poblacion_inicial(int matriz[M][N]) {
    int x, y;

    do{
        system("clear");
        pintar(matriz);
        dame_coord(&x, &y);

        if ( SON_VALIDAS(x,y) )
            matriz[x][y] = 1;

    } while ( SON_VALIDAS(x,y) );
}

void rellena(int matriz[M][N]){
    int iniciales;
    int x, y;

    system("clear");
    printf(VERDE "¿Cuántos puntos iniciales quieres?\n" NORMAL
                 "Te recomendamos introducir más de 200\n\n"
         NEGRITA "Introduce la cantidad deseada: " NORMAL);
    scanf(" %i", &iniciales);

    for (int n=0; n<iniciales; n++) {
        x = rand() % M;
        y = rand() % N;
        matriz[x][y] = 1;
    }
}


#include <stdio.h>
#include <stdlib.h>

void random_area(int x[][100], int y[][100], int filas, int columnas, int celula);
void imprime_areas(int x[][100], int filas, int columnas);
void ciclo_vida(int x[][100], int y[][100], int filas, int columnas);
void copy_paste(int x[][100], int y[][100], int filas, int columnas);
void limpieza(int y[][100], int filas, int columnas);
bool estabilizate(int x[][100], int y[][100], int filas, int columnas);

int Poblacion(int x[][100], int filas, int columnas);

int main()
{
    int filas, columnas, celula;
    int m[100][100], t[100][100];

    printf("Introduce el número de filas: ");
    scanf(" %i",&filas);
    printf("Introduce el número de columnas: ");
    scanf(" %i", &columnas);
    printf("Cuantas celulas desea?");
    scanf("%i", &celula);

    random_area(m,t,filas,columnas,celula); //Generamos la matriz con las células (con las dimsensiones deseadas)

    printf("El area es: ");
    imprime_areas(m,filas,columnas); //Imprimimos el área

    printf("Presiona una tecla para comenzar");
    getch(); //Esta función espera la respuesta del teclado

    for(int i=1; 1; i++){
        system("clear");
        system("toilet -fpagga Celuvita");

        ciclo_vida(m,t,filas,columnas); //En esta función se verá que células mueren o viven
        imprime_areas(m,filas,columnas); //Imprime las nuevas células
/*
        if(estabilizate(m,t,filas,columnas)==1)
            printf("No es estable");
        else{
            static int ciclo=i;
            printf("Si es estable");
        }
        if(Poblacion(m,filas,columnas)==0)
            printf("Poblacion: 0");
        else
            printf("Poblacion: %i",Poblacion());
            copy_paste(m,t,filas,columnas); //actualiza la matriz original con la matriz temporal
            limpieza(t,f,columnas); //vuelve a inicializar la matriz temporal con ceros
            sleep(500);//espera dos segundos para que pase al siguiente ciclo
        }
*/
    printf("¡Gracias por jugar a Celuvita!");

    return EXIT_SUCCESS;
}

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <time.h>

//FILAS Y COLUMNAS TOTALES
#define COLUMNAS 40
#define FILAS 20

//REPETICIONES TOTALES
#define DuracionJUEGO 2000

//MÍNIMO DE CÉLULAS VIVAS QUE RODEAN PARA QUE NO SE MUERA
#define MINAguanta_celula 2
//MÁXIMO DE CÉLULAS VIVAS QUE RODEAN PARA QUE NO SE MUERA
#define MAXAguanta_celula 3

//MÁXIMO DE CÉLULAS VIVAS QUE RODEAN HA UNA MUERTA PARA REVIVIRLA
#define MINAguanta_celulaVive 2
//MÁXIMO DE CÉLULAS VIVAS QUE RODEAN HA UNA MUERTA PARA REVIVIRLA
#define MAXAguanta_celulaVive 3

//LUGAR
char poblacion[FILAS][COLUMNAS];

//REGLAS DEL JUEGO
int vida[4] = {MINAguanta_celula,MAXAguanta_celula,MINAguanta_celulaVive,MAXAguanta_celulaVive};

//FUNCIONES EN EL JUEGO
void vida_inicial();
void poblacion_celular();
void ver_vida();
int revision_celular(int,int);
void cicloCelular();


void vida_inicial(){
   int i,j;
   for (i = 0; i < FILAS; i++){
       for (j = 0; j < COLUMNAS; j++){
           poblacion[i][j] = '_';
       }
   }
}

void poblacion_celular(){
int fil,x,y;
srand(time(NULL));

//CREACIÓN ALEATORIA
for (fil = 0; fil < COLUMNAS; ++fil){
 y = rand()%COLUMNAS;
 x = rand()%FILAS;
 if(poblacion[x][y]=='_')
  poblacion[x][y]='O';
}
}

void ver_vida(){
   int i,j;
   for (i = 0; i < FILAS; i++){
           printf("\n");
       for (j = 0; j < COLUMNAS; j++){
           printf("%c",poblacion[i][j] );
       }
   }
   printf("\n");
}

//CONTADOR DE CÉLULAS
int revision_celular(int posicionFILAS, int posicionCOLUMNAS){
int celulillas_vecinas = 0;
if(posicionFILAS-1 >= 0 && posicionCOLUMNAS-1 >= 0)
 if(poblacion[posicionFILAS-1][posicionCOLUMNAS-1] == 'O')
  celulillas_vecinas++;
if(posicionFILAS-1 >= 0)
 if(poblacion[posicionFILAS-1][posicionCOLUMNAS] == 'O')
  celulillas_vecinas++;
if(posicionFILAS-1 >= 0 && posicionCOLUMNAS+1 <= COLUMNAS-1)
 if(poblacion[posicionFILAS-1][posicionCOLUMNAS+1] == 'O')
  celulillas_vecinas++;
if(posicionCOLUMNAS-1 >= 0)
 if(poblacion[posicionFILAS][posicionCOLUMNAS-1] == 'O')
  celulillas_vecinas++;
if(posicionCOLUMNAS+1 <= COLUMNAS-1)
 if(poblacion[posicionFILAS][posicionCOLUMNAS+1] == '0')
  celulillas_vecinas++;
if(posicionFILAS+1 <= FILAS-1 && posicionCOLUMNAS-1 >= 0)
 if(poblacion[posicionFILAS+1][posicionCOLUMNAS-1] == 'O')
  celulillas_vecinas++;
if(posicionFILAS+1 <= FILAS-1)
 if(poblacion[posicionFILAS+1][posicionCOLUMNAS] == 'O')
  celulillas_vecinas++;
if(posicionFILAS+1 <= FILAS-1 && posicionCOLUMNAS+1 <= COLUMNAS-1)
 if(poblacion[posicionFILAS+1][posicionCOLUMNAS+1] == 'O')
  celulillas_vecinas++;

//DEVUELVE LOS celulillas_vecinas
return celulillas_vecinas;
}

void cicloCelular(){
int fil,col;
int n_celulillas_vecinas;

//PRINCIPAL CICLO DEL JUEGO
for(fil = 0; fil < FILAS; fil++){
 for(col = 0; col < COLUMNAS; col++){
  n_celulillas_vecinas = revision_celular(fil,col);

  //CONDICIONES PARA LA NO MUERTE DE LA CÉLULA
  if(poblacion[fil][col] == '_'){
   if(n_celulillas_vecinas == MINAguanta_celulaVive || n_celulillas_vecinas == MAXAguanta_celulaVive)
    poblacion[fil][col] = 'O';
   else
    poblacion[fil][col] = '_';
  }
  else if(poblacion[fil][col] == 'O'){
   if(n_celulillas_vecinas == MINAguanta_celula || n_celulillas_vecinas == MAXAguanta_celula)
    poblacion[fil][col] = 'O';
   else
    poblacion[fil][col] = '_';
  }
 }
}
}

//FUNCIÓN PRINCIPAL
int main(){

  int i=0;
  int opcion;

  printf("¡BIENVENIDO A CELUVITA!\n");
  printf("Pulsa 1 para comenzar\n");
  printf("Opción escogida: ");
  scanf("%i", &opcion);

  printf("ANTES DE COMENZAR EL JUEGO\n"
         "Para parar el proceso, pulsa 0");

  if (opcion == 1) {
      vida_inicial();
      poblacion_celular();

      while(i < DuracionJUEGO){
          ver_vida();
          usleep(100000); //VELOCIDAD DE CAMBIOS EN LAS CÉLULAS
          system("clear");
          cicloCelular();
          i++;
      }
  }else{
    printf("¡GRACIAS POR JUGAR A ESTE JUEGO!\n");
    return EXIT_SUCCESS;
  }

}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NUM_MAX 50
#define LONGITUD 100


char matrizPalabras[NUM_MAX][LONGITUD]; 
char matrizOrdenadas[NUM_MAX][LONGITUD];


void limpiarMatriz();

int main(){
    
    int num_pal = 0;
    int cont    = 0;

    limpiarMatriz();

    printf("\n¿Cuantas palabras desea ingresar?\n");
    printf("R: ");
    scanf("%d", &num_pal);

    
    if(num_pal <= NUM_MAX){
         
         while(cont < num_pal){
           printf("\nPalabra %d: ", cont+1);
           scanf("%s",matrizPalabras[cont]);
           strcpy(matrizOrdenadas[cont], matrizPalabras[cont]);
           getchar();
           cont++;
         } 

         printf("\n-----------------------");
         // Ordenar por columnas

         int i, j;
         int columnas;
         char temp   = '\0';

     
    for(columnas = 0; columnas < LONGITUD; columnas++){
       
       for(i=0; i < num_pal-1; i++){
            for(j=i+1; j < num_pal; j++){

               temp = tolower(matrizOrdenadas[i][columnas]);
               
               if(temp >= 97 && temp <= 122){
            
                   if(temp > tolower(matrizOrdenadas[j][columnas])){
                   
                    temp = matrizOrdenadas[j][columnas];
                    matrizOrdenadas[j][columnas] = matrizOrdenadas[i][columnas];
                    matrizOrdenadas[i][columnas] = temp;

                   }
                    
               }

             }
         }
    }

    for(i=0; i < 6; i++){
        printf("\n");
        puts(matrizOrdenadas[i]);
        printf("\n");
    }
         
        // Mostrar matriz original

        // Mostrar matriz ordenada

    }
    else{
        printf("El maximo numero de palabras permitido es %d \n.", NUM_MAX);
    }
     

    return 0;
}

void limpiarMatriz(){
    int i;
    for(i=0; i < NUM_MAX; i++){
       strcpy(matrizPalabras[i],"");
       strcpy(matrizOrdenadas[i],"");
    }
}




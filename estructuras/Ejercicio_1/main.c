#include <stdio.h>
#include <stdlib.h>
#define TAM_ARCHIVO 10

typedef struct tiempo{
        int anio, mes, dia, hora, minuto, segundo;
} Tiempo;

typedef struct {
        char * nombre;
        Tiempo ultima_mod;
} Archivo;

int compara_tiempos(Tiempo *t1, Tiempo *t2){
        if(t1->anio > t2->anio){
                return -1;
        } else if( t2->anio > t1->anio){
                return 1;
        } else{
                if(t1->mes > t2->mes){
                        return -1;
                } else if(t2->mes > t1->mes){
                        return 1;
                } else{
                        if(t1->dia > t2->dia){
                                return -1;
                        } else if(t2->dia > t1->dia){
                                return 1;
                        } else{
                                if(t1->hora > t2->hora){
                                        return -1;
                                } else if(t2->hora > t1->hora){
                                        return 1;
                                } else {
                                        if(t1->minuto > t2->minuto){
                                                return -1;
                                        } else if(t2->minuto > t1->minuto){
                                                return 1;
                                        } else{
                                                if(t1->segundo > t2->segundo){
                                                        return -1;
                                                } else if(t2->segundo > t1->segundo){
                                                        return 1;
                                                } else {
                                                        return 0;
                                                }
                                        }
                                }
                        }
                }
        }
}

void imprime_tiempo( Tiempo t ){
        printf("%d/%d/%d %d:%d:%d", t.dia, t.mes, t.anio, t.hora, t.minuto, t.segundo);
}

void ordena_alfa(Archivo *lista, int n){
        int i,j,resultado;
        Archivo aux;
        for(i = 0; i< n-1;i++){
                for(j = i+1;j<n;j++){
                        resultado = strcmp(lista[i].nombre, lista[j].nombre);
                        if(resultado == 1){
                                aux = lista[i];
                                lista[i] = lista[j];
                                lista[j] = aux;
                        }

                }
        }
}


void ordena_temporal(Archivo *lista, int n){
        int i,j,resultado;
        Archivo aux;
        for(i = 0; i< n-1;i++){
                for(j = i+1;j<n;j++){
                        resultado = compara_tiempos(&lista[i].ultima_mod, &lista[j].ultima_mod);
                        if(resultado == -1){
                                aux = lista[i];
                                lista[i] = lista[j];
                                lista[j] = aux;
                        }

                }
        }
}

int main()
{

        Tiempo uno, dos;
        uno.anio = 2010;uno.mes = 12;uno.dia = 10;uno.hora = 22;uno.minuto = 25;uno.segundo = 30;
        dos.anio = 2010;dos.mes = 12;dos.dia = 10;dos.hora = 21; dos.minuto = 47; dos.segundo = 37;


        int resultado = compara_tiempos(&uno, &dos);
        printf("\n Tiempo Uno: ");
        imprime_tiempo(uno);
        printf("\n Tiempo Dos: ");
        imprime_tiempo(dos);
        printf("\n");
        if(resultado == 1){
                printf(" El tiempo 1 es anterior al tiempo 2");
        } else if(resultado == -1){
                printf(" El tiempo 2 es anterior al tiempo 1");
        } else {
                printf(" Las fechas son iguales");
        }



        Archivo archivos[TAM_ARCHIVO];
        archivos[0].nombre = "Dario";archivos[1].nombre = "Martina";archivos[2].nombre = "Benjamin";archivos[3].nombre = "Juliana";
        archivos[4].nombre = "Valentina";archivos[5].nombre = "Analia";archivos[6].nombre = "Candela";archivos[7].nombre = "Luna";
        archivos[9].nombre = "Agustin";archivos[8].nombre = "Julia";




        int i;
      for(i=1;i<=TAM_ARCHIVO;i++){
                archivos[i-1].ultima_mod.anio = 2025;
                archivos[i-1].ultima_mod.mes = 5;
                archivos[i-1].ultima_mod.dia = i*2;
                archivos[i-1].ultima_mod.hora = 22;
                archivos[i-1].ultima_mod.minuto = 30;
                archivos[i-1].ultima_mod.segundo = 25;
        }

        printf("\n\n");
            printf("\n------------------------------------------------------------\n");
        printf(" Pre-Ordenamiento Alfabetico\n");
        for(i = 0;i <TAM_ARCHIVO;i++){
                printf(" [%d] - Nombre: %20s\n", i,archivos[i].nombre);
        }
        ordena_alfa(archivos, TAM_ARCHIVO);
        printf(" Post-ordenamiento Alfabetico\n");
        for(i = 0;i <TAM_ARCHIVO;i++){
                printf(" [%d] - Nombre: %20s\n", i,archivos[i].nombre);
        }



        printf("\n------------------------------------------------------------\n");
        printf(" Pre-Ordenamiento Temporal\n");
        for(i = 0;i <TAM_ARCHIVO;i++){
                printf(" [%d] - Nombre: %20s    |   Dia: %d\n", i,archivos[i].nombre, archivos[i].ultima_mod.dia);
        }
        ordena_temporal(archivos, TAM_ARCHIVO);
        printf(" Post-ordenamiento Temporal\n");
        for(i = 0;i <TAM_ARCHIVO;i++){
                printf(" [%d] - Nombre: %20s    |   Dia: %d\n", i,archivos[i].nombre, archivos[i].ultima_mod.dia);
        }

        return 0;
}

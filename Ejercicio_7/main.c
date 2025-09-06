#include <stdio.h>
#include <stdlib.h>
#define TAM_ARR 10


/*       7. Recorriendo un array
Crear un programa que lea un numero determinado (100) de reales introducidos por teclado,
los almacene en un vector para luego mostrarlos en orden inverso. Para recorrer el array debera usar
aritmetica de punteros en lugar deindices del array.*/

int main(){

        int numeros[TAM_ARR];
        int *pp;
        pp = numeros;
        int i, varTmp;
        for(i=0;i<TAM_ARR;i++){
                printf("Ingrese el elemento numero %d: ", i+1);
                scanf("%d", &varTmp);
                *pp = varTmp;
                if(TAM_ARR - i > 1){pp+=1;};
        }
        for(i=TAM_ARR-1;i>=0;i--){
                printf("\n[ %d ] =  %d", i+1, *pp);
                pp-=1;
        }
        return 0;

}

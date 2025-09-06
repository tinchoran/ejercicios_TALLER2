#include <stdio.h>
#include <stdlib.h>
#define TAM_ARR 10


/*       7. Recorriendo un array
Crear un programa que lea un numero determinado (100) de reales introducidos por teclado,
los almacene en un vector para luego mostrarlos en orden inverso. Para recorrer el array debera usar
aritmetica de punteros en lugar deindices del array.*/

//Notas: el ejercicio pide números reales, entonces debería usarse float o double como tipo de dato, pero lo hice con int
//En caso de querer hacerlo con reales deberían ser modificadas las variables: numeros, pp, varTmp por float o double en vez de int

int main(){

        //Declaramos el array donde guardaremos los números
        int numeros[TAM_ARR]; //Hecho con int para simplificar

        //Declaramos el puntero que utilizaremos para recorrer el arreglo
        int *pp;

        //Le asignamos al puntero pp la dirección de memoria del primer elemento del array (también podríamos hacer pp = &numeros[0])
        pp = numeros;

        //Variables secundarias para el funcionamiento del programa
        int i, varTmp;

        //Bucle for para ingresar los valores en el arreglo
        for(i=0;i<TAM_ARR;i++){
                printf("Ingrese el elemento numero %d: ", i+1);
                scanf("%d", &varTmp);

                *pp = varTmp;
                //Aquí le estamos diciendo que modifique la variable que está en la dir. de memoria a la que apunta el puntero,
                // sería lo mismo que hacer: numeros[i] = varTmp, pero lo estamos haciendo con aritmética de punteros y no con índices.

                //Vamos aumentando el valor del puntero en una posición de memoria por ciclo
                if(TAM_ARR - i > 1){pp+=1;};
                //El if está porque si no lo ponemos, en el último ciclo se aumentará en 1 y apuntará a la dirección de memoria contigua al último elemento del array.
        }

        //Bucle for que empieza con i = TAM_ARR - 1 para mostrar el arreglo de forma inversa
        for(i=TAM_ARR-1;i>=0;i--){
                //El puntero quedó apuntando en el anterior bucle hacia la dirección de memoria del último elemento del arreglo
                printf("\n[ %d ] =  %d", i+1, *pp);
                //Nuevamente usamos el puntero para acceder al valor  de la variable, utilizando el * antes del puntero pp

                //Finalmente decrementamos en 1 el puntero al terminar cada ciclo
                pp-=1;
        }
        return 0;

}

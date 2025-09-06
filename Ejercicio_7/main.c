#include <stdio.h>
#include <stdlib.h>
#define TAM_ARR 10


/*       7. Recorriendo un array
Crear un programa que lea un numero determinado (100) de reales introducidos por teclado,
los almacene en un vector para luego mostrarlos en orden inverso. Para recorrer el array debera usar
aritmetica de punteros en lugar deindices del array.*/

//Notas: el ejercicio pide n�meros reales, entonces deber�a usarse float o double como tipo de dato, pero lo hice con int
//En caso de querer hacerlo con reales deber�an ser modificadas las variables: numeros, pp, varTmp por float o double en vez de int

int main(){

        //Declaramos el array donde guardaremos los n�meros
        int numeros[TAM_ARR]; //Hecho con int para simplificar

        //Declaramos el puntero que utilizaremos para recorrer el arreglo
        int *pp;

        //Le asignamos al puntero pp la direcci�n de memoria del primer elemento del array (tambi�n podr�amos hacer pp = &numeros[0])
        pp = numeros;

        //Variables secundarias para el funcionamiento del programa
        int i, varTmp;

        //Bucle for para ingresar los valores en el arreglo
        for(i=0;i<TAM_ARR;i++){
                printf("Ingrese el elemento numero %d: ", i+1);
                scanf("%d", &varTmp);

                *pp = varTmp;
                //Aqu� le estamos diciendo que modifique la variable que est� en la dir. de memoria a la que apunta el puntero,
                // ser�a lo mismo que hacer: numeros[i] = varTmp, pero lo estamos haciendo con aritm�tica de punteros y no con �ndices.

                //Vamos aumentando el valor del puntero en una posici�n de memoria por ciclo
                if(TAM_ARR - i > 1){pp+=1;};
                //El if est� porque si no lo ponemos, en el �ltimo ciclo se aumentar� en 1 y apuntar� a la direcci�n de memoria contigua al �ltimo elemento del array.
        }

        //Bucle for que empieza con i = TAM_ARR - 1 para mostrar el arreglo de forma inversa
        for(i=TAM_ARR-1;i>=0;i--){
                //El puntero qued� apuntando en el anterior bucle hacia la direcci�n de memoria del �ltimo elemento del arreglo
                printf("\n[ %d ] =  %d", i+1, *pp);
                //Nuevamente usamos el puntero para acceder al valor  de la variable, utilizando el * antes del puntero pp

                //Finalmente decrementamos en 1 el puntero al terminar cada ciclo
                pp-=1;
        }
        return 0;

}

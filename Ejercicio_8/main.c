#include <stdio.h>

/*8.      Retornar un puntero
Escribir una funcion que tome como argumento un entero positivo entre 1 y 7
y retorne un puntero a cadena con el nombre del da de la semana correspondiente
al argumento. Probar dicha funcion.*/

char *funcion(int x);

char *funcion(int x){
        //Arreglo de punteros a char -> Es un arreglo unidimensional, donde cada item apunta al primer char de un arreglo de chars(string)
        char *semana[] = {"Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado", "Domingo"};
        return semana[x-1];
}

int main(){
        int diaIngresado;
        printf("\n  Ingrese el numero de dia de la semana (1-7): ");
        scanf("%d", &diaIngresado);
        while(diaIngresado < 1 || diaIngresado > 7){
                printf("\n  [ERROR] - Debe ingresar un numero entre 1 y 7");
                printf("\n  Intente nuevamente: ");
                scanf("%d", &diaIngresado);
        }
        printf("\n  El dia numero %d de la semana es el [%s]\n\n\n ", diaIngresado,funcion(diaIngresado));

        return 0;
}

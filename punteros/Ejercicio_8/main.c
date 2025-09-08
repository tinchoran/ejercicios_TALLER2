#include <stdio.h>

/*  8. Retornar un puntero
Escribir una funcion que tome como argumento un entero positivo entre 1 y 7
y retorne un puntero a cadena con el nombre del da de la semana correspondiente
al argumento. Probar dicha funcion.*/

char *funcion(int x);

char *funcion(int x){
        //Arreglo de punteros a char -> Es un arreglo unidimensional, donde cada item apunta al primer char de un arreglo de chars(string)
        char *semana[] = {"Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado", "Domingo"};
        //El arreglo "semana" se guarda en el stack, mientras que las strings a las que apuntan son constantes, por lo que se guardan
        // en la parte "text" de la memoria. Esto es importante porque el arreglo de punteros "semana" dejará de existir al terminar la ejecución de la función,
        // pero antes de que se destruya nosotros retornamos un puntero que apunta a una cadena constante en la memoria que no se pierde aunque la función haya finalizado su ejecución.
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

        printf("\n  El dia numero %d de la semana es el [%s]\n\n\n ", diaIngresado , funcion(diaIngresado));
        //Aquí arriba indicamos que vamos a printear una cadena con el especifier "%s", y le pasamos como argumento la dirección de memoria
        //que nos devuelve la función, siendo esta la dirección del primer elemento del arreglo de caracteres para el día correspondiente. Printf toma
        //ese puntero y se encarga del resto, printeando caracter tras caracter hasta encontrar el fin de cadena ('\0')

        return 0;
}

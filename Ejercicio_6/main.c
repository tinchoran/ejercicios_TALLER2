#include <stdio.h>

/*
        6. Escriba un programa que de na las siguientes variables
int i=5, j[]={1,2,3,4,5,6,7,8,9,10};
char x = a , pal [] ="texto en c";
int *pi;
char *pc;
 1. Mostrar la direccion de i y su valor.
 2. Mostrar los mismos valores a traves del puntero pi .
 3. Recorrer el vector j mostrando para cada elemento, su direccion y valor.
 4. Recorra el vector accediendo a traves del puntero pi y usando algebra de
 punteros.
 5. Repita lo mismo con las variables char, el arreglo y el puntero.
 6. Finalmente muestre la direccion donde se almacenan ambos punteros.
*/

int main(){
        int i=5, j[]={1,2,3,4,5,6,7,8,9,10};
        char x = 'a' , pal [] ="texto en c";
        int *pi;
        char *pc;
        int longitudDeLosArrays = 10; //Ambos arrays tienen longitud
        // 1)
        printf("-------------------------------- 1 -------------------------------- \n");
        printf(" Por variable: 'i'   Valor: %d      Direccion: %p", i, &i);
        //
        printf("\n\n");

        // 2)
        pi = &i;
        printf("-------------------------------- 2 -------------------------------- \n");
        printf(" Por Puntero: 'pi'   Valor: %d      Direccion: %p", *pi, pi);
        //
        printf("\n\n");

        // 3)
        int k;
        printf("-------------------------------- 3 -------------------------------- \n");
        for(k=0;k<longitudDeLosArrays;k++){
                printf(" Por Variable: 'j[%d]' Valor: %2d    Direccion: %p", k, j[k], &j[k]);
                printf("\n");
        }
        printf("\n");
        // 4)
        pi = j;
        printf("-------------------------------- 4 -------------------------------- \n");
        for(k=0;k<longitudDeLosArrays;k++){
                printf(" Por Puntero: 'pi(=&j)+%d' Valor: %2d    Direccion: %p", k, *pi, pi);
                pi++;
                printf("\n");
        }
        printf("\n");
        // 5.1)
        printf("------------------------------- 5.1 ------------------------------- \n");
        printf(" Por variable: 'x'   Valor: %c      Direccion: %p", x, &x);
        //
        printf("\n\n");

        // 5.2)
        pc = &x;
        printf("------------------------------- 5.2 ------------------------------- \n");
        printf(" Por Puntero: 'pc'   Valor: %c      Direccion: %p", *pc, pc);
        //
        printf("\n\n");

        // 5.3)
        printf("------------------------------- 5.3 ------------------------------- \n");
        for(k=0;k<longitudDeLosArrays;k++){
                printf(" Por Variable: 'pal[%d]' Valor: %c    Direccion: %p", k, pal[k], &pal[k]);
                printf("\n");
        }
        printf("\n");
        // 5.4)
        printf("------------------------------- 5.4 ------------------------------- \n");
        pc = pal;
        for(k=0;k<longitudDeLosArrays;k++){
                printf(" Por Puntero: 'pc(=&pal)+%d' Valor: %c    Direccion: %p", k, *pc, pc);
                pc++;
                printf("\n");
        }
        printf("\n");
        // 6)
        printf("-------------------------------- 6 -------------------------------- \n");
        printf(" El puntero 'pi' se encuentra almacenado en:  %p", &pi);
        printf("\n");
        printf(" El puntero 'pc' se encuentra almacenado en:  %p", &pc);

        printf("\n\n\n");
        return 0;
}

# Ejercicio 6
### Escriba un programa que defina las siguientes variables
```c
int i=5, j[]={1,2,3,4,5,6,7,8,9,10};
char x = 'a', pal [] ="texto en c";
int *pi;
char *pc;
```
1. Mostrar la dirección de "i" y su valor.
2. Mostrar los mismos valores a través del puntero "pi".
3. Recorrer el vector "j" mostrando para cada elemento, su dirección y valor.
4. Recorra el vector accediendo a través del puntero "pi" y usando álgebra de punteros.
5. Repita lo mismo con las variables char, el arreglo y el puntero.
6. Finalmente muestre la dirección donde se almacenan ambos punteros.


**Genere una salida similar a esta:**
```
Por Variable: 'i' Valor: 5 Direccion: 13FF5C
Por Puntero: 'pi' Valor: 5 Direccion: 13FF5C
Por Variable: 'j[0]' Valor: 1 Direccion: 13FF2C
Por Puntero: 'pi(=&j)+0' Valor: 1 Direccion: 13FF2C
Por Variable: 'j[1]' Valor: 2 Direccion: 13FF30
Por Puntero: 'pi(=&j)+1' Valor: 2 Direccion: 13FF30
Por Variable: 'x' Valor: a Direccion: 13FF23
Por Puntero: 'pc' Valor: a Direccion: 13FF23
Por Variable: 'pal[0]' Valor: t Direccion: 13FF0C
Por Puntero: 'pc(=&pal)+0' Valor: t Direccion: 13FF0C
Por Variable: 'pal[1]' Valor: e Direccion: 13FF0D
Por Puntero: ' pc(=&pal)+1' Valor: e Direccion: 13FF0D
...
Direccion de *pi: 13FF00 De *pc: 13FEF4
```
# Ejercicio 7 
### Recorriendo un array
Crear un programa que lea un número determinado (<100) de reales introducidos por teclado, los almacene en un vector para luego mostrarlos en orden inverso. Para recorrer el array deberá usar aritmética de punteros en lugar de
índices del array.
# Ejercicio 8
### Retornar un puntero
Escribir una función que tome como argumento un entero positivo entre 1 y 7
y retorne un puntero a cadena con el nombre del día de la semana correspondiente
al argumento. Probar dicha función.
# Ejercicio 9
### Cadena de caracteres
Escribir las funciones que operan sobre cadenas de caracteres.
```c
#include <stdio.h>
#include <stdlib.h>
typedef enum { MAYUSCULAS, MINUSCULAS } may_min;
int strLargo(const char *origen); //Cantidad de caracteres
int strVacio(const char *origen); //retorna 1 si tiene al
menos un caracter, 0 en otro caso
void strCopia(char *destino, const char *origen); // Copiador
/*prototipo modificado para permitir argumentos de tipo
string literales, en casi todos los
compiladores un literal string es considerado una constante,
o sea la función no podría modificarlos pero, en algunos compiladores tales como GCC es posible modificarlos (según
K&R el comportamiento es indefinido)*/

char* reverse(char *string);//retorna una cadena que es
string invertida
void strIzq(char *destino, const char *origen); // Saca
blancos Izq.
void strDer(char *destino, const char *origen); // Saca
blancos Der.
void strAmbos(char *destino, const char *origen); // Saca
blancos Izq. y Der.
void strMayMin(char *destino, const char *origen, may_min m);
// Convierte May. Min.
int main(){
    char *text1 =" Sera Cierto ?? ";
    int largo=strLargo(text1)+1;
    char *result = (char *)malloc (largo);
    char* reves;
    if(result == NULL)
        return -1;//si no pudo reservar memoria para result
    printf("La cadena: ");
    puts(text1);

    printf("Se encuentra: %s\n", (strVacio(text1) ? "Novacia" : "Vacia"));

    printf("Largo : %d\n", strLargo(text1));


    strCopia(result, text1);
    printf("Copia : [%s]\n", result);

    strIzq(result, text1);
    printf("Sin blancos a la Izq:");
    puts(result);

    strDer(result, text1);
    printf("Der : [%s]\n", result);

    strAmbos(result, text1);
    printf("Ambos: [%s], sin blancos al principio ni alfinal.\n", result);

    strMayMin(result, text1, MAYUSCULAS);
    printf("Mayusculas : [%s]\n", result);

    strMayMin(result, text1, MINUSCULAS);
    printf("Minusculas : [%s]\n", result);

//  reves = reverse(text1);
//  printf("La cadena: %s invertida queda: %s\n", text1, reves);

    return 0;
}
```
**La salida debería tener que ser similar a esta:**
```
La cadena: Sera Cierto ??
Se encuentra: No vacia
Largo : 20
Copia : [ Sera Cierto ?? ]
Sin blancos a la Izq:Sera Cierto ??
Der : [ Sera Cierto ??]
Ambos: [Sera Cierto ??], sin blancos al principio ni al final.
Mayusculas : [ SERA CIERTO ?? ]
Minusculas : [ sera cierto ?? ]
La cadena: Sera Cierto ?? invertida queda ?? otreiC areS
Presione una tecla para continuar . . .
```
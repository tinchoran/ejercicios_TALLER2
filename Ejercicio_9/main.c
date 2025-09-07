/*9.                    Cadena de caracteres
Escribir las funciones que operan sobre cadenas de caracteres.*/

#include <stdio.h>
#include <stdlib.h>

typedef enum { MAYUSCULAS, MINUSCULAS } may_min;

int strLargo(const char *origen); // Cantidad de caracteres
int strVacio(const char *origen); // retorna 1 si tiene al menos un caracter, 0 en otro caso
void strCopia(char *destino, const char *origen); // Copiador
/* prototipo modificado para permitir argumentos de tipo string literales.
   En casi todos los compiladores un literal string es considerado una constante,
   o sea la función no podría modificarlos pero, en algunos compiladores tales como GCC
   es posible modificarlos (según K&R el comportamiento es indefinido) */

char* reverse(char *string); // retorna una cadena que es string invertida

void strIzq(char *destino, const char *origen);   // Saca blancos a la izquierda
void strDer(char *destino, const char *origen);   // Saca blancos a la derecha
void strAmbos(char *destino, const char *origen); // Saca blancos a izquierda y derecha
void strMayMin(char *destino, const char *origen, may_min m); // Convierte May/Min

int main()
{
        char *text1 = "  Sera  Cierto  ??  ";
        int largo = strLargo(text1) + 1;
        char *result = (char *) malloc(largo);
        char *reves;

        if (result == NULL)
                return -1; // si no pudo reservar memoria para result

        printf("La cadena: ");
        puts(text1);


        printf("Largo : %d\n", strLargo(text1));

        printf("Se encuentra: %s\n", (strVacio(text1) ? "No vacia" : "Vacia"));

        strCopia(result, text1);
        printf("Copia : [%s]\n", result);

        strIzq(result, text1);
        printf("Sin blancos a la Izq:");
        puts(result);

        strDer(result, text1);
        printf("Der : [%s]\n", result);

//        strAmbos(result, text1);
//        printf("Ambos: [%s], sin blancos al principio ni al final.\n", result);
//
//        strMayMin(result, text1, MAYUSCULAS);
//        printf("Mayusculas : [%s]\n", result);
//
//        strMayMin(result, text1, MINUSCULAS);
//        printf("Minusculas : [%s]\n", result);
//
//        reves = reverse(text1);
//        printf("La cadena: %s invertida queda: %s\n", text1, reves);

        return 0;
}


int strLargo(const char *origen){
        int contador = 0;
        //Leemos todos los caracteres de la cadena hasta que encontremos el caracter de fin de cadena (\0), y vamos incrementando la variable de contador
        while(*origen != '\0'){
                origen++;
                contador++;
        }
        return contador;
}

int strVacio(const char *origen){
        return (*origen != '\0')?1:0;
}

void strCopia(char *destino, const char *origen){
        while(*origen != '\0'){
                *destino = *origen;   //Copiamos en la dir. de memoria a la que apunta destino el valor que es apuntado por el puntero origen
                destino++;
                origen++;
        }
        *destino = '\0';  //Debemos ponerlo para que c lo interprete como una cádena válida, ya que siempre va al final de una cadena
}

void strIzq(char *destino, const char *origen){
        //Primero debemos inicializar el puntero origen para que apunte al primer caracter que no es un espacio vacío de la cadena
        //Para eso usamos este while en el que incrementamos el puntero mientras apunte a un caracter de espacio vacío
        while(*origen == ' ' && *origen != '\0'){
                origen++;
        }
        //Ahora que ya tenemos el puntero "origen" apuntando al primer caracter que no es un espacio vacío de la cadena, empezamos a copiar la cadena en destino
        while(*origen != '\0'){
                *destino = *origen;
                origen++;
                destino++;
        }
        *destino = '\0'; //Especificamos fin de cadena para que C interprete el arreglo de caracteres como una cadena
}

void strDer(char *destino, const char *origen){
        //Definimos una variable contador que nos servirá para movernos con los punteros sin perder sus valores iniciales y sin crear nuevas variables duplicadas
        int contador = 0;
        //Aumentamos el contador hasta el final de la cadena
        while(*origen != '\0'){
                origen++;
                contador++;
        }
        //Devolvemos a origen a su posición inicial ya que la necesitaremos para copiar la string a destino
        origen-=contador;
        //Decrementamos en uno el contador porque está aumentado hasta el '\0', y queremos evitar eso
        contador--;

        //Es una forma de recorrer de forma inversa, osea de derecha a izquierda. Le vamos sumando el valor de contador
        //en posiciones de memoria hasta que encontremos un caracter que sea distinto de espacios en blanco.
        //Esto nos sirve para posicionar el contador para que guarde el índice del primer caracter desde la derecha que no es un espacio en blanco
        while(*(origen + contador) == ' '){
                contador--;
        }
        //Como siempre, no nos olvidamos de colocar en la última dirección de memoria del arreglo de caracteres el caracter nulo
        *(destino + contador + 1) = '\0';

        //Con un for vamos decrementando la variable contador para copiar la cadena de derecha a izquierda
        for(contador;contador>=0;contador--){
                //Con aritmética de punteros vamos copiando el string de derecha a izquierda. Para eso usamos el asterisco a la izquierda del (puntero + contador)
                //En el primer ciclo copiamos el último caracter de la cadena, pues contador le suma la longitud de la cadena deseada al puntero
                *(destino + contador) = *(origen + contador);
                //En cada ciclo vamos decrementando con el for la variable contador que se va sumando al puntero, de esta forma vamos copiando la cadena
        }

        // NOTA: esto no está hecho con aritmética de punteros pura, ya que usamos una variable entera contador para simular índices que vamos sumando para recorrer las posiciones de memoria.
}


void strAmbos(char *destino, const char *origen){

}

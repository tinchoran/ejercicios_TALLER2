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
   o sea la funci�n no podr�a modificarlos pero, en algunos compiladores tales como GCC
   es posible modificarlos (seg�n K&R el comportamiento es indefinido) */

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

        printf("Se encuentra: %s\n", (strVacio(text1) ? "No vacia" : "Vacia"));

        printf("Largo : %d\n", strLargo(text1));


        strCopia(result, text1);
        printf("Copia : [%s]\n", result);

        strIzq(result, text1);
        printf("Sin blancos a la Izq:");
        puts(result);

        strDer(result, text1);
        printf("Der : [%s]\n", result);

        strAmbos(result, text1);
        printf("Ambos: [%s], sin blancos al principio ni al final.\n", result);

        strMayMin(result, text1, MAYUSCULAS);
        printf("Mayusculas : [%s]\n", result);

        strMayMin(result, text1, MINUSCULAS);
        printf("Minusculas : [%s]\n", result);

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
        *destino = '\0';  //Debemos ponerlo para que c lo interprete como una c�dena v�lida, ya que siempre va al final de una cadena
}

void strIzq(char *destino, const char *origen){
        //Primero debemos inicializar el puntero origen para que apunte al primer caracter que no es un espacio vac�o de la cadena
        //Para eso usamos este while en el que incrementamos el puntero mientras apunte a un caracter de espacio vac�o
        while(*origen == ' ' && *origen != '\0'){
                origen++;
        }
        //Ahora que ya tenemos el puntero "origen" apuntando al primer caracter que no es un espacio vac�o de la cadena, empezamos a copiar la cadena en destino
        while(*origen != '\0'){
                *destino = *origen;
                origen++;
                destino++;
        }
        *destino = '\0'; //Especificamos fin de cadena para que C interprete el arreglo de caracteres como una cadena
}

void strDer(char *destino, const char *origen){
        //Definimos una variable contador que nos servir� para movernos con los punteros sin perder sus valores iniciales y sin crear nuevas variables duplicadas
        int contador = 0;
        //Aumentamos el contador hasta el final de la cadena
        while(*origen != '\0'){
                origen++;
                contador++;
        }
        //Devolvemos a origen a su posici�n inicial ya que la necesitaremos para copiar la string a destino
        origen-=contador;
        //Decrementamos en uno el contador porque est� aumentado hasta el '\0', y queremos evitar eso
        contador--;

        //Es una forma de recorrer de forma inversa, osea de derecha a izquierda. Le vamos sumando el valor de contador
        //en posiciones de memoria hasta que encontremos un caracter que sea distinto de espacios en blanco.
        //Esto nos sirve para posicionar el contador para que guarde el �ndice del primer caracter desde la derecha que no es un espacio en blanco
        while(*(origen + contador) == ' '){
                contador--;
        }
        //Como siempre, no nos olvidamos de colocar en la �ltima direcci�n de memoria del arreglo de caracteres el caracter nulo
        *(destino + contador + 1) = '\0';

        //Con un for vamos decrementando la variable contador para copiar la cadena de derecha a izquierda
        for(contador;contador>=0;contador--){
                //Con aritm�tica de punteros vamos copiando el string de derecha a izquierda. Para eso usamos el asterisco a la izquierda del (puntero + contador)
                //En el primer ciclo copiamos el �ltimo caracter de la cadena, pues contador le suma la longitud de la cadena deseada al puntero
                *(destino + contador) = *(origen + contador);
                //En cada ciclo vamos decrementando con el for la variable contador que se va sumando al puntero, de esta forma vamos copiando la cadena
        }

        // NOTA: esto no est� hecho con aritm�tica de punteros pura, ya que usamos una variable entera contador para simular �ndices que vamos sumando para recorrer las posiciones de memoria.
}

void strAmbos(char *destino, const char *origen){
        //Creamos dos punteros que empiezan apuntando a origen y que nos permitir�n delimitar el incio y el final de la cadena
        char *inicio, *fin;
        inicio = origen;
        fin = origen;

        //  --- Acomodando por derecha
        //Empezamos acomodando el puntero fin en el final de la cadena
        while(*(fin) != '\0'){
                fin++;
        }
        //Decrementamos en uno porque qued� apuntando a \0
        fin--;
        //Decrementamos el puntero hasta encontrar un caracter distinto al espacio en blanco
        while(*(fin) == ' '){
                fin--;
        }

        //  --- Acomodando por izquierda
        //Incrementamos el puntero hasta que apunte al primer caracter distinto a espacio en blanco
        while(*(inicio) == ' '){
                inicio++;
        }


        //  --- Copiando la cadena
        // Usando los punteros ya acomodados comenzamos a copiar la cadena en destno
        while(inicio <= fin){    //Inicio y final como referencia
                *destino = *inicio;  //Copiamos en la direcci�n donde apunta destino el valor del char presente en la direcci�n a la que apunta inicio
                //Por cada ciclo vamos incrementando en 1 los punteros para ir recorriendo la cadena
                inicio++;
                destino++;
        }
        //Cerramos poniendo como �ltimo caracter el caracter nulo como siempre
        *(destino) = '\0';
}

void strMayMin(char *destino, const char *origen, may_min m){
        int diferencia = 32; //32 es la diferencia en la tabla ascii entre una letra min�scula y la misma letra pero en may�scula
        if(m == MAYUSCULAS){

                while(*origen != '\0'){
                        if(*origen >= 'a' && *origen <= 'z'){
                                //Con el if verificamos si la letra es min�scula
                                *destino = *origen - diferencia;    //Una letra may�scula es representada con un n�mero menor en 32 unidades que la misma en min�scula
                        } else {
                                *destino = *origen;
                        }
                        destino++;
                        origen++;
                }
                *destino = '\0';
        } else {

                while(*origen != '\0'){
                        if(*origen >= 'A' && *origen <= 'Z'){
                                //Con el if verificamos si la letra es may�scula
                                *destino = *origen + diferencia;
                        } else {
                                *destino = *origen;
                        }
                        destino++;
                        origen++;
                }
                *destino = '\0';

        }
}

//Reverse no hecho porque a�n no dimos heap

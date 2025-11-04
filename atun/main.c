#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#define tam_nombre 10

typedef struct nodo {
      char nombre[tam_nombre];
      struct nodo *siguiente;
} Nodo;


//       ----   FUNCIONES EXTRA ----
void borrarPantalla(){system("cls");};
void limpiarSaltoDeLinea(char *cadena){
      int longitudString = strlen(cadena);
      if( longitudString > 0 && cadena[longitudString - 1] == '\n' ){
            cadena[longitudString - 1] = '\0';
      }
}



//      ----   FUNCIONES DEL PROGRAMA ----
void inserta(char nombre[], Nodo **punteroConjunto);
void suprime(char nombre[], Nodo **punteroConjunto);
int miembro(char nombre[], Nodo  *punteroConjunto);
void mostrar();


Nodo *lista_chicosMalos = NULL;
Nodo *lista_chicosBuenos = NULL;

int main(){

      int contadorEntradas = 1;
      char mandato, nombre[tam_nombre];
      printf("\n   --  Bienvenido al sistema de gestion de votos de Legisladores -- \n");

      while(mandato != 'E' ){
            printf("\n  -- Indique el voto del Legislador (E) para finalizar: ");
            printf("\n  [F] - Favorable");
            printf("\n  [D] - Desfavorable\n  - ");
            scanf("%c", &mandato);
            fflush(stdin);
            while(mandato != 'E' && mandato != 'F' && mandato != 'D'){
                  printf("\n  --  Opcion invalida. Intente nuevamente");
                  printf("\n  -- Indique el voto del Legislador (E) para finalizar: ");
                  printf("\n  [F] - Favorable");
                  printf("\n  [D] - Desfavorable\n  - ");
                  scanf("%c", &mandato);
            }
            printf("\n  -- Ingrese el nombre del Legislador:  ");
            fgets(nombre, tam_nombre, stdin);

            limpiarSaltoDeLinea(nombre);


            fflush(stdin);

            if(mandato == 'F'){
                  if(miembro(nombre, lista_chicosMalos)){
                        suprime(nombre, &lista_chicosMalos);
                  }
                  if(!miembro(nombre, lista_chicosBuenos)){
                        inserta(nombre, &lista_chicosBuenos);
                  }

            } else if(mandato == 'D'){
                  if(miembro(nombre, lista_chicosBuenos)){
                        suprime(nombre, &lista_chicosBuenos);
                  }
                  if(!miembro(nombre, lista_chicosMalos)){
                        inserta(nombre, &lista_chicosMalos);
                  }
            }

            if((contadorEntradas % 4) == 0){
                  mostrar();
            } else {
                  borrarPantalla();
            }

            contadorEntradas++;
      }

      return 0;
}


void inserta(char nombre[], Nodo **punteroConjunto){
      // El metodo de insertado que uso acá es el de Pila, es decir, al nuevo nodo lo ingreso en el tope de la lista, antes que todos los demas.
      Nodo *nuevoNodo;
      nuevoNodo = (Nodo*) malloc(sizeof(Nodo));

      strcpy(nuevoNodo->nombre, nombre);
      nuevoNodo->siguiente = *punteroConjunto;


      *punteroConjunto = nuevoNodo;

}


void  suprime(char nombre[], Nodo **punteroConjunto){
      //Declaramos dos variables para ir moviendonos en la lista, una que apunte al prórximo nodo y otra que apunte al anterior, para no perder el rastro
      Nodo *aux;
      Nodo *auxAnterior = NULL;
      // La variable de cabecera apunta al primer nodo
      aux = *punteroConjunto;
      // Mientras no encontremos el nombre, nos movemos por la lista. Guardamos primero en auxAnterior el nodo que no es y luego sobreescribimos aux para apuntar al siguiente. Esto lo hacemos porque si tenemos que sacar
      // un nodo debemos tener la posición de memoria del nodo anterior al borrado para enlazarlo con el siguiente luego de eliminar el del medio.
      while( strcmp(nombre, aux->nombre) != 0 ){
            auxAnterior = aux;
            aux  = aux->siguiente;
      }

      //Está la posibilidad de que el primer nodo sea el que tenga el nombre que buscamos, en ese caso debemos actualizar la variable "lista" que apunta al conjunto especificado para que apunte al que será el próximo nodo luego de eliminar este
      if(auxAnterior == NULL){
            *punteroConjunto = aux->siguiente;

      } else {
            auxAnterior->siguiente = aux->siguiente;
      }

      //Liberamos la memoria
      free(aux);
}


int miembro(char nombre[], Nodo *punteroConjunto){
      int flag = 0;
      Nodo *aux;
      aux = punteroConjunto;
      while(!flag && aux != NULL){
            if(strcmp(nombre, aux->nombre) != 0){
                  aux = aux->siguiente;
            } else {
                  flag = 1;
            }
      }
      return flag;
}


void mostrar(){
      Nodo *aux;
      aux = lista_chicosBuenos;
      printf("\n--------------------------------------------------------------  ");
      printf("\n                         CHICOS BUENOS");
      printf("\n--------------------------------------------------------------  ");
      while(aux != NULL){
            printf("\n  - Nombre:  %.10s", aux->nombre);
            aux = aux->siguiente;
      }
      aux = lista_chicosMalos;
      printf("\n--------------------------------------------------------------  ");
      printf("\n                         CHICOS MALOS");
      printf("\n--------------------------------------------------------------  ");
      while(aux != NULL){
            printf("\n  - Nombre:  %.10s", aux->nombre);
            aux = aux->siguiente;
      }
      printf("\n--------------------------------------------------------------  \n");
}








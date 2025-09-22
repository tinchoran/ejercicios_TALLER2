#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


typedef struct {
      int n;
      double *coeficiente;
} Polinomio;

// Crea y retorna un nuevo Polinomio
Polinomio *creaPolinomio(int orden);
// Asigna el n_�simo coeficiente del Polinomio
void setCoef(int n, double c, Polinomio *P);
// Retorna el n_�simo coeficiente del Polinomio
double getCoef(int n, Polinomio * P);
// Calcula el polinomio en x usando: ((�((c[n]*x+c[n-1])*x+c[n-2])*x+ �+c[1]*x)+c[0])
double especializa( double x, Polinomio * P );
// Suma dos Polinomios retorna un nuevo Polinomio con el resultado
Polinomio * sum( Polinomio *p1, Polinomio *p2);
// Multiplica dos Polinomios y retorna un nuevo Polinomio con el resultado
Polinomio * mult( Polinomio *p1, Polinomio *p2);
//Deriva un Polinomio retornando un nuevo Polinomio con el resultado
Polinomio * deriv( Polinomio *p );
// Funci�n est�tica para mostrar un polinomio
void mostrarPolinomio( Polinomio *p);

int main(){

      Polinomio *pc1 = creaPolinomio(4);

      setCoef(4, 5, pc1);
      setCoef(3, 4, pc1);
      setCoef(2, 3, pc1);
      setCoef(1, 2, pc1);
      setCoef(0, 10, pc1);

      Polinomio *pc2 = creaPolinomio(3);
      setCoef(3, 10, pc2);
      setCoef(2, 20, pc2);
      setCoef(1, 5, pc2);
      setCoef(0, 2, pc2);


      printf(" -------------------------------------------------\n");
      printf("   Especializacion de polinomios  ");
      printf(" \n -------------------------------------------------\n");
      printf("  Polinomio:  ");
      mostrarPolinomio(pc2);
      printf("\n  Con x = %.0lf :  %.0lf", 3.0, especializa(3, pc2));


      printf("\n");
      printf(" \n -------------------------------------------------\n");
      printf("   Suma de polinomios  ");
      printf(" \n -------------------------------------------------\n");
      Polinomio *pc3 = sum(pc1, pc2);
      printf("  Polinomios originales: ");
      printf("\n  ");
      mostrarPolinomio(pc1);
      printf("\n  ");
      mostrarPolinomio(pc2);
      printf("\n\n");
      printf("  Polinomio sumado:\n  ");
      mostrarPolinomio(pc3);



      printf("\n");
      printf(" \n -------------------------------------------------\n");
      printf("   Multiplicacion de polinomios  ");
      printf(" \n -------------------------------------------------\n");
      Polinomio *pc4 = mult(pc1, pc2);
      printf("  Polinomios originales: ");
      printf("\n  ");
      mostrarPolinomio(pc1);
      printf("\n  ");
      mostrarPolinomio(pc2);
      printf("\n\n");
      printf("  Polinomio del producto:\n  ");
      mostrarPolinomio(pc4);

      printf("\n");
      printf(" \n -------------------------------------------------\n");
      printf("   Derivacion de polinomios  ");
      printf(" \n -------------------------------------------------\n");
      Polinomio *Dpc1 = deriv(pc1);
      printf("  Polinomio original:  ");
      mostrarPolinomio(pc1);
      printf("\n\n");
      printf("  Polinomio derivado:  ");
      mostrarPolinomio(Dpc1);
      printf("\n");


      return 0;

}

Polinomio *creaPolinomio(int orden){
      // Reservamos memoria en el heap con malloc y devolvemos un puntero que apunta all� donde guardaremos nuestra estructura Polinomio
      Polinomio *pPol = (Polinomio*) malloc(sizeof(Polinomio));
      // Reservamos memoria en el heap para el array double de coeficientes y le asignamos el puntero al atributo coeficiente de la estructura Polinomio creada arriba
      pPol->coeficiente = (double*) malloc(sizeof(double) * (orden+1));
      // Asignamos el orden al atributo n de la estructura creada
      pPol->n = orden;
      // pPol es un puntero que apunta a un trozo de memoria en el heap  que nosotros mismos reservamos y que estar� ocupada hasta que la liberemos. All� se encuentra nuestra estructura
      return pPol;
}

void setCoef(int n, double c, Polinomio *P){
      P->coeficiente[n] = c;
}

double getCoef(int n, Polinomio *P){
      double coef;
      coef = P->coeficiente[n];
      return coef;
}

double especializa( double x, Polinomio * P ){
      // ((�((c[n]*x+c[n-1])*x+c[n-2])*x+ �+c[1]*x)+c[0]  <-- usamos esta formula
      double resultado =  P->coeficiente[P->n];
      int i;
      for( i=P->n-1; i>=0 ; i--){
            resultado =  (resultado * x) + P->coeficiente[i];
      }
      return resultado;
}

Polinomio * sum( Polinomio *p1, Polinomio *p2){

      // En realidad esto es siempre y cuando los coeficientes no se anulen. Habr�a que ir validando la suma de coeficientes para ver  si dan 0. Por ejemplo una suma de dos polinomios de orden  3, en el que el coef.principal de uno es 3x al cubo y el del otro es -3x al cubo. En ese caso el polinomio ser�a de orden 2 si es que los coeficientes de 2 tampoco se anulan y as�.
      // No hago esa validaci�n, almenos por ahora, porque es una complejizaci�n innecesaria
      int ordenNuevoPol = (p1->n >= p2->n)?p1->n:p2->n;


      Polinomio *pPol = (Polinomio*) malloc(sizeof(Polinomio));
      pPol->n = ordenNuevoPol;
      pPol->coeficiente = (double*) malloc(sizeof(double) * (ordenNuevoPol + 1));

      int i;
      double coef1, coef2;
      for(i=0;i<=pPol->n;i++){
            // Validamos que los polinomios tengan �ndice en la posici�n a analizar para no leer afuera del array
            coef1 = (p1->n >= i)?p1->coeficiente[i]:0.0;
            coef2 = (p2->n >= i)?p2->coeficiente[i]:0.0;
            pPol->coeficiente[i] = coef1 + coef2;
      }

      return pPol;
}


Polinomio * mult( Polinomio *p1, Polinomio *p2){
      int ordenNuevoPol = p1->n + p2->n; // El grado de un polinomio resultante de  un producto entre polinomios es la suma de los grados de los polinomios que se multiplican
      Polinomio *pPol = (Polinomio*) malloc(sizeof(Polinomio));
      pPol->n = ordenNuevoPol;
      pPol->coeficiente = (double*) malloc(sizeof(double) * (ordenNuevoPol+1));

      int i,j;
      for (i = 0; i <= ordenNuevoPol; i++) {
            pPol->coeficiente[i] = 0;  // inicializar
      }

      for(i = 0; i <= p1->n; i++){
          for(j = 0; j <= p2->n; j++){
              pPol->coeficiente[i+j] += p1->coeficiente[i] * p2->coeficiente[j];
          }
      }



      return pPol;
}


Polinomio * deriv( Polinomio *p ){
      Polinomio *pPol = (Polinomio*) malloc(sizeof(Polinomio));
      pPol->n = p->n - 1; //Al derivar un polinomio obtenemos un polinomio de grado menor a una unidad al polinomio original
      pPol->coeficiente = (double*) malloc(sizeof(double) * (pPol->n + 1));
      int i = p->n;
      for(i;i>=1;i--){
            pPol->coeficiente[i-1] = (p->coeficiente[i]) * i;
      }

      return pPol;
}


void mostrarPolinomio( Polinomio *p){
      int i = p->n;
      for(i;i>=0;i--){
            printf("%.0lf", getCoef(i, p));
            if(i > 1){
                  printf("(x^%d) + ", i);
            } else if(i == 1){
                  printf("x + ", i);
            }

      }

}


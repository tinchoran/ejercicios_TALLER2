#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


typedef struct {
      int n;
      double *coeficiente;
} Polinomio;

// Crea y retorna un nuevo Polinomio
Polinomio *creaPolinomio(int orden);
// Asigna el n_ésimo coeficiente del Polinomio
void setCoef(int n, double c, Polinomio *P);
// Retorna el n_ésimo coeficiente del Polinomio
double getCoef(int n, Polinomio * P);
// Calcula el polinomio en x usando: ((…((c[n]*x+c[n-1])*x+c[n-2])*x+ …+c[1]*x)+c[0])
double especializa( double x, Polinomio * P );
// Suma dos Polinomios retorna un nuevo Polinomio con el resultado
Polinomio * sum( Polinomio *p1, Polinomio *p2);


int main(){

      Polinomio *pc1 = creaPolinomio(4);
      printf("%p\n", pc1);

      printf("Orden del polinomio %d: [%d]", 1, pc1->n);
      printf("\n");
      setCoef(4, 5, pc1);
      setCoef(3, 4, pc1);
      setCoef(2, 3, pc1);
      setCoef(1, 2, pc1);
      setCoef(0, 10, pc1);
      printf("Coeficiente %d: [%f]", 2, getCoef(2, pc1));
      printf("\n");
      printf("Resultado del polinomio 1 en %d:  [%.2f]", 1, especializa(1, pc1));
      printf("\n");
      Polinomio *pc2 = creaPolinomio(3);
      setCoef(3, 10, pc2);
      setCoef(2, 20, pc2);
      setCoef(1, 5, pc2);
      setCoef(0, 2, pc2);
      printf("Resultado del polinomio 2 en %d:  [%.2f]", 1, especializa(1, pc2));
      printf("\n");
      Polinomio *pc3 = sum(pc1, pc2);
      printf("Resultado del polinomio 3 en %d:  [%.2f]", 1, especializa(1, pc3));

      return 0;

}

Polinomio *creaPolinomio(int orden){
      // Reservamos memoria en el heap con malloc y devolvemos un puntero que apunta allí donde guardaremos nuestra estructura Polinomio
      Polinomio *pPol = (Polinomio*) malloc(sizeof(Polinomio));
      // Reservamos memoria en el heap para el array double de coeficientes y le asignamos el puntero al atributo coeficiente de la estructura Polinomio creada arriba
      pPol->coeficiente = (double*) malloc(sizeof(double) * (orden+1));
      // Asignamos el orden al atributo n de la estructura creada
      pPol->n = orden;
      // pPol es un puntero que apunta a un trozo de memoria en el heap  que nosotros mismos reservamos y que estará ocupada hasta que la liberemos. Allí se encuentra nuestra estructura
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
      double resultado;
      int i;
      for(i = 0; i<=P->n;i++){
            resultado+=(P->coeficiente[i])*x;
      }
      return resultado;
}

Polinomio * sum( Polinomio *p1, Polinomio *p2){
      int ordenNuevoPol = (p1->n >= p2->n)?p1->n:p2->n;
      Polinomio *pPol = (Polinomio*) malloc(sizeof(Polinomio));
      pPol->n = ordenNuevoPol;
      pPol->coeficiente = (double*) malloc(sizeof(double) * (ordenNuevoPol + 1));

      int i;
      for(i=0;i<=pPol->n;i++){
            pPol->coeficiente[i] = p1->coeficiente[i] + p2->coeficiente[i];
      }

      return pPol;
}

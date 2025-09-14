# Ejercicio 2
### Dada la siguiente estructura 
```c
typedef struct { 
    int n; 
    double *coeficiente; 
} Polinomio; 
```

**Que representa a un polinomio de orden n, cuyos n+1 coeficientes c0, c1,…, cn, 
almacenados en el vector apuntado por coeficientes, corresponden a las potencias x0, 
x1, …, xn, cree las siguientes funciones:** 

1. **Crea y retorna un nuevo Polinomio**
```c
Polinomio * creaPolinomio(int orden); 
```  
2. **Asigna el n_ésimo coeficiente del Polinomio**
```c 
void setCoef(int n, double c, Polinomio * P);
```   
3. **Retorna el n_ésimo coeficiente del Polinomio**
```c
double getCoef(int n, Polinomio * P);
```  
4. **Calcula el polinomio en x usando:** ((...((c[n]*x+c[n-1])*x+c[n-2])*x+ ...+c[1]*x)+c[0])
```c  
double especializa( double x, Polinomio * P );
```  
5. **Suma dos Polinomios retorna un nuevo Polinomio con el resultado** 
```c
Polinomio * sum( Polinomio *p1, Polinomio *p2);
```   
6. **Multiplica dos Polinomios y retorna un nuevo Polinomio con el 
resultado**
```c  
Polinomio * mult( Polinomio *p1, Polinomio *p2);
```  
7. **Deriva un Polinomio retornando un nuevo Polinomio con el 
resultado**
```c 
Polinomio * deriv( Polinomio *p );
```  
8. **Libera la memoria asociada con el polinomio**
```c 
void destruyePolinomio( Polinomio *p );
``` 
9. **Busque por el método de bisección un cero de un polinomio dentro 
de un intervalo [a,b], con una precisión dada por épsilon y lo 
retorne**
```c 
double ceropol( Polinomio *p, double a, double b, double epsilon);
```

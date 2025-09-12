# Ejercicio 1 
## Parte 1 
### Dada la siguiente estructura que permite representar tiempos:
```c
typedef struct tiempo{ 
    int anio, mes, dia, hora, minuto, segundo; 
} Tiempo; 
``` 
### Implemente las siguientes funciones:

 
```c
1. int compara_tiempos( Tiempo *t1, Tiempo * t2);
```
**que retorna:** 
|||    
| ----------- | ----------- |
| 1 | si *t1 es anterior a *t2   |
| 0 | si *t1 es igual a *t2      |
| -1 | si *t1 es posterior a *t2 |

```c
2. void imprime_tiempo( Tiempo t );
```
**que imprime el contenido de la estructura t con el siguiente formato:**
 
`"dia/mes/año  hora:minuto:segundo"` (por ejemplo: "3/8/1974 18:23:59"). 

## Parte 2

Para representar un archivo se escogió la siguiente estructura que utiliza la anterior:
```c
typedef struct { 
    char * nombre; 
    Tiempo ultima_mod; 
} Archivo; 
``` 

**Donde:**
+ `nombre` es un cadena de caracteres con el nombre del archivo 
+ `ultima_mod` es una estructura Tiempo que almacena la fecha y hora en que se modificó por última 
vez el archivo

Dado un arreglo lista de n archivos, implemente funciones para 
ordenarlo alfanuméricamente y temporalmente de acuerdo a los siguientes prototipos:

```c
a. void ordena_alfa( Archivo * lista, int n );
```
(utilice la función `strcmp` de la biblioteca *estándar*  para comparar los nombres de 
los archivos al ordenarlos alfabéticamente).  

```c
b. void ordena_temporal(Archivo * lista, int n );
```
(utilice la función `compara_tiempos` para comparar los tiempos de última 
modificación de los archivos).
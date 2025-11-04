# Sociedad para la Prevención de Injusticias con el Atún (SPIA)

La Sociedad para la Prevención de Injusticias con el Atún (SPIA)
mantiene una base de datos que registra los votos más recientes de los
legisladores en asuntos de importancia para los amantes del atún. Desde
el punto de vista conceptual, esta base de datos consta de dos conjuntos
de nombres de legisladores llamados `chicos_buenos` y `chicos_malos`.

La sociedad olvida con facilidad los errores del pasado y, de igual
modo, tiende a olvidar a quienes fueron amigos. Por ejemplo, si se
efectuara una votación para decidir acerca de la prohibición de la pesca
de atún en Puerto Madryn, todos los legisladores que votaran a favor se
incluirían en `chicos_buenos` y se excluirían de `chicos_malos`, y lo
contrario sucedería con los que votaran en contra. Los legisladores que
se abstuvieran permanecerán en el conjunto donde se encontraran, si
estuvieran en alguno.

Cuando está en operación, el sistema de bases de datos acepta tres
mandatos, cada uno representado por un solo carácter, seguido de una
cadena de diez caracteres que denota el nombre de un legislador. Cada
mandato está en una línea aparte. Los mandatos son:

1.  `F` → (sigue el nombre de un legislador con voto favorable)
2.  `D` → (sigue el nombre de un legislador con voto desfavorable)

El proceso termina cuando se lee el carácter `E` en la línea de comando
para señalar el final del proceso.

## Ejercicio

Utilice la estructura dinámica que prefiera para ambas listas.

Al iniciar el sistema, por teclado, se ingresarán voto y nombre como se
explica arriba. Cada cuatro entradas, se deberá mostrar el estado de las
listas para verificar a los `chicos_buenos` y `chicos_malos`.

Al finalizar se actualizarán los archivos de acuerdo a las opciones
votadas.

## Métodos a implementar

-   **inserta(nombre, conjunto)** → recibirá el nombre del legislador y
    el conjunto que corresponda.
-   **suprime(nombre, conjunto)** → recibirá el nombre del legislador y
    el conjunto que corresponda.
-   **miembro(nombre, conjunto)** → recibirá el nombre del legislador y
    el conjunto que corresponda, retornando verdadero/falso si está
    presente o no.
-   **mostrar()** → lee los archivos y los muestra por pantalla.

Puede implementar funciones adicionales si lo cree necesario.

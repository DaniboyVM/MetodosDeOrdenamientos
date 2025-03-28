Metodos de ordenamientos.

Este programa corre 6 metodos de ordenamientos diferenres con el fin de comparar su complejidad algoritmica,
primero ordenamos un arreglo de 10 valores aleatorios y luego le vamos sumando otros 10 valores hasta llegar al 1000, 
todo esto lo haces mil veces en cada intervalo para obtener un promedio.

Todo este proceso es automatico por lo no es necesario que el usuario interactue con el programa, con tan solo abrir el archivo y compilarlo es todo.


-El algoritmo de insercion por orden es un método de ordenamiento que recibe como ´
entrada una sucesion´ s = (s1, s2, . . . , sn) y ordena sus elementos en orden no decreciente
modificando la sucesion original.

-El algoritmo de ordenamiento burbuja (Bubble Sort) es un metodo simple que recorre ´
repetidamente una lista, compara elementos adyacentes y los intercambia si estan en el ´
orden incorrecto. El algoritmo recibe como entrada una sucesion´ s = (s1, s2, . . . , sn) y
ordena sus elementos en orden no decreciente.

 -El algoritmo de ordenamiento por selección (Selection Sort) es un método que divide
 la lista de entrada en dos partes: una sublista ya ordenada y una sublista por ordenar. El
 algoritmo busca repetidamente el elemento mínimo de la parte no ordenada y lo coloca al
 final de la parte ordenada. Recibe como entrada una sucesión s = (s1,s2,...,sn) y ordena
 sus elementos en orden no decreciente.

- El algoritmo deordenamiento por mezcla (MergeSort) es un algoritmo eficiente basado
 en la técnica de “dividir y conquistar”. Divide la lista en mitades recursivamente hasta
 obtener sublistas de tamaño 1, que son trivialmente ordenadas. Luego combina (mezcla)
 estas sublistas para producir nuevas sublistas ordenadas hasta que solo queda una lista
 completa ordenada.

- El algoritmo de ordenamiento rápido (Quick Sort) es un algoritmo eficiente que emplea
 la estrategia de “dividir y conquistar”. Selecciona un elemento como pivote y particiona
 el arreglo alrededor del pivote, colocando todos los elementos menores al pivote a su
 izquierda y todos los mayores a su derecha. Luego, recursivamente ordena los dos sub
arreglos resultantes.

-El algoritmo de ordenamiento Shell (Shell Sort) es una extensión del algoritmo de ordenamiento
por inserción que supera algunas de sus limitaciones al permitir el intercambio de 
elementos distantes. Desarrollado por Donald Shell en 1959, el algoritmo mejora el rendimiento 
del ordenamiento por inserción al ordenar elementos separados por una cierta
distancia (o gap), reduciendo progresivamente esta distancia hasta que el gap sea 1, momento 
en el cual el algoritmo se comporta como el ordenamiento por inserción estándar.
 La idea principal es permitir que los elementos “salten” varias posiciones, haciendo que
 la lista se vuelva “parcialmente ordenada”, lo que hace que el ordenamiento por inserción
 final sea más eficiente.


Con el tiempo promedio que tarda en ordenar un arreglo podemos decir que el algoritmo de ordenamiento
Shell es el mejor.

 

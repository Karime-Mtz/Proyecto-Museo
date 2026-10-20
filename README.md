# Catálogo de Obras para Museos

Este programa funciona como una visita virtual un Museo, en el cuál se lleva se puede realizar un recorrido guiado a través de las salas, en dónde puedes ver la información de las obras que están en cada una de ellas. Se puede buscar una obra por su ID, acceder al catálogo e incluso mantener un registro de tus piezas favoritas.

## SICT0302: Toma Decisiones
#### Algoritmo de Ordenamiento Seleccionado: QuickSort
La cantidad de obras que exhibe un museo puede ir aumentando con el tiempo, por lo que generalmente el catálogo de piezas exhibidas es muy largo. Seleccioné el algoritmo de ordenamiento QuickSort porque no ocupa tanta memoria RAM a diferencia de otros (por ejemplo el MergeSort) y es eficiente con una gran cantidad de datos.

## SICT0301: Evalúa los componentes
#### Complejidad de mis estructuras de datos: 
##### Lista Doble Ligada
Insertar - O(1) (utiliza el puntero *tail)
Buscar - O(n) (recorre cada obra)
##### Árbol Binario de Búsqueda
Insertar y Búsqueda - O(log(n)) (en el peor de los casos es O(n))
##### Algoritmo de Ordenamiento
QuickSort- O(nlogn)

## SICT0303: Implementa acciones científicas
Utilizo cuatro clases: Obra.h, Museo.h, Sala.h, Arbol.h 
Sala.h guarda el código de la lista doble ligada e implementa sus funciones, mientras Arbol.h es la clase que maneja al árbol BST.

## SEG0701: Cultura digital
Utilizo un programa computacional para facilitar el proceso de llevar un inventario y manejar un catálogo.

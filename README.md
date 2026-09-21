# Catálogo de Obras para Museos

Este programa funciona como un inventario de las obras que exhibe un Museo, en el cuál se lleva un registro de la información de cada obra y se puede desplegar un catálogo con las piezas ordenadas por año:
* ID
* Título
* Autor
* Año
* Valor

## SICT0302: Toma Decisiones
#### Algoritmo de Ordenamiento Seleccionado: QuickSort
La cantidad de obras que exhibe un museo puede ir aumentando con el tiempo, por lo que generalmente el catálogo de piezas exhibidas es muy largo. Seleccioné el algoritmo de ordenamiento QuickSort porque no ocupa tanta memoria RAM a diferencia de otros (por ejemplo el MergeSort) y es eficiente con una gran cantidad de datos.

## SICT0301: Evalúa los componentes
#### Complejidad: 
La complejidad del QuickSort es de O(nlogn), es decir funciona cada vez mejor conforme va aumentando la cantidad de datos con los que trabaja.

## SICT0303: Implementa acciones científicas
Utilizo dos clases: Obra.h y Museo.h y un vector que guarda objetos tipo Obra. El programa lee el registro de las obras y lo ordena utilizando el agoritmo QuickSort.

## SEG0701: Cultura digital
Utilizo un programa computacional para facilitar el proceso de llevar un inventario y manejar un catálogo.

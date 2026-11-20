# Catálogo de Obras para Museos

Este programa es la simulación de un Museo con las funciones básicas que puede hacer tanto un Administrador como un Visitante.
Por un lado, el Visitante puede realizar una visita virtual al Museo. En esta visita se puede hacer un recorrido guiado a través de las salas, en dónde puedes ver la información de las obras que están en cada una de ellas. Se puede consultar catálogos que muestran las obras ordenadas por id o por año y también se tiene la opción de llevar una lista de sus obras favoritas.
Por otro lado, el Administrador puede buscar obras por su id, retirar alguna pieza de las exhibiciones y, al igual que el Visitante, puede consultar los catálogos de las obras ordenadas.

## SICT0302: Toma Decisiones
### Justificación de las Estructuras de Datos y del Algoritmo de Ordenamiento

#### Algoritmo de Ordenamiento: QuickSort O(log n)
El algoritmo está presente al mostrar los catálogos ordenados por id o por fecha. La cantidad de obras que exhibe un museo puede ir aumentando con el tiempo, por lo que generalmente el catálogo de piezas exhibidas es muy largo. Seleccioné el algoritmo de ordenamiento QuickSort porque no ocupa tanta memoria RAM y sobre todo porque tiene una complejidad de O(log n). Esto quiere decir que sigue siendo eficiente sin importar la cantidad de obras que sean agregadas al museo.

#### Lista Doble Ligada O(1)
La lista se encarga de guardar las obras y su información para que el Visitante pueda realizar el recorrido de las salas. Como dentro del recorrido se puede ir en dos direcciones, a la siguiente obra o la pasada, fue necesario utilizar una lista doble. Gracias a ella se mantiene una complejidad de O(1), y ya no es necesario volver a recorrer la lista desde el principio cuando el Visitante quiera regresar a la obra anterior.

#### Árbol BST (
El árbol guarda los indices de todas las obras y se ocupa cada vez que el Administrador busca o quita una obra de exhibición. Elegí este tipo de estructura para que fuera mucho más fácil y eficiente acceder a las obras, ya que en la mayoría de los casos su complejidad es O(log n). De esta forma se evita que se tenga que recorrer cada sala y cada una de sus obras.

## SICT0301: Evalúa los componentes
#### Complejidad de mis estructuras de datos: 
##### Lista Doble Ligada
Insertar - O(1) (utiliza el puntero *tail)
Buscar - O(n) (recorre cada obra)
##### Árbol Binario de Búsqueda
Insertar, Búsqueda y Eliminar - O(log(n)) (en el peor de los casos es O(n))
##### Algoritmo de Ordenamiento
QuickSort- O(nlogn)

## SICT0303: Implementa acciones científicas
Utilizo cuatro clases: Obra.h, Museo.h, Sala.h, Arbol.h 
Sala.h guarda el código de la lista doble ligada e implementa sus funciones, mientras Arbol.h es la clase que maneja al árbol BST.

## SEG0701: Cultura digital
Utilizo un programa computacional para facilitar el proceso de llevar un inventario y manejar un catálogo.

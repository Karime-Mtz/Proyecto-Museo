#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "Museo.h"


int main() {
    Museo miMuseo("Museo Nacional", "Mexico");


    miMuseo.registrar_obra(Obra(101, "La Mona Lisa", "Leonardo da Vinci", 1503, 860000000.0f));
    miMuseo.registrar_obra(Obra(102, "El Grito", "Edvard Munch", 1893, 120000000.0f));
    miMuseo.registrar_obra(Obra(103, "La Noche Estrellada", "Vincent van Gogh", 1889, 100000000.0f));
    miMuseo.registrar_obra(Obra(104, "Guernica", "Pablo Picasso", 1937, 200000000.0f));
    miMuseo.registrar_obra(Obra(105, "Nacimiento de Venus", "Sandro Botticelli", 1485, 500000000.0f));

    cout << "\nCatalogo sin ordenar" << endl;
    miMuseo.mostrar_catalogo();

    // Aplicar el algoritmo de sorting
    miMuseo.ordenar_por_anio();

    cout << "\n\nCatalogo ordenado por anio de la obra" << endl;
    miMuseo.catalogo_fechas();

    return 0;
}

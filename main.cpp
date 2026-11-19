#include <iostream>
#include <string>
#include <vector>
#include "Museo.h"

using namespace std;

// Este es el menu principal
char menu_principal() {
    cout << "\n\n   BIENVENIDO AL MUSEO   " << endl;
    cout << "a) Iniciar Recorrido por Salas (Guiado)" << endl;
    cout << "b) Buscar Obra por ID" << endl;
    cout << "c) Ver Catalogos" << endl;
    cout << "d) Ver Favoritos" << endl;
    cout << "e) Salir" << endl;
    cout << "Elige una opcion: ";

    char opcion;
    cin >> opcion;
    cin.ignore();
    return opcion;
}

char menu_catalogos() {
    cout << "\n   Opciones " << endl;
    cout << "a) Ordenado por ano de creacion" << endl;
    cout << "b) Ordenado por mas reciente" << endl;
    cout << "c) Regresar al menu principal" << endl;
    cout << "Elige una opcion: ";

    char opcion;
    cin >> opcion;
    cin.ignore();
    return opcion;
}

int main() {
    Museo miMuseo("Museo Nacional", "Mexico");
    int contador_id = 100;

    miMuseo.cargar_obras("obras.txt", contador_id);
    vector<Obra> mis_favoritos;

    while (true) {
        char choice = menu_principal();

        switch (choice) {
            case 'a': {
                miMuseo.mostrar_salas();
                vector<Sala>& salas = miMuseo.get_salas();

                if (!salas.empty()) {
                    int seleccion;
                    cout << "\nSelecciona el numero de sala a visitar (0 para regresar): ";
                    cin >> seleccion;
                    cin.ignore();

                    if (seleccion > 0 && seleccion <= (int)salas.size()) {
                        salas[seleccion - 1].iniciar_recorrido(mis_favoritos);
                    }
                    if (!mis_favoritos.empty()) {
                        miMuseo.guardar_favoritos("mis_favoritos.txt", mis_favoritos);
                    }
                }
                break;
            }

            case 'b': {
                int id_buscado;
                cout << "\nIngresa el ID de la obra que deseas buscar (100-119): ";
                cin >> id_buscado;
                cin.ignore();

                miMuseo.buscar_obra_por_id(id_buscado);
                break;
            }

            case 'c': {
                miMuseo.mostrar_salas();
                vector<Sala>& salas = miMuseo.get_salas();

                if (!salas.empty()) {
                    int seleccion;
                    cout << "0. Regresar";
                    cin >> seleccion;
                    cin.ignore();

                    if (seleccion > 0 && seleccion <= (int)salas.size()) {
                        char filtro = menu_catalogos();

                        if (filtro == 'a') {
                            salas[seleccion - 1].ordenar_por_anio();
                            salas[seleccion - 1].catalogo_fechas();
                        } else if (filtro == 'b') {
                            salas[seleccion - 1].ordenar_por_reciente();
                            salas[seleccion - 1].mostrar_catalogo();
                        }
                    }
                }
                break;
            }
            case 'd' : {
                miMuseo.mostrar_mis_favoritos();
                break;
            }
            case 'e': {
                cout << "\n¡Gracias por visitar el " << miMuseo.get_nombre() << "! Que tengas un excelente dia." << endl;
                return 0;
            }

            default:
                cout << "\nOpcion no valida. Intenta de nuevo." << endl;
        }
    }

    return 0;
}

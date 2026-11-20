#include <iostream>
#include <string>
#include <vector>
#include "Museo.h"

using namespace std;

// Menu para saber que usuario es
char menu_perfil() {
    cout << "\n\n   BIENVENIDO AL MUSEO DE ARTE  \n" << endl;
    cout << "[1] Visitante" << endl;
    cout << "[2] Administrador" << endl;
    cout << "[0] Salir\n" << endl;
    cout << "Selecciona tu perfil: ";

    char perfil;
    cin >> perfil;
    cin.ignore();
    return perfil;
}

// Menu para Visitante
char menu_visitante() {
    cout << "\n\n   MENU VISITANTE - MUSEO DE ARTE  \n" << endl;
    cout << "[a] Iniciar Recorrido por Salas" << endl;
    cout << "[c] Ver Catalogos" << endl;
    cout << "[d] Ver Favoritos" << endl;
    cout << "[e] Salir\n" << endl;
    cout << "Elige una opcion: ";

    char opcion;
    cin >> opcion;
    cin.ignore();
    return opcion;
}

// Menu para Administrador
char menu_administrador() {
    cout << "\n\n   MENU ADMINISTRADOR - MUSEO DE ARTE  \n" << endl;
    cout << "[b] Buscar Obra por ID" << endl;
    cout << "[c] Ver Catalogos" << endl;
    cout << "[g] Retirar obra de exhibicion" << endl;
    cout << "[e] Salir\n" << endl;
    cout << "Elige una opcion: ";

    char opcion;
    cin >> opcion;
    cin.ignore();
    return opcion;
}

char menu_catalogos() {
    cout << "\nOpciones " << endl;
    cout << "[a] Ordenado por ano de creacion" << endl;
    cout << "[b] Ordenado por ID" << endl;
    cout << "[c] Regresar al menu principal" << endl;
    cout << "Elige una opcion: ";

    char opcion;
    cin >> opcion;
    cin.ignore();
    return opcion;
}

void ver_catalogos(Museo& miMuseo) {
    miMuseo.mostrar_salas();
    vector<Sala>& salas = miMuseo.get_salas();

    if (!salas.empty()) {
        int seleccion;
        cout << "0. Regresar" << '\n';
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
}

int main() {
    Museo miMuseo("Museo de Arte", "Internacional");
    int contador_id = 100;

    miMuseo.cargar_obras("obras.txt", contador_id);
    vector<Obra> mis_favoritos;
    miMuseo.cargar_favoritos("mis_favoritos.txt", mis_favoritos);

    while (true) {
        char perfil = menu_perfil();

        if (perfil == '0') {
            cout << "\nGracias por visitar el " << miMuseo.get_nombre() << endl;
            return 0;
        }

        if (perfil == '1') {
            bool visitante = true;
            while (visitante) {
                char choice = menu_visitante();

                switch (choice) {
                    case 'a': {
                        miMuseo.mostrar_salas();
                        vector<Sala>& salas = miMuseo.get_salas();

                        if (!salas.empty()) {
                            int seleccion;
                            cout << "\nSelecciona el numero de sala a visitar: ";
                            cout << "[0] Regresar" << endl;
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

                    case 'c': {
                        ver_catalogos(miMuseo);
                        break;
                    }

                    case 'd': {
                        miMuseo.mostrar_mis_favoritos();

                        if (!mis_favoritos.empty()) {
                            char resp;
                            cout << "Deseas quitar alguna obra de favoritos?"<< endl;
                            cout << "[s] si" << endl;
                            cout << "[n] no" << endl;
                            cin >> resp;
                            cin.ignore();

                            if (resp == 's' || resp == 'S') {
                                miMuseo.quitar_favorito("mis_favoritos.txt", mis_favoritos);
                            }
                        }
                        break;
                    }

                    case 'e': {
                        visitante = false;
                        break;
                    }

                    default:
                        cout << "\nOpcion no valida. Intenta de nuevo." << endl;
                }
            }
        } else if (perfil == '2') {
            bool admin = true;
            while (admin) {
                char choice = menu_administrador();

                switch (choice) {
                    case 'b': {
                        int id_buscado;
                        cout << "\nIngresa el ID de la obra que deseas buscar (100-127): ";
                        cin >> id_buscado;
                        cin.ignore();

                        miMuseo.buscar_obra_por_id(id_buscado);
                        break;
                    }

                    case 'c': {
                        ver_catalogos(miMuseo);
                        break;
                    }

                    case 'g': {
                        int id_retirar;
                        cout << "\nIngresa el ID de la obra a retirar de exhibicion: ";
                        cin >> id_retirar;
                        cin.ignore();

                        miMuseo.retirar_obra_indice(id_retirar);
                        break;
                    }

                    case 'e': {
                        admin = false;
                        break;
                    }

                    default:
                        cout << "\nOpcion no valida. Intenta de nuevo." << endl;
                }
            }
        } else {
            cout << "\nPerfil no valido. Intenta de nuevo." << endl;
        }
    }

    return 0;
}

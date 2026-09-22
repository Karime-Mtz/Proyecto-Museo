#include <iostream>
#include <string>
#include <vector>

using namespace std;

#include "Museo.h"


// Procedimiento menu
char menu(){

    // Imprime las opciones que se pueden realizar en el programa
    cout << "\nElige una de las siguientes opciones "
        "(a/b/c/d):" 
     << endl;
    cout << "a) Mostrar catalogo" << endl;
    cout << "b) Registrar nueva obra" << endl;
    // cout << "c) Consultar informacion de una obra" << endl;
    cout << "d) Salir\n" << endl;

    char opcion;
    // Lee la opcion que ha sido seleccionada
    cin >> opcion;
    cin.ignore();    
    return opcion;
}

char menu2() {

    cout << "\na) Ordenado por mas reciente" << endl;
    cout << "b) Ordenado por anio" << endl;
    cout << "c) Regresar\n" << endl;

    char opcion;
    // Lee la opcion que ha sido seleccionada
    cin >> opcion;
    cin.ignore();    
    return opcion;
}

Obra crear_obra(int &contador){
    int fecha;
    string titulo, autor;
    float precio;

    cout << "Titulo: ";
    getline(cin, titulo);
    cout << "Autor: ";
    getline(cin, autor);
    cout << "Anio: ";
    cin >> fecha;
    cout << "Precio (numero): ";
    cin >> precio;

    cin.ignore();

    Obra obra_creada(contador, titulo, autor, fecha, precio);
    contador++;
    return obra_creada;
}

int main() {
    Museo miMuseo("Museo Nacional", "Mexico");
    
    int contador_id = 100;

    miMuseo.registrar_obra(Obra(contador_id++,"La Mona Lisa", "Leonardo da Vinci", 1503, 860000000.0f));
    miMuseo.registrar_obra(Obra(contador_id++,"El Grito", "Edvard Munch", 1893, 120000000.0f));
    miMuseo.registrar_obra(Obra(contador_id++, "La Noche Estrellada", "Vincent van Gogh", 1889, 100000000.0f));
    miMuseo.registrar_obra(Obra(contador_id++, "Guernica", "Pablo Picasso", 1937, 200000000.0f));
    miMuseo.registrar_obra(Obra(contador_id++, "Nacimiento de Venus", "Sandro Botticelli", 1485, 500000000.0f));
  
    // Permite realizar varias acciones hasta que se salga del programa
while (true) {
        // Muestra el menu principial y recibe la opcion elegida
        char choice = menu();

        // Ejecuta las funciones de acuerdo a la opcion elegida
        switch (choice) {
            case 'a': {
                bool submenu = true;
                while(submenu) {
                    char filtro = menu2();
                    switch (filtro) {
                        case 'a': { // Opción "Ordenado por más reciente"
                            miMuseo.ordenar_por_reciente();
                            miMuseo.mostrar_catalogo();
                            break;
                        }
                        case 'b': { // Opción "Ordenado por año"
                            miMuseo.ordenar_por_anio();
                            miMuseo.catalogo_fechas(); // o miMuseo.mostrar_catalogo();
                            break;
                        }
                        case 'c' : {
                            cout << "Regresando al menu principal..." << endl;
                            submenu = false;
                            break;
                        }
                        default :
                        cout << "opcion invalida" << endl;
                    }
                }
                break;
            }

            case 'b': {
                Obra nueva_obra = crear_obra(contador_id);
                miMuseo.registrar_obra(nueva_obra);
                cout << "Obra registrada" << endl;
                break;
            }

            case 'c': {
                cout << "hola" << endl;
                }
                break;

            case 'd': {
                // en caso de que el usuario elija una opcion no valida
                cout << "¡Hasta luego!" << endl;
                return 0;
            }

            default:
                cout << "Opcion invalida" << endl;
        }
    }

    return 0;

}

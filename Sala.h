#ifndef SALA_H
#define SALA_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "Obra.h"
using namespace std;

class Sala;

class NodoLista {
    private:
    // este es como el value pero vamos a guardar una obra en cada nodo
        Obra obra;
        NodoLista* next;
        NodoLista* previous;
        
    public:
        NodoLista(Obra val);

        friend class Sala;
};

NodoLista::NodoLista(Obra val) {
    obra = val;
    next = 0;
    previous = 0;
}

class Sala {
    private:
        string nombre_sala;
        NodoLista* head;
        NodoLista* tail;

        vector<Obra> coleccion;

        int particion(int inicio, int fin, string criterio);
        void quick_sort(int inicio, int fin, string criterio);


    public:
        Sala();
        Sala(string);

        string get_nombre_sala() { return nombre_sala; }

        void agregar_obra(const Obra& nueva);
        void iniciar_recorrido(vector<Obra>& favoritos);
        void ordenar_por_anio();
        void ordenar_por_reciente();
        void mostrar_catalogo();
        void catalogo_fechas();
};

Sala::Sala(){
    nombre_sala = "";
    head = 0;
    tail = 0;
}

Sala::Sala(string nombre) {
    nombre_sala = nombre;
    head = 0;
    tail = 0;
}

// Complejidad O(1)
void Sala::agregar_obra(const Obra& nueva) {
    NodoLista* nuevo = new NodoLista(nueva);
    if (head == 0) {
        head = nuevo;
        tail = nuevo;
    } else {
        tail->next = nuevo;
        nuevo->previous = tail;
        tail = nuevo;
    }

    coleccion.push_back(nueva);
}

// Complejidad O(n)
void Sala::iniciar_recorrido(vector<Obra>& favoritos) {
    if (head == 0) {
        cout << "\nLa " << nombre_sala << " no tiene obras registradas aun." << endl;
        return;
    }

    NodoLista* actual = head;
    char opcion;

    cout << "\nHa comenzado tu recorrido en: " << nombre_sala << endl;

    while (actual != 0) {
        cout << "Obra en exhibicion:" << endl;
        actual->obra.mostrar_info_completa();

        cout << "\nOpciones de navegacion:" << endl;
        if (actual->previous != 0) {
            cout << "[a] Obra anterior" << endl;
        }
        if (actual->next != 0) {
            cout << "[s] Siguiente obra" << endl;
        }
        cout << "[f] Guardar en Mis Favoritos" << endl;
        cout << "[x] Salir de la sala" << endl;
        cout << "Elige una opcion: ";
        cin >> opcion;

        if (opcion == 's' || opcion == 'S') {
            if (actual->next != 0) {
                actual = actual->next;
            } else {
                cout << "\nHas llegado al final del recorrido" << endl;
            }
        } else if (opcion == 'a' || opcion == 'A') {
            if (actual->previous != 0) {
                actual = actual->previous;
            } else {
                cout << "\nEstas en la primera obra de la sala." << endl;
            }   
        } else if (opcion == 'f' || opcion == 'F') {
            favoritos.push_back(actual->obra);
            cout << "\n¡\"" << actual->obra.get_titulo() << "\" se agrego a tus favoritos!" << endl;
        } else if (opcion == 'x' || opcion == 'X') {
            cout << "\nSaliendo del recorrido..." << endl;
            break;
        } else {
            cout << "\nOpcion no valida." << endl;
        }
    }
}


// Complejidad O(nlog(n))
int Sala::particion(int inicio, int fin, string criterio) {
// Divide el vector utilizando el anio como pivote
    int i = inicio - 1;

    for (int j = inicio; j < fin; j++) {
        bool condicion = false;
        
        if (criterio == "anio") {
            condicion = (coleccion[j].get_anio() <= coleccion[fin].get_anio());
        } else if (criterio == "reciente") {
            condicion = (coleccion[j].get_id() >= coleccion[fin].get_id());
        }

        if (condicion) {
            i++;
            swap(coleccion[i], coleccion[j]);
        }
    }
    swap(coleccion[i + 1], coleccion[fin]);
    return (i + 1);
}

// Complejidad O(nlog(n))
void Sala::quick_sort(int inicio, int fin, string criterio) {
    if (inicio < fin) {
        int pi = particion(inicio, fin, criterio);
        quick_sort(inicio, pi - 1, criterio);
        quick_sort(pi + 1, fin, criterio);
    }
}

// Complejidad O(nlog(n))
void Sala::ordenar_por_anio() {
    if (!coleccion.size() == 0) {
        quick_sort(0, coleccion.size() - 1, "anio");
    }
}

// Complejidad O(nlog(n))
void Sala::ordenar_por_reciente() {
    if (!coleccion.size() == 0) {
        quick_sort(0, coleccion.size() - 1, "reciente");
    }
}

// Complejidad O(n)
void Sala::mostrar_catalogo() {
    cout << "\nSala: " << nombre_sala << endl;
    if (coleccion.size() == 0) {
    cout << "\nEl catalogo esta vacio." << endl;
    } else {
        for (size_t i = 0; i < coleccion.size(); i++) {
            coleccion[i].mostrar_info_completa();
        }
    }
}

// Complejidad O(n)
void Sala::catalogo_fechas() {
    cout << "\nMuseo: " << nombre_sala << endl;
    if (coleccion.size() == 0) {
    cout << "\nEl catalogo esta vacio." << endl;
    } else {
        for (size_t i = 0; i < coleccion.size(); i++) {
            coleccion[i].mostrar_fechas();
        }
    }
}


#endif

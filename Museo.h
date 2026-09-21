#ifndef MUSEO_H
#define MUSEO_H

#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include "Obra.h"
using namespace std;


class Museo {
    private:
        string nombre;
        string pais;
        vector<Obra> coleccion;

        int particion(int inicio, int fin);
        void quick_sort(int inicio, int fin);

    public:
        Museo();
        Museo(string name, string country);

        string get_nombre();
        string get_pais();

        void set_nombre(string name);
        void set_pais(string country);

        void ordenar_por_anio();
        void registrar_obra(const Obra& nueva);
        void mostrar_catalogo();
        void catalogo_fechas();

};

Museo::Museo(){
    nombre = "";
    pais = "";
}

Museo::Museo(string name, string country){
    nombre = name;
    pais = country;
}

string Museo::get_nombre(){
    return nombre;
}

string Museo::get_pais(){
    return pais;
}

void Museo::set_nombre(string name){
    nombre = name;
}

void Museo::set_pais(string country){
    pais = country;
}

void Museo::registrar_obra(const Obra& nueva){
    // push_back se usa para añadir un nuevo elemento al dinal del vector 
    coleccion.push_back(nueva);
}

// Función de ayuda para dividir el vector utilizando el anio como pivote
int Museo::particion(int inicio, int fin) {
    int pivote = coleccion[fin].get_anio();
    int i = inicio - 1;

    for (int j = inicio; j < fin; j++) {
        if (coleccion[j].get_anio() <= pivote) {
            i++;
            swap(coleccion[i], coleccion[j]);
        }
    }
    swap(coleccion[i + 1], coleccion[fin]);
    return (i + 1);
}

void Museo::quick_sort(int inicio, int fin) {
    if (inicio < fin) {
        int pi = particion(inicio, fin);
        quick_sort(inicio, pi - 1);
        quick_sort(pi + 1, fin);
    }
}

void Museo::ordenar_por_anio() {
    if (!coleccion.empty()) {
        quick_sort(0, coleccion.size() - 1);
    }
}

void Museo::mostrar_catalogo() {
    cout << "\nMuseo: " << nombre << " (" << pais << ")" << endl;
    if (coleccion.size() == 0) {
    cout << "\nEl catalogo esta vacio." << endl;
    } else {
        for (size_t i = 0; i < coleccion.size(); i++) {
            coleccion[i].mostrar_info_completa();
        }
    }
}

void Museo::catalogo_fechas() {
    cout << "\nMuseo: " << nombre << " (" << pais << ")" << endl;
    if (coleccion.size() == 0) {
    cout << "\nEl catalogo esta vacio." << endl;
    } else {
        for (size_t i = 0; i < coleccion.size(); i++) {
            coleccion[i].mostrar_fechas();
        }
    }
}

#endif

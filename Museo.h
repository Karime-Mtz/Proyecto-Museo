#ifndef MUSEO_H
#define MUSEO_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "Obra.h"
#include "Sala.h"
#include "Arbol.h"
using namespace std;


class Museo {
    private:
        string nombre;
        string pais;
        vector<Sala> salas; 
        Arbol arbol_obras;

    public:
        Museo();
        Museo(string name, string country);
        vector<Sala>& get_salas() { return salas; }

        string get_nombre();
        string get_pais();

        void set_nombre(string name);
        void set_pais(string country);

        void cargar_obras(string nombre_archivo, int& contador_id);
        void mostrar_salas();
        void buscar_obra_por_id(int id);
        void retirar_obra_indice(int id);
        void guardar_favoritos(string nombre_archivo, vector<Obra>& favoritos);
        void quitar_favorito(string nombre_archivo, vector<Obra>& favoritos);
        void cargar_favoritos(string nombre_archivo, vector<Obra>& favoritos);
        bool obra_ya_en_favoritos(vector<Obra>& favoritos, int id_obra);

        void mostrar_mis_favoritos();
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

// Complejidad O(n)
void Museo::cargar_obras(string nombre_archivo, int& contador_id) {
    ifstream archivo(nombre_archivo);

    if (!archivo.is_open()) {
        cout << "Error: No se pudo abrir el archivo " << nombre_archivo << endl;
        return;
    }

    string linea;
    while (getline(archivo, linea)) {
        if (linea.empty()) continue;

        stringstream ss(linea);
        string nombre_sala, titulo, autor, str_anio, str_precio;

        getline(ss, nombre_sala, '|');
        getline(ss, titulo, '|');
        getline(ss, autor, '|');
        getline(ss, str_anio, '|');
        getline(ss, str_precio, '|');

        // se usan funciones para convertir strings a numeros
        // string to integer
        int anio = stoi(str_anio);
        // string to float
        float precio = stof(str_precio);

        Obra nueva_obra(contador_id++, titulo, autor, anio, precio);

        arbol_obras.add(nueva_obra);

        int indice_sala = -1;
        for (size_t i = 0; i < salas.size(); i++) {
            if (salas[i].get_nombre_sala() == nombre_sala) {
                indice_sala = i;
                break;
            }
        }

        if (indice_sala == -1) {
            Sala nueva_sala(nombre_sala);
            nueva_sala.agregar_obra(nueva_obra);
            salas.push_back(nueva_sala);
        } else {
            // Si ya existe, agregamos la obra a la Lista Doblemente Ligada de esa sala
            salas[indice_sala].agregar_obra(nueva_obra);
        }
    }

    archivo.close();
    cout << "Archivo " << nombre_archivo << "cargado con exito" << endl;
}

// Complejidad O(n)
void Museo::mostrar_salas() {
    cout << "\nSalas disponibles: "<< endl;
    if (salas.empty()) {
        cout << "No hay salas registradas aún." << endl;
    } else {
        for (size_t i = 0; i < salas.size(); i++) {
            cout << "["<< i + 1 << "] " << salas[i].get_nombre_sala() << endl;
        }
    }
}

// Complejidad O(log(n))
void Museo::buscar_obra_por_id(int id) {
    Obra* resultado = arbol_obras.buscar_por_id(id);

    if (resultado != 0) {
        cout << "\nObra encontrada" << endl;
        resultado->mostrar_info_completa();
        delete resultado;
    } else {
        cout << "\nNo se encontro ninguna obra con el ID: " << id << endl;
    }
}

// Complejidad: O(n)
void Museo::retirar_obra_indice(int id) {
    Obra* encontrada = arbol_obras.buscar_por_id(id);

    if (encontrada == 0) {
        cout << "\nNo se encontro ninguna obra con el ID " << id << " en el indice." << endl;
        return;
    }

    cout << "\nRetirando obra: [" << encontrada->get_id() << "] "
         << encontrada->get_titulo() << endl;
    delete encontrada;

    arbol_obras.remove(id);

    for (size_t i = 0; i < salas.size(); i++) {
        salas[i].fuera_exhibicion(id);
    }

    cout << "La obra ha sido quitada de la exhibicion" << endl;
}

// Complejidad O(n)
void Museo::guardar_favoritos(string nombre_archivo, vector<Obra>& favoritos) {
    ofstream archivo(nombre_archivo);

    if (!archivo.is_open()) {
        cout << "Error: No se pudo crear el archivo de favoritos." << endl;
        return;
    }

    for (size_t i = 0; i < favoritos.size(); i++) {
        archivo << favoritos[i].get_id() << "|"
                << favoritos[i].get_titulo() << "|"
                << favoritos[i].get_autor() << "|"
                << favoritos[i].get_anio() << endl;
    }

    archivo.close();
    cout << "\nLista de favoritos guardada" << endl;
}

// Complejidad O(n)
void Museo::mostrar_mis_favoritos() {
    ifstream archivo("mis_favoritos.txt");

    // Si el archivo no existe o no tiene datos
    string linea;
    bool tiene_contenido = false;

    if (archivo.is_open()) {
        cout << "\n           MIS OBRAS FAVORITAS              \n" << endl;

       while (getline(archivo, linea)) {
            if (!linea.empty()) {
                stringstream ss(linea);
                string id, titulo, autor, anio;
                
                getline(ss, id, '|');
                getline(ss, titulo, '|');
                getline(ss, autor, '|');
                getline(ss, anio, '|');

                cout << "- [" << id << "] " << titulo << " - " << autor << " (" << anio << ")" << endl;
                tiene_contenido = true;
            }
        }
        archivo.close();
    }

    if (!tiene_contenido) {
        cout << "\nAun no tienes obras guardadas en tus favoritos." << endl;
    } else {
        cout <<  endl;
    }
}

// Complejidad: O(n)
void Museo::quitar_favorito(string nombre_archivo, vector<Obra>& favoritos) {
    if (favoritos.empty()) {
        cout << "\nTodavia no tienes ninguna obra en Favoritos" << endl;
        return;
    }

    cout << "\nSelecciona la obra que deseas borrar de Favoritos" << endl;
    for (size_t i = 0; i < favoritos.size(); i++) {
        cout << (i + 1) << ". [" << favoritos[i].get_id() << "] "
             << favoritos[i].get_titulo() << " - "
             << favoritos[i].get_autor() << " (" << favoritos[i].get_anio() << ")" << endl;
    }
    cout << "0. Cancelar" << endl;
    cout << "Elige un numero: ";

    int seleccion;
    cin >> seleccion;
    cin.ignore();

    if (seleccion == 0) {
        cout << "\nOperacion cancelada." << endl;
        return;
    }

    if (seleccion > 0 && seleccion <= (int)favoritos.size()) {
        string titulo_eliminado = favoritos[seleccion - 1].get_titulo();
        favoritos.erase(favoritos.begin() + (seleccion - 1));

        cout << "\nSe quito \"" << titulo_eliminado << "\" de tus favoritos." << endl;
        guardar_favoritos(nombre_archivo, favoritos);
    } else {
        cout << "\nSeleccion no valida." << endl;
    }
}

// Complejidad: O(n^2)
void Museo::cargar_favoritos(string nombre_archivo, vector<Obra>& favoritos) {
    ifstream archivo(nombre_archivo);
    if (!archivo.is_open()) {
        return; // Si aun no existe el archivo, no hay problema
    }

    favoritos.clear();
    string linea;
    while (getline(archivo, linea)) {
        if (linea.empty()) continue;

        stringstream ss(linea);
        string str_id, titulo, autor, str_anio;

        getline(ss, str_id, '|');
        getline(ss, titulo, '|');
        getline(ss, autor, '|');
        getline(ss, str_anio, '|');

        if (str_id.empty() || str_anio.empty()) continue;

        try {
            int id = stoi(str_id);
            int anio = stoi(str_anio);

            if (!obra_ya_en_favoritos(favoritos, id)) {
                Obra* obra_bst = arbol_obras.buscar_por_id(id);
                if (obra_bst != 0) {
                    favoritos.push_back(*obra_bst);
                    delete obra_bst;
                } else {
// Este es un respaldo por si había una obra en favoritos que se quitó de la exhibición
                    Obra obra_respaldo(id, titulo, autor, anio, 0.0f);
                    favoritos.push_back(obra_respaldo);
                }
            }
        } catch (...) {
        }
    }

    archivo.close();
}

// Complejidad: O(n)
bool Museo::obra_ya_en_favoritos(vector<Obra>& favoritos, int id_obra) {
    for (size_t i = 0; i < favoritos.size(); i++) {
        if (favoritos[i].get_id() == id_obra) {
            return true;
        }
    }
    return false;
}


#endif

#ifndef OBRA_H
#define OBRA_H

#include <iostream>
#include <string>
using namespace std;

class Obra {
    private:
        int id;
        string titulo;
        string autor;
        int anio;
        float precio;

    public:
        Obra();
        Obra(int code, string title, string author, int date, float price);
        int get_id();
        string get_titulo();
        string get_autor();
        int get_anio();
        float get_precio();

        void set_id(int code);
        void set_titulo(string title);
        void set_autor(string author);
        void set_anio(int date);
        void set_precio(float price);

        void mostrar_info_completa();
        void mostrar_fechas();
};

Obra::Obra(){
    id = 0;
    titulo = "";
    autor = ""; 
    anio = 0;
    precio = 0.0;
}

Obra::Obra(int code, string title, string author, int date, float price){
    id = code;
    titulo = title;
    autor = author;
    anio = date;
    precio = price;
}

int Obra::get_id(){
    return id;
}

string Obra::get_titulo(){
    return titulo;
}

string Obra::get_autor(){
    return autor;
}

int Obra::get_anio(){
    return anio;
}

float Obra::get_precio(){
    return precio;
}

void Obra::set_id(int code){
    id = code;
}

void Obra::set_titulo(string title){
    titulo = title;
}

void Obra::set_autor(string author){
    autor = author;
}

void Obra::set_anio(int date){
    anio = date;
}

void Obra::set_precio(float price){
    precio = price;
}

void Obra::mostrar_info_completa(){
    cout << "\n\nID: " << id << endl;
    cout << "Titulo: " << titulo << endl;
    cout << "Autor: " << autor << endl;
    cout << "Fecha: " << anio << endl;
    cout << "Valor: $" << precio << endl;
}

void Obra::mostrar_fechas(){
    cout << titulo << "(" << anio << ")" << endl;
}
#endif

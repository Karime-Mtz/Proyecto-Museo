#ifndef ARBOL_H
#define ARBOL_H

#include "Obra.h"
#include <iostream>
using namespace std;

class Arbol;

class NodoBST {
    private:
        Obra obra;
        NodoBST* left;
        NodoBST* right;

    public:
        NodoBST(Obra val);
        void add(Obra val);
        Obra* find(int id_buscado);

        friend class Arbol;
};

NodoBST::NodoBST(Obra val) {
    obra = val;
    left = 0;
    right = 0;
}

// Complejidad O(log n)
// En el peor caso O(n) si el árbol es degenerado
void NodoBST::add(Obra val) {
    if (val.get_id() < obra.get_id()) {
        if (left != 0) {
            left->add(val);
        } else {
            left = new NodoBST(val);
        }
    } else {
        if (right != 0) {
            right->add(val);
        } else {
            right = new NodoBST(val);
        }
    }
}

// Complejidad O(log n)
// En el peor caso O(n).
Obra* NodoBST::find(int id_buscado) {
if (obra.get_id() == id_buscado) {
    return new Obra(obra);
}
if (id_buscado < obra.get_id()) {
    if (left != 0) return left->find(id_buscado);
} else {
    if (right != 0) return right->find(id_buscado);
}
return 0;
}

class Arbol {
    private:
        NodoBST* root;

    public:
        Arbol();

        void add(Obra obra);
        Obra* buscar_por_id(int id_buscado);
};

Arbol::Arbol(){
    root = 0;
}

// Complejidad O(n)
void Arbol::add(Obra val) {
    if (root != 0) {
        root->add(val);
    } else {
        root = new NodoBST(val);
    }
}

// Complejidad O(n)
Obra* Arbol::buscar_por_id(int id_buscado) {
    if (root != 0) {
        return root->find(id_buscado);
    }
    return 0;
}
#endif

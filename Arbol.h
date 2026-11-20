// Justificacion del BST
// Arbol BST: O(log(n))ordena las obras por id, lo utilicé porque al
//   buscar, agregar o eliminar obras evita que se tengan que recorrer todas

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
        NodoBST* predecesor();

    public:
        NodoBST(Obra val);
        void add(Obra val);
        Obra* find(int id_buscado);
        void remove(int id_buscado);

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

NodoBST* NodoBST::predecesor() {
    NodoBST *le, *ri;

    le = left;
    ri = right;

    if (left == 0) {
        if (right != 0) {
            right = 0;
        }
        return ri;
    }

    if (left->right == 0) {
        left = left->left;
        le->left = 0;
        return le;
    }

    NodoBST *parent, *child;
    parent = left;
    child = left->right;
    while (child->right != 0) {
        parent = child;
        child = child->right;
    }
    parent->right = child->left;
    child->left = 0;
    return child;
}

void NodoBST::remove(int id_buscado) {
    NodoBST *succ, *old;

    if (id_buscado < obra.get_id()) {
        if (left != 0) {
            if (left->obra.get_id() == id_buscado) {
                old = left;
                succ = left->predecesor();
                if (succ != 0) {
                    succ->left = old->left;
                    succ->right = old->right;
                }
                left = succ;
                delete old;
            } else {
                left->remove(id_buscado);
            }
        }
    } else if (id_buscado > obra.get_id()) {
        if (right != 0) {
            if (right->obra.get_id() == id_buscado) {
                old = right;
                succ = right->predecesor();
                if (succ != 0) {
                    succ->left = old->left;
                    succ->right = old->right;
                }
                right = succ;
                delete old;
            } else {
                right->remove(id_buscado);
            }
        }
    }
}


class Arbol {
    private:
        NodoBST* root;

    public:
        Arbol();

        void add(Obra obra);
        Obra* buscar_por_id(int id_buscado);
        void remove(int id_buscado);
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

void Arbol::remove(int id_buscado) {
    if (root == 0) return;

    if (root->obra.get_id() == id_buscado) {
        NodoBST* old = root;
        NodoBST* succ = root->predecesor();
        if (succ != 0) {
            succ->left = old->left;
            succ->right = old->right;
        }
        root = succ;
        delete old;
        return;
    }

    root->remove(id_buscado);
}

#endif

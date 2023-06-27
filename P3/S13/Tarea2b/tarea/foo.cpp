#include "foo.h"

void BST::insertarNodo(int dato) {
    raiz = insertarNodoAux(raiz, dato);
}

Nodo* BST::insertarNodoAux(Nodo* nodo, int dato) {
    if (nodo == nullptr)
        return new Nodo(dato);

    if (dato < nodo->valor)
        nodo->left = insertarNodoAux(nodo->left, dato);
    else if (dato > nodo->valor)
        nodo->right = insertarNodoAux(nodo->right, dato);
    return nodo;
}

Nodo* BST::buscarNodo(int dato) {
    return buscarNodoAux(raiz, dato);
}

Nodo* BST::buscarNodoAux(Nodo* nodo, int dato) {
    if (nodo == nullptr || nodo->valor == dato)
        return nodo;

    if (dato < nodo->valor)
        return buscarNodoAux(nodo->left, dato);
    else
        return buscarNodoAux(nodo->right, dato);
}

BST::BST(vector<int> pre_order){
    raiz = nullptr;

    for_each(pre_order.begin(), pre_order.end(), [&](int dato){
        insertarNodo(dato);
    });
}

Nodo* BST::LCA(int x, int y){
    return LCAaux(raiz, x, y);
}

Nodo* BST::LCAaux(Nodo* nodo, int x, int y){
    if(nodo == nullptr)
        return nullptr;
    else if(nodo->valor > x && nodo->valor > y)
        return LCAaux(nodo->left, x, y);
    else if(nodo->valor < x && nodo->valor < y)
        return LCAaux(nodo->right, x, y);
    return nodo;
}

vector<int> BST::camino(int x, int y){
    Nodo* lca = LCA(x, y);
    vector<int> camino;
    if (lca != nullptr){
        Nodo* nodo = buscarNodo(lca->valor);
        while(nodo != nullptr){
            camino.insert(camino.begin(), nodo->valor);
            if(nodo->valor > x)
                nodo = nodo->left;
            else
                nodo = nodo->right;
        }

        nodo = buscarNodo(lca->valor);
        while(nodo != nullptr){
            if (find(camino.begin(), camino.end(), nodo->valor) == camino.end())
                camino.push_back(nodo->valor);

            if(nodo->valor > y)
                nodo = nodo->left;
            else
                nodo = nodo->right;
        }


    }
    return camino;
}
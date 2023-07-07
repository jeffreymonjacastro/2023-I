#include <iostream>

using namespace std;

// Cada nodo del árbol
struct Nodo {
    int dato;
    Nodo* left;
    Nodo* right;

    // Constructor
    Nodo(int dato) {
        this->dato = dato;
        left = nullptr;
        right = nullptr;
    }
};

class BST {
private:
    Nodo* raiz;

    // Función auxiliar para insertar un nodo en el árbol
    Nodo* insertarNodoAux(Nodo* nodo, int dato){
        if (nodo == nullptr)
            return new Nodo(dato);

        if (dato < nodo->dato)
            nodo->left = insertarNodoAux(nodo->left, dato);
        else if (dato > nodo->dato)
            nodo->right = insertarNodoAux(nodo->right, dato);
        return nodo;
    }

    // Función auxiliar para buscar un nodo en el árbol
    Nodo* buscarNodoAux(Nodo* nodo, int dato){
        if (nodo == nullptr || nodo->dato == dato)
            return nodo;

        if (dato < nodo->dato)
            return buscarNodoAux(nodo->left, dato);
        else
            return buscarNodoAux(nodo->right, dato);
    }

public:
    BST(){};

    // Insertar nodo
    void insert(int dato){
        raiz = insertarNodoAux(raiz, dato);
    }

    // Buscar nodo
    Nodo* buscarNodo(int dato){
        return buscarNodoAux(raiz, dato);
    }
};


int main(){
    BST arbol;

    // Insertar nodos en el árbol
    arbol.insert (12);
    arbol.insert (1);
    arbol.insert (26);
    arbol.insert (30);
    arbol.insert (22);
    arbol.insert (10);
    arbol.insert (41);
    arbol.insert (5);
    arbol.insert (21);
    arbol.insert (38);
    arbol.insert (28);
    arbol.insert (20);
    arbol.insert (2);
    arbol.insert (2);
    arbol.insert (7);
    arbol.insert (16);
    arbol.insert (36);
    arbol.insert (44);
    arbol.insert (3);


    // Buscar un nodo en el árbol y luego verificar
    Nodo* nodoBuscado = arbol.buscarNodo(7);

    if (nodoBuscado != nullptr)
        cout << "Nodo encontrado: " << nodoBuscado->dato << endl;
    else
        cout << "Nodo no encontrado" << endl;

    return 0;
}

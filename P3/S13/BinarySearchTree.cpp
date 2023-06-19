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
    Nodo* insertarNodoAux(Nodo* nodo, int dato);
    Nodo* buscarNodoAux(Nodo* nodo, int dato);

public:
    BST(){};
    void insertarNodo(int dato);
    Nodo* buscarNodo(int dato);
};

// Insertar nodo
void BST::insertarNodo(int dato) {
    raiz = insertarNodoAux(raiz, dato);
}

// Función auxiliar para insertar un nodo en el árbol
Nodo* BST::insertarNodoAux(Nodo* nodo, int dato) {
    if (nodo == nullptr)
        return new Nodo(dato);

    if (dato < nodo->dato)
        nodo->left = insertarNodoAux(nodo->left, dato);
    else if (dato > nodo->dato)
        nodo->right = insertarNodoAux(nodo->right, dato);
    return nodo;
}

// Buscar nodo
Nodo* BST::buscarNodo(int dato) {
    return buscarNodoAux(raiz, dato);
}

// Función auxiliar para buscar un nodo en el árbol
Nodo* BST::buscarNodoAux(Nodo* nodo, int dato) {
    if (nodo == nullptr || nodo->dato == dato)
        return nodo;

    if (dato < nodo->dato)
        return buscarNodoAux(nodo->left, dato);
    else
        return buscarNodoAux(nodo->right, dato);
}


int main(){
    BST arbol;

    // Insertar nodos en el árbol
    arbol.insertarNodo(50);
    arbol.insertarNodo(30);
    arbol.insertarNodo(20);
    arbol.insertarNodo(40);
    arbol.insertarNodo(60);

    // Buscar un nodo en el árbol y luego verificar
    Nodo* nodoBuscado = arbol.buscarNodo(70);

    if (nodoBuscado != nullptr)
        cout << "Nodo encontrado: " << nodoBuscado->dato << endl;
    else
        cout << "Nodo no encontrado" << endl;

    return 0;
}
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
    void insertarNodo(int dato){
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
    arbol.insertarNodo(50);
    arbol.insertarNodo(30);
    arbol.insertarNodo(20);
    arbol.insertarNodo(40);
    arbol.insertarNodo(60);

    // Buscar un nodo en el árbol y luego verificar
    Nodo* nodoBuscado = arbol.buscarNodo(20);

    if (nodoBuscado != nullptr)
        cout << "Nodo encontrado: " << nodoBuscado->dato << endl;
    else
        cout << "Nodo no encontrado" << endl;

    return 0;
}
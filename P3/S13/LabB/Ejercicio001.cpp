#include <iostream>

using namespace std;

// Método para hallar el padre de un nodo

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
    Nodo *raiz;

    // Función auxiliar para insertar un nodo en el árbol
    Nodo* insertarNodoAux(Nodo *nodo, int dato) {
        if (nodo == nullptr)
            return new Nodo(dato);

        if (dato < nodo->dato)
            nodo->left = insertarNodoAux(nodo->left, dato);
        else if (dato > nodo->dato)
            nodo->right = insertarNodoAux(nodo->right, dato);
        return nodo;
    }

    // Función auxiliar para buscar un nodo en el árbol
    Nodo* buscarNodoAux(Nodo *nodo, int dato) {
        if (nodo == nullptr || nodo->dato == dato)
            return nodo;

        if (dato < nodo->dato)
            return buscarNodoAux(nodo->left, dato);
        else
            return buscarNodoAux(nodo->right, dato);
    }

    // Función auxiliar para hallar el padre de un nodo
    Nodo* padreAux(Nodo* nodo, int x){
        // Si el nodo que estamos buscando es la raiz, no tiene padre
        // Si el nodo que estamos buscando no existe, no tiene padre
        if (raiz->dato == x || nodo == nullptr)
            return nullptr;

        // Si el nodo que estamos buscando es el hijo izquierdo o derecho del nodo actual, el nodo actual es el padre
        if (nodo->left != nullptr && nodo->left->dato == x)
            return nodo;
        if (nodo->right != nullptr && nodo->right->dato == x)
            return nodo;

        // Si el nodo que estamos buscando es menor que el nodo actual,
        // buscar en el subárbol izquierdo, sino buscamos por el derecho
        if (x < nodo->dato)
            return padreAux(nodo->left, x);
        else
            return padreAux(nodo->right, x);
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

    // Buscar padre
    Nodo* padre(int x){
        return padreAux(raiz, x);
    }
};


int main() {
    BST arbol;
    arbol.insertarNodo(50);
    arbol.insertarNodo(30);
    arbol.insertarNodo(20);
    arbol.insertarNodo(40);
    arbol.insertarNodo(60);
    arbol.insertarNodo(10);
    arbol.insertarNodo(5);

    // Encontrar el padre de 5
    Nodo* padre = arbol.padre(5);
    cout << "El padre de 5 es: " << padre->dato << endl;;

    // Encontrar el padre de 50
    padre = arbol.padre(10);
    if (padre != nullptr)
        cout << "El padre de 50 es: " << padre->dato << endl;
    else
        cout << "El nodo 50 no tiene padre" << endl;
}

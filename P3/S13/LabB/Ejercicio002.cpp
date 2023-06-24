#include <iostream>

using namespace std;

// Método para eliminar un nodo

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
    Nodo *insertarNodoAux(Nodo *nodo, int dato) {
        if (nodo == nullptr)
            return new Nodo(dato);

        if (dato < nodo->dato)
            nodo->left = insertarNodoAux(nodo->left, dato);
        else if (dato > nodo->dato)
            nodo->right = insertarNodoAux(nodo->right, dato);
        return nodo;
    }

    // Función auxiliar para buscar un nodo en el árbol
    Nodo *buscarNodoAux(Nodo *nodo, int dato) {
        if (nodo == nullptr || nodo->dato == dato)
            return nodo;

        if (dato < nodo->dato)
            return buscarNodoAux(nodo->left, dato);
        else
            return buscarNodoAux(nodo->right, dato);
    }

    // Función auxiliar para hallar el sucesor de un nodo
    Nodo *encontrarSucesorAux(Nodo *nodo, int dato) {
        if (nodo == nullptr)
            return nullptr;
        if (nodo->dato <= dato)
            return encontrarSucesorAux(nodo->right, dato);
        else {
            Nodo *sucesor = encontrarSucesorAux(nodo->left, dato);
            if (sucesor == nullptr)
                return nodo;
            else
                return sucesor;
        }
    }

    // Función auxiliar para hallar el padre de un nodo
    Nodo *padreAux(Nodo *nodo, int x) {
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

    // Función auxiliar para eliminar un nodo
    void eliminarAux(Nodo *nodo, int x) {
        if (nodo == nullptr)
            return;

        Nodo *nodo_padre = padre(x);

        // Caso 1: Si el nodo que queremos eliminar es una hoja
        if (nodo->left == nullptr && nodo->right == nullptr) {
            if (nodo_padre == nullptr) {
                raiz = nullptr;
                return;
            }
            if (nodo_padre->left == nodo) {
                nodo_padre->left = nullptr;
            } else {
                nodo_padre->right = nullptr;
            }
            delete nodo;
        }

            // Caso 2: Si el nodo tiene un hijo
        else if (nodo->left == nullptr || nodo->right == nullptr) {
            // Se asigna el hijo del nodo izquierdo
            Nodo *hijo = nodo->left;

            // Si no tiene hijo izquierdo, entonces se asigna el hijo derecho
            if (hijo == nullptr)
                hijo = nodo->right;

            // Si el nodo no tiene padre, entonces el hijo pasa a ser la raiz
            if (nodo_padre == nullptr)
                raiz = hijo;

                // Si el nodo es hijo izquierdo, entonces el nodo padre ahora apunta al nodo hijo
            else if (nodo_padre->left == nodo)
                nodo_padre->left = hijo;

                // Si el nodo es hijo derecho, entonces el nodo padre ahora apunta al nodo hijo
            else
                nodo_padre->right = hijo;
        }

            // Caso 3: El nodo tiene dos hijos
        else {
            Nodo *sucesor = encontrarSucesor(x);
            int dato = sucesor->dato;
            eliminarAux(sucesor, dato);
            nodo->dato = dato;
        }
    }

public:
    BST() {};

    // Insertar nodo
    void insertarNodo(int dato) {
        raiz = insertarNodoAux(raiz, dato);
    }

    // Buscar nodo
    Nodo *buscarNodo(int dato) {
        return buscarNodoAux(raiz, dato);
    }

    // Método para encontrar el sucesor de un nodo
    Nodo* encontrarSucesor(int dato) {
        return encontrarSucesorAux(raiz, dato);
    }

    // Buscar padre
    Nodo *padre(int x) {
        return padreAux(raiz, x);
    }

    // Eliminar un nodo
    void eliminar(int x) {
        return eliminarAux(raiz, x);
    }
};


int main() {
    BST arbol;
    arbol.insertarNodo(50);
    arbol.insertarNodo(30);
    arbol.insertarNodo(20);
    arbol.insertarNodo(40);
    arbol.insertarNodo(60);
    arbol.insertarNodo(70);
    arbol.insertarNodo(10);
    arbol.insertarNodo(5);

    arbol.imprimirPreOrden(); // Salida: 50 30 20 10 5 40 60 70

    arbol.eliminar(5);
    arbol.imprimirPreOrden(); // Salida: 50 30 20 10 40 60 70

}

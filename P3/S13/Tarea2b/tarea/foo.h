#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>


using namespace std;

// Cada nodo del árbol
struct Nodo {
    int valor;
    Nodo* left;
    Nodo* right;

    // Constructor
    Nodo(int dato) {
        this->valor = dato;
        left = nullptr;
        right = nullptr;
    }
};

class BST{
private:
    Nodo* raiz;
    Nodo* insertarNodoAux(Nodo*, int);
    Nodo* buscarNodoAux(Nodo*, int);
    Nodo* LCAaux(Nodo*, int, int);

public:
    BST() = default;
    BST(vector<int>);

    void insertarNodo(int);
    Nodo* buscarNodo(int);

    Nodo* LCA(int, int);
    vector<int> camino(int, int);
};
#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

class Nodo{
    public:
        int valor;
        Nodo* izq;
        Nodo* der;
        Nodo(int valor): valor(valor), izq(nullptr), der(nullptr){}
};

class BST{
public:
    BST();
    BST(vector<int>);
    Nodo* LCA(int, int);
    vector<int> camino(int, int);
};
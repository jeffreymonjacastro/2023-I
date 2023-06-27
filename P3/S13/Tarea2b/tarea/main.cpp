// =============================================================================
// Tarea 2B: Arboles Binarios de Busqueda
// =============================================================================
// 1. Utilizar unicamente los archivos de cabecera y codigo fuente provistos. Es
//    decir: main.cpp, foo.h y foo.cpp.

#include "foo.h"

// Puede validar su codigo con la siguiente funcion main
int main(){
    vector<int> pre_order = {50,30,20,10,25,40,70,60,55,65,80,75,90};
    BST bst(pre_order);

    Nodo* lca1 = bst.LCA(10,40);
    Nodo* lca2 = bst.LCA(55,75);
    Nodo* lca3 = bst.LCA(25,65);
    Nodo* lca4 = bst.LCA(50,10);
    cout << "LCA(10,40) = " << lca1->valor << endl;
    cout << "LCA(55,75) = " << lca2->valor << endl;
    cout << "LCA(25,65) = " << lca3->valor << endl;

    vector<int> camino1 = bst.camino(10,40);
    vector<int> camino2 = bst.camino(55,75);
    vector<int> camino3 = bst.camino(25,65);

    cout << "Camino(10,40) = ";
    for_each(camino1.begin(), camino1.end(), [](int i){cout << i << " ";});
    cout << endl;

    cout << "Camino(55,75) = ";
    for_each(camino2.begin(), camino2.end(), [](int i){cout << i << " ";});
    cout << endl;

    cout << "Camino(25,65) = ";
    for_each(camino3.begin(), camino3.end(), [](int i){cout << i << " ";});
    cout << endl;
}
// No modifique este archivo. Este es el archivo de pruebas que se usara para corregir 
// su tarea. Cualquier cambio realizado sera penalizado con una nota de CERO.

#include "test.hpp"
#include "../tarea/foo.h"

TEST_CASE("parte1", "[Implementacion]"){
    vector<int> pre_order = {50,30,20,10,25,40,70,60,55,65,80,75,90};
    BST bst(pre_order);

    Nodo* lca1 = bst.LCA(10,40);
    Nodo* lca2 = bst.LCA(55,75);   
    Nodo* lca3 = bst.LCA(25,65);
    REQUIRE(lca1 != nullptr);
    REQUIRE(lca2 != nullptr);
    REQUIRE(lca3 != nullptr);

    vector<int> camino1 = bst.camino(10,40);
    vector<int> camino2 = bst.camino(55,75);
    vector<int> camino3 = bst.camino(25,65);

    REQUIRE(camino1.size() > 0);
    REQUIRE(camino2.size() > 0);
    REQUIRE(camino3.size() > 0);
}

TEST_CASE("parte2", "[Ancestro Comun]"){
    vector<int> pre_order = {50,30,20,10,25,40,70,60,55,65,80,75,90};
    BST bst(pre_order);

    Nodo* lca1 = bst.LCA(10,40);
    REQUIRE(lca1->valor == 30);
    
    Nodo* lca2 = bst.LCA(55,75);
    REQUIRE(lca2->valor == 70);
    
    Nodo* lca3 = bst.LCA(25,65);
    REQUIRE(lca3->valor == 50);
}

TEST_CASE("parte3", "[Camino Mas Corto]"){
    vector<int> pre_order = {50,30,20,10,25,40,70,60,55,65,80,75,90};
    BST bst(pre_order);

    vector<int> camino1 = bst.camino(10,40);
    vector<int> camino2 = bst.camino(55,75);
    vector<int> camino3 = bst.camino(25,65);

    REQUIRE(camino1 == vector<int>{10,20,30,40});
    REQUIRE(camino2 == vector<int>{55,60,70,75});
    REQUIRE(camino3 == vector<int>{25,30,50,65});   
}


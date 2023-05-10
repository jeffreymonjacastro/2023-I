// =============================================================================
// Tarea 1a: Matrices Dinamicas, Constructores y Sobrecarga de Operadores
// =============================================================================
// 1. Utilizar unicamente los archivos de cabecera y codigo fuente provistos. Es
//    decir: main.cpp, foo.h y foo.cpp.
// 2. No se permite el uso de librerias adicionales.

#include "foo.h"

// Puede validar su codigo con la siguiente funcion main
int main() {
    Counter C("C:\\Users\\Usuario\\Github\\2023-I\\P3\\s6_chavez\\tarea-1c\\tarea\\document.html");

    // Primer item check
//    cout << C("think");
//    cout << C("bug");
//    cout << C("bugs");

    // Segundo item
    vector<string> rank = C.ranking();


    return 0;
}
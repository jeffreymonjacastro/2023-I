// =============================================================================
// Tarea 1a: Matrices Dinamicas, Constructores y Sobrecarga de Operadores
// =============================================================================
// 1. Utilizar unicamente los archivos de cabecera y codigo fuente provistos. Es
//    decir: main.cpp, foo.h y foo.cpp.
// 2. No se permite el uso de librerias adicionales.

#include "foo.h"

// Puede validar su codigo con la siguiente funcion main
int main() {

//    Counter C(R"(C:\Users\Usuario\Github\2023-I\P3\s6_chavez\tarea-1c\tarea\document.txt)");
    Counter C(R"(../tarea/document.txt)");

    // Primer item check
    cout << C("think") << endl;
    cout << C("bug") << endl;
    cout << C("bugs") << endl;
    cout << C("ilsa") << endl;

    // Segundo item
    vector<string> rank = C.ranking();

    cout << rank[0] << endl;    // ilsa     (con 30 repeticiones)
    cout << rank[1] << endl;    // time     (con 20 repeticiones)
    cout << rank[2] << endl;    // said     (con 18 repeticiones)
    cout << rank[3] << endl;    // russell  (con 16 repeticiones)
    cout << rank[4] << endl;    // still    (con 10 repeticiones)


    return 0;
}
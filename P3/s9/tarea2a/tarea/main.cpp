// =============================================================================
// Tarea 1a: Matrices Dinamicas, Constructores y Sobrecarga de Operadores
// =============================================================================
// 1. Utilizar unicamente los archivos de cabecera y codigo fuente provistos. Es
//    decir: main.cpp, foo.h y foo.cpp.
// 2. No se permite el uso de librerias adicionales.

#include "foo.h"

// Puede validar su codigo con la siguiente funcion main
int main(){
    int N = 1000000;
    vector<double> v(N);

    ifstream file(R"(C:\Users\Usuario\Github\2023-I\P3\s9\tarea2a\data.txt)");

    for(int i=0; i<N; i++){
        file >> v[i];
    }

    file.close();
}
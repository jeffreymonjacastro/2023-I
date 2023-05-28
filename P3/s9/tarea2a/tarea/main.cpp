// =============================================================================
// Tarea 1a: Matrices Dinamicas, Constructores y Sobrecarga de Operadores
// =============================================================================
// 1. Utilizar unicamente los archivos de cabecera y codigo fuente provistos. Es
//    decir: main.cpp, foo.h y foo.cpp.
// 2. No se permite el uso de librerias adicionales.

#include "foo.h"

// Puede validar su codigo con la siguiente funcion main
int main() {
    int N = 1000000;
    vector<double> v(N);

    ifstream file(R"(C:\Users\Usuario\Github\2023-I\P3\s9\tarea2a\data.txt)");

    for (int i = 0; i < N; i++) {
        file >> v[i];
    }

    file.close();

    time_point<system_clock> t_start, t_end;

    t_start = high_resolution_clock::now();

    sort_alg(v.begin(), v.end());

    t_end = high_resolution_clock::now();

//    for (int i = 0; i < N; ++i) {
//        cout << v[i] << endl;
//    }

    if (is_sorted(v.begin(), v.end())) {
        cout << "Ordenado" << endl;
    } else {
        cout << "No ordenado" << endl;
    }

    duration<double, milli> t = t_end - t_start;

    cout << "Tiempo = " << t.count() << " ms" << endl;

    return 0;
}
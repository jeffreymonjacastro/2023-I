// No modifique este archivo. Este es el archivo de pruebas que se usara para corregir 
// su tarea. Cualquier cambio realizado sera penalizado con una nota de CERO.

#include "test.hpp"
#include "../tarea/foo.h"

const int N=1000000;

TEST_CASE("parte1", "[Ordenamiento]"){
    ifstream file("../data.txt");

    vector<double> v(N);
    for(int i=0; i<N; i++){
        file >> v[i];
    }
    file.close();
    chrono::steady_clock::time_point begin, end;

    begin = chrono::steady_clock::now();

    sort_alg(v.begin(), v.end());   

    end = chrono::steady_clock::now();
    chrono::duration<double, milli> t = end - begin;

    REQUIRE(is_sorted(v)==true);
    cout << "T = " << t.count() << " ms" << endl;
}
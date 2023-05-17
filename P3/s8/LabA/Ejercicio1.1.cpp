#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <cassert>

using namespace std;

void sumar(vector<int> A, vector<int> B, vector<int> &C){
    for (int i = 0; i < 10000000; ++i)
        C[i] = A[i] + B[i];
}

void verificarSuma(vector<int> C){
    for (const int e: C)
        assert(e == 3);
}

int main(){
    // Se crea la función chrono::time_point para medir el tiempo de ejecución en base al reloj del sistema
    chrono::time_point<std::chrono::system_clock> t_inicio, t_final;

    vector<int> A(10000000, 1);
    vector<int> B(10000000, 2);
    vector<int> C(10000000);

    t_inicio = chrono::system_clock::now(); // Se obtiene el tiempo de inicio

    sumar(A,B,C);

    t_final = chrono::system_clock::now(); // Se obtiene el tiempo de finalización

    // Esta función chrono::duration es para medir el tiempo que tarda en ejecutarse el programa
    std::chrono::duration<double, std::milli> elapsed_seconds = t_final - t_inicio;

    cout << "Tiempo: " << elapsed_seconds.count() << " ms" << endl;

    verificarSuma(C);

    return 0;
}

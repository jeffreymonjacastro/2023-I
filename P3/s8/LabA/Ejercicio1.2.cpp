#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <cassert>

using namespace std;

void sumar(vector<int> A, vector<int> B, vector<int> &C, int chunk, int chunks){
    int inicio = (chunk) * (A.size() / chunks);
    int fin = (chunk+1) * (A.size() / chunks);

    for (int i = inicio; i < fin; ++i)
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

    t_inicio = chrono::high_resolution_clock ::now(); // Se obtiene el tiempo de inicio

    // Se crean los threads que se particionarán por chunks la tarea de sumar
    thread t1(sumar, A, B, ref(C), 0, 4);
    thread t2(sumar, A, B, ref(C), 1, 4);
    thread t3(sumar, A, B, ref(C), 2, 4);
    thread t4(sumar, A, B, ref(C), 3, 4);

    // Se espera a que los threads terminen su ejecución
    t1.join();
    t2.join();
    t3.join();
    t4.join();

    t_final = chrono::high_resolution_clock::now(); // Se obtiene el tiempo de finalización

    // Esta función chrono::duration es para medir el tiempo que tarda en ejecutarse el programa
    std::chrono::duration<double, std::milli> elapsed_seconds = t_final - t_inicio;

    cout << "Tiempo: " << elapsed_seconds.count() << " ms" << endl;

//    verificarSuma(C);

    return 0;
}

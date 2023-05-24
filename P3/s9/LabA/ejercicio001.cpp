#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <chrono>
#include <cassert>

using namespace std;
using namespace std::chrono; // para las variables de tiempo

mutex mtx; // Clase mutex

void suma_sin_threads(vector<int> A, int& s){
    for (int i : A)
        s += i;
}

void suma_con_threads(vector<int> A, int& s, int chunk, int chunks){
    int inicio = (chunk) * (A.size() / chunks);
    int fin = (chunk+1) * (A.size() / chunks);
    int temp = 0;

    for (int i = inicio; i < fin; ++i)
        temp += A[i];

    mtx.lock();
    s = s + temp;
    mtx.unlock();
}


int main() {
    time_point<system_clock> t_inicio, t_fin;

    int n = 10000000;
    vector<int> vec(n, 1);

    int n_threads = 2;
    vector<thread> vthreads;

    t_inicio = high_resolution_clock::now();

    int sum = 0;

    suma_sin_threads(vec, sum);
//    for (int i = 0; i < n_threads; ++i) {
//        vthreads.push_back(thread(&suma_con_threads, vec, ref(sum), i, n_threads));
//    }
//
//    for (int i = 0; i < n_threads; ++i) {
//        vthreads[i].join();
//    }

    t_fin = high_resolution_clock::now();

    duration<double, milli> time = t_fin - t_inicio;

    cout << "Tiempo: " << time.count() << " ms" << endl;
    cout << "Suma_con_thrads: " << sum << endl;

    assert(sum == n);

    return 0;
}
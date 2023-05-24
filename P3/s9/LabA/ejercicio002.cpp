#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <chrono>
#include <cassert>

using namespace std;
using namespace std::chrono; // para las variables de tiempo

mutex mtx; // Clase mutex


void producto_escalar(vector<int> A, vector<int> B, int& s, int chunk, int chunks){
    int inicio = (chunk) * (A.size() / chunks);
    int fin = (chunk + 1) * (A.size() / chunks);
    int temp = 0;

    for (int i = inicio; i < fin; ++i)
        temp += A[i] * B[i];

    mtx.lock();
    s = s + temp;
    mtx.unlock();

    // Otra forma
//    lock_guard<mutex> lock(mtx);
//    s += temp;
}


int main() {
    time_point<system_clock> t_inicio, t_fin;

    int n = 10000000;
    vector<int> vec1(n, 1);
    vector<int> vec2(n, 1);

    int n_threads = 2;
    vector<thread> vthreads;

    t_inicio = high_resolution_clock::now();

    int sum = 0;

    for (int i = 0; i < n_threads; ++i) {
        vthreads.push_back(thread(&producto_escalar, vec1, vec2, ref(sum), i, n_threads));
    }

    for (int i = 0; i < n_threads; ++i) {
        vthreads[i].join();
    }

    t_fin = high_resolution_clock::now();

    duration<double, milli> time = t_fin - t_inicio;

    cout << "Tiempo: " << time.count() << " ms" << endl;
    cout << "Suma_con_thrads: " << sum << endl;

    assert(sum == n);

    return 0;
}
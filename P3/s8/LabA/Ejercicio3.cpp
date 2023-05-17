#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <cmath>

using namespace std;

bool es_primo(int n) {
    if (n == 2)
        return true;

    for (int i = 2; i < pow(n,0.5); ++i) {
        if (n % i == 0)
            return false;
    }

    return true;
}

void contar_primos(int &count, int inicio, int fin){
    for (int i = inicio; i < fin; ++i) {
        if (es_primo(i))
            count++;
    }
}

int main(){
    chrono::time_point<std::chrono::system_clock> t_inicio, t_final;

    int nthreads = 3;
    int size = pow(2,25);
    int count[4] = {0,0,0,0};

    vector<thread> threads;

    t_inicio = chrono::high_resolution_clock::now();

    for (int i = 0; i < nthreads; i++){
        int inicio = 2 + i * (size / nthreads);
        int fin = 2 + (i + 1) * (size / nthreads);

        threads.push_back(thread(&contar_primos, ref(count[i]), inicio, fin));
    }

    for (int i = 0; i < nthreads; ++i) {
        threads[i].join();
    }

    int c = 0;
    for (int i = 0; i < nthreads; ++i) {
        c += count[i];
    }

    t_final = chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> elapsed_seconds = t_final - t_inicio;
    cout << "Tiempo: " << elapsed_seconds.count() << " ms" << endl;

    cout << c << endl;

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;
using namespace std::chrono;

mutex mtx;

void max_elemento(vector<int> numbers, int& max, int chunk, int chunks){
    int inicio = (chunk) * (numbers.size() / chunks);
    int fin = (chunk+1) * (numbers.size() / chunks);

    int temp = 0;
    for (int i = inicio; i < fin; ++i) {
        if (numbers[i] > temp){
            temp = numbers[i];
        }
    }

    mtx.lock();
    if (temp > max){
        max = temp;
    }
    mtx.unlock();
}

int findMax(const vector<int>& numbers) {
    return *max_element(numbers.begin(), numbers.end());
}

int findMaxParallel(vector<int>& numbers) {
    size_t n_threads = 4;

    int max = 0;
    vector<thread> vthreads;

    for (int i = 0; i < n_threads; ++i) {
        vthreads.push_back(thread(max_elemento, numbers, ref(max), i, n_threads));
    }

    for (int i = 0; i < n_threads; ++i) {
        vthreads[i].join();
    }

    return max;
}

int main(){
//    vector <int> numbers = {9, 12, 4, 7, 1, 18, 3, 5, 10};

    vector <int> numbers(10000000);
    generate(numbers.begin(), numbers.end(), [](){return rand() % 10000;});

    high_resolution_clock::time_point t_inicio, t_final;

//    int Max1 = findMax(numbers);
//    cout << "Elemento Maximo: " << Max1 << endl;

    t_inicio = high_resolution_clock::now();

    int Max2 = findMaxParallel(numbers);
    cout << "Elemento Maximo (Paralelo): " << Max2 << endl;

    t_final = high_resolution_clock::now();

    cout << "Tiempo de ejecucion: " << duration<double, milli>(t_final - t_inicio).count() << " ms" << endl;

    // Tiempo de ejecución sin threads: 140.00 ms aprox.
    // Tiempo de ejecución con threads: 60.00 ms aprox.

    return 0;
}

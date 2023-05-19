#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <cassert>

using namespace std;

float** crearMatriAleatoria(int n){
    float** matriz = new float*[n];
    for(int i = 0; i < n; i++){
        matriz[i] = new float[n];
        for(int j = 0; j < n; j++){
            matriz[i][j] = (float)rand()/RAND_MAX;
        }
    }
    return matriz;
}

void liberarMatriz(float** matriz, int n){
    for(int i = 0; i < n; i++){
        delete[] matriz[i];
    }
    delete[] matriz;
}

// Suma de matrices usando 1 thread
void multiplicacionDeMatrices(float** M1, float** M2, float** M3, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            M3[i][j] = M1[i][j] * M2[i][j];
        }
    }
}

// Suma de matrices usando más threads
void sumaConThreads(float** M1, float** M2, float** M3, int n, int chunk, int chunks){
    int inicio = (chunk) * (n / chunks);
    int fin = (chunk+1) * (n / chunks);

    for(int i = 0; i < n; i++){
        for(int j = inicio; j < fin; j++){
            M3[i][j] = M1[i][j] + M2[i][j];
        }
    }
}

void verificarMatriz(float** M, int n){
    for (int i=0; i < n; i++)
        for (int j=0; j < n; j++)
            assert((M[i][j] - 2) < 0.0001);
}

int main() {
    chrono::time_point<std::chrono::system_clock> t_inicio, t_final;

    int dim = 1000;
    float** A = crearMatrizAleatoria(dim);
    float** B = crearMatrizAleatoria(dim);
    float** C = crearMatrizAleatoria(dim);

    // int n_threads = thread::hardware_concurrency()/2; // Cantidad de núcleos
    int n_threads = 4;

    vector<thread> vthreads; // Vector de threads

    t_inicio = chrono::high_resolution_clock::now();

    // Con solo 1 thread
    // sumaDeMatrices(A, B, C, 1000);

    // Con más threads
    for (int i = 0; i < n_threads; ++i) {
        vthreads.push_back(thread(&sumaConThreads, A, B, C, dim, i, n_threads));
    }

    for (int i = 0; i < n_threads; ++i) {
        vthreads[i].join();
    }

    t_final = chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> elapsed_seconds = t_final - t_inicio;
    cout << "Tiempo: " << elapsed_seconds.count() << " ms" << endl;

    verificarMatriz(C, dim);

    liberarMatriz(A,dim);
    liberarMatriz(B,dim);
    liberarMatriz(C,dim);

    return 0;
}
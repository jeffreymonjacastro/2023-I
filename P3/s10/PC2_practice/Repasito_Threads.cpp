#include <iostream>
#include <vector>
#include <algorithm>
#include <thread>
#include <chrono>
#include <mutex>
#include <future>

using namespace std;
using namespace std::chrono; // Para usar el namespace de chrono

/* TEMAS PC2:
    * Callables y Librería Algorithm
    * Contenedores e Iteradores
    * Complejidad Algoritmica e Invariante de Bucle
    -> Programación Concurrente y Race Condition
*/

/*
    CUARTO TEMA: PROGRAMACIÓN CONCURRENTE Y RACE CONDITION
    -> La concurrencia es la capacidad de un sistema de procesar más de un trabajo al mismo tiempo.
    -> Núcleos (Cores): Los cores están dentros de un procesador y son capaces de ejecutar más de una tarea en paralelo
    -> Hilos (Threads): Algunos procesadores pueden ejecutar múltiples hilos dentro de un mismo núcleo
    -> Task Parallelism: Dividir una tarea en partes y ejecutar cada una en paralelo.
    -> Data Parallelism: Cada thread realizando la misma tarea pero en una distinta porción de los datos.

    LIBRERÍA <chrono>
    + Se usa para medir el tiempo de ejecución de un programa
    + Sintaxis:
        + high_resolution_clock::time_point t1 -> Se declara un objeto de tipo time_point
        + t1 = high_resolution_clock::now() -> Se obtiene el tiempo actual
        + duration<double, milli> t = t2 - t1 -> Se obtiene la diferencia entre dos time_point
        + t.count() -> Se obtiene el tiempo en milisegundos
        + this_thread::sleep_for(seconds(1000)) -> Se duerme el thread por 1 segundos
*/

int fibonacci(int n){
    if (n < 2)
        return 1;
    else
        return fibonacci(n-1) + fibonacci(n-2);
}

void ejemplo001(){
    high_resolution_clock::time_point t_inicio, t_final;

    t_inicio = high_resolution_clock::now();

    cout << fibonacci(40) << endl;

    t_final = high_resolution_clock::now();

    duration<double, milli> t = t_final - t_inicio;

    cout << "Tiempo (ms): " << t.count() << endl;
}

/*
    LIBRERÍA <thread>
    * CMakeList: set(CMAKE_CXX_FLAGS -pthread)
    * En terminal: g++ main.cpp -o out -pthread
    * El main() se considera como el hilo principal

    * Para crear un thread, se debe pasar un callable como parámetro
        * Los demás parámetros serían los parámetros de la función callable
    * Para esperar a que un thread termine, se usa el método .join()
    * El método .detach() permite que el hilo se ejecute en segundo plano y no se puede unir
*/

void suma(vector<int> A, int &suma){
    for (int i = 0; i < A.size(); i++)
        suma += A[i];
}

void ejemplo002(){
    vector<int> A(10000000, 1);
    int suma1 = 0, suma2 = 0;

    // Se define t1 de tipo thread y se le pasa como parámetro la función suma con parámetros A y suma1 por referencia
    thread t1(suma, A, ref(suma1));
    thread t2(suma, A, ref(suma2));

    // Se espera a que los threads terminen
    t1.join();
    t2.join();

    cout << suma1 + suma2 << endl;
}

/*
    RACE CONDITION
    -> Ocurre cuando dos o más hilos acceden a una misma variable y al menos uno de ellos la modifica
    -> Para evitarlo, se usa el mutex (mutual exclusion)


*/

int main(){
    ejemplo002();

    return 0;
}
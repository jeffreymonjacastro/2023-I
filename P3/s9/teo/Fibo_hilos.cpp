#include <iostream>
#include <thread>
#include <future>

using namespace std;

int calcularFibonacci(int n) {
    if (n <= 1)
        return n;
    else {
        // Crear dos promises para los dos cálculos recursivos
        promise<int> promise1;
        promise<int> promise2;

        // Obtener los futures asociados a los promises
        future<int> future1 = promise1.get_future();
        future<int> future2 = promise2.get_future();

        // Crear dos hilos para calcular los dos números de Fibonacci
        thread hilo1([&]() { promise1.set_value(calcularFibonacci(n - 1)); });
        thread hilo2([&]() { promise2.set_value(calcularFibonacci(n - 2)); });

        // Obtener los resultados de los dos cálculos recursivos
        int resultado1 = future1.get();
        int resultado2 = future2.get();

        // Unir los hilos
        hilo1.join();
        hilo2.join();

        // Calcular el número de Fibonacci y devolverlo
        return resultado1 + resultado2;

    }
}


int main() {
    int numero = 20; // Número para calcular la secuencia de Fibonacci

    // Calcular la secuencia de Fibonacci utilizando la función recursiva
    // y "future-promise"
    int resultado = calcularFibonacci(numero);

    // Imprimir el resultado
    cout << "El numero de Fibonacci para " << numero << " es: " << resultado << endl;

    return 0;
}

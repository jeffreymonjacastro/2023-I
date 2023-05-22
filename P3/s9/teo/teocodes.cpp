#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;
using namespace std::chrono; // para las variables de tiempo

int counter = 0;  // Variable global compartida
mutex mtx; // Clase mutex

void incrementar_inseguro() {
    for (int i = 0; i < 100000; ++i) {
        counter++;                      // Incrementar el contador de manera insegura
    }
}

void ejemplo001(){
    // Se ejecutan ambos a la vez y no se sabe el resultado final

    thread thread1(incrementar_inseguro);
    thread thread2(incrementar_inseguro);

    thread1.join();
    thread2.join();

    cout << "Contador: " << counter << endl;
}

// ------------------------------

void incrementar_seguro() {
    for (int i = 0; i < 100000; ++i) {
        lock_guard<mutex> lock(mtx);    // Bloquear el mutex
        counter++;        // Incrementar el contador de manera segura
    }
}

void ejemplo002(){
    // Se ejecuta uno después del otro, el resultado es correcto,
    // pero la idea es que se ejecute en paralelo

    thread thread1(incrementar_seguro);
    thread thread2(incrementar_seguro);

    thread1.join();
    thread2.join();

    cout << "Contador: " << counter << endl;
}

// ------------------------------

void incrementar_correcto(){
    int temp = 0;
    for (int i = 0; i < 100000; ++i) {
        temp++;        // Incrementar una variable interna
    }

    lock_guard<mutex> lock(mtx); // Se bloquea el mutex para sumar correctamente
    counter += temp;
}

void ejemplo003(){
    // Se ejecutan ambos a la vez y se da una pausa para sumar correctamente
    thread thread1(incrementar_correcto);
    thread thread2(incrementar_correcto);

    thread1.join();
    thread2.join();

    cout << "Contador: " << counter << endl;
}

// ------------------------------


int main() {
    ejemplo003();


    return 0;
}

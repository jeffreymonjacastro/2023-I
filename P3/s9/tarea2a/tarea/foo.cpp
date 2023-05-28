#include "foo.h"

// Función para hacer el Heapify de un subárbol en un vector
template <typename RandomIt>
void heapify(RandomIt first, RandomIt last, RandomIt root) {
    auto size = std::distance(first, last);
    auto largest = root;
    auto left = first + 2 * distance(first, root) + 1;
    auto right = first + 2 * distance(first, root) + 2;

    if (left < last && *left > *largest)
        largest = left;

    if (right < last && *right > *largest)
        largest = right;

    if (largest != root) {
        iter_swap(root, largest);
        heapify(first, last, largest);
    }
}

// Función principal de Heap Sort
template <typename RandomIt>
void heapSort(RandomIt first, RandomIt last) {
    auto size = std::distance(first, last);

    // Construir el Heap inicial
    for (auto i = size / 2 - 1; i >= 0; --i)
        heapify(first, last, first + i);

    // Extraer elementos del Heap en orden ascendente
    for (auto i = size - 1; i >= 0; --i) {
        iter_swap(first, first + i);
        heapify(first, first + i, first);
    }
}

void sort_alg(vector<double>::iterator begin, vector<double>::iterator end){
    /*
    TODO: Implementar algoritmo de ordenamiento
    
    [Hint] Separar el vector en 2 partes iguales y ordenar 
           cada parte con un thread diferente. Luego combinar
           las partes ordenadas en un solo vector ordenado.
    */

    thread thread1(heapSort, begin, end);
    thread thread2(heapSort, begin, end);

    thread1.join();
    thread2.join();

    
}


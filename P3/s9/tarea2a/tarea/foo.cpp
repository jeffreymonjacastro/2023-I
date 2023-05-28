#include "foo.h"

void heapify(vector<double>& v, int n, int i){
    int largest = i;
    int l = 2*i + 1; // Left
    int r = 2*i + 2; // Right

    if(l < n && v[l] > v[largest]){
        largest = l;
    }

    if(r < n && v[r] > v[largest]){
        largest = r;
    }

    if(largest != i){
        swap(v[i], v[largest]);
        heapify(v, n, largest);
    }
}

void buildHeap(vector<double>& v, int n){
    for(int i = n/2 - 1; i >= 0; i--){
        heapify(v, n, i);
    }
}


void heapSort(vector<double> &v, int n){
    buildHeap(v, n);

    for(int i = n-1; i >= 0; i--){
        swap(v[0], v[i]);
        heapify(v, i, 0);
    }
}

void sort_alg(vector<double>::iterator begin, vector<double>::iterator end){
    /*
    TODO: Implementar algoritmo de ordenamiento
    
    [Hint] Separar el vector en 2 partes iguales y ordenar 
           cada parte con un thread diferente. Luego combinar
           las partes ordenadas en un solo vector ordenado.
    */

    vector<double> vec1(begin, begin + (end - begin) / 2);
    vector<double> vec2(begin + (end - begin) / 2, end);

    thread thread1(heapSort, ref(vec1), vec1.size());
    thread thread2(heapSort, ref(vec2), vec2.size());

    thread1.join();
    thread2.join();

    merge(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), begin);
}


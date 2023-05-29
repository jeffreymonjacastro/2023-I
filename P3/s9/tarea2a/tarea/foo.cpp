#include "foo.h"

void localSort(vector<double>& arr, int start, int end) {
    int n = end - start + 1;

    // Encuentra el valor máximo en el rango dado
    double maxVal = *max_element(arr.begin() + start, arr.begin() + end + 1);

    // Realiza el ordenamiento Radix Sort en los dígitos decimales

    for (int exp = 1; maxVal / exp > 0; exp *= 10) {

        // Utiliza Counting Sort para ordenar los elementos según el dígito actual

        int countSize = 10;
        vector<int> count(countSize, 0);

        for (int i = start; i <= end; i++) {
            int index = static_cast<int>((arr[i] * n) / exp) % 10;
            count[index]++;
        }

        int sum = 0;
        for (int i = 0; i < countSize; i++) {
            int temp = count[i];
            count[i] = sum;
            sum += temp;
        }

        vector<double> temp(n);

        for (int i = start; i <= end; i++) {
            int index = static_cast<int>((arr[i] * n) / exp) % 10;
            temp[count[index]] = arr[i];
            count[index]++;
        }

        auto copyStart = temp.begin();
        copy(copyStart, copyStart + n, arr.begin() + start);
    }
}



void sort_alg(vector<double>::iterator begin, vector<double>::iterator end){
    /*
    TODO: Implementar algoritmo de ordenamiento
    
    [Hint] Separar el vector en 2 partes iguales y ordenar 
           cada parte con un thread diferente. Luego combinar
           las partes ordenadas en un solo vector ordenado.
    */

    vector<double> arr(begin, end);

    int mid = arr.size() / 2;

    thread t1(localSort, ref(arr), 0, mid);
    thread t2(localSort, ref(arr), mid + 1, arr.size() - 1);

    t1.join();
    t2.join();

    // Combinar los Ordenamientos locales

    copy(arr.begin(), arr.end(), begin);

    inplace_merge(begin, begin + mid + 1,end);

}


#include "foo.h"

void sorting(vector<double>::iterator begin, vector<double>::iterator end){
    sort(begin, end);

    cout<<"Finished"<<endl;
}



void sort_alg(vector<double>::iterator begin, vector<double>::iterator end){
    /*
    TODO: Implementar algoritmo de ordenamiento
    
    [Hint] Separar el vector en 2 partes iguales y ordenar 
           cada parte con un thread diferente. Luego combinar
           las partes ordenadas en un solo vector ordenado.
    */

    thread thread1(sorting, begin, begin + (end - begin) / 2);
    thread thread2(sorting, begin + (end - begin) / 2, end);

    thread1.join();
    thread2.join();
}


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* TEMAS PC2:
    * Callables y Librería Algorithm
    * Contenedores e Iteradores
    -> Complejidad Algoritmica e Invariante de Bucle
    * Programación Concurrente
*/

/*
    TERCER TEMA: COMPLEJIDAD ALGORITMICA E INVARIANTE DE BUCLE
    -> Complejidad Algoritmica: Es la cantidad de recursos que necesita un algoritmo para resolver un problema
        - Tiempo de ejecución
        - Memoria

    -> Invariante de Bucle: Es una condición que se cumple en cada iteración de un bucle
        - Es útil para demostrar la corrección de un algoritmo

    -> Prueba de Correctitud: Es una técnica para demostrar que un algoritmo es correcto
        - Iniciación: El invariante de bucle se debe cumple antes de la primera iteración
        - Mantenimiento: Si el invariante de bucle se cumple antes de un iteración, entonces se debe mantener al final de la iteración
        - Terminación: Al terminar el bucle, el invariante de bucle ayuda a demostrar la correctitud el algoritmo
*/

// EJEMPLO: INSERTION SORT

void insertion_sort(std::vector<int>& v){
    for(int j = 1; j < v.size(); j++){
        int key = v[j];
        int i = j-1;
        while(i >= 0 && v[i] > key){
            v[i+1] = v[i];
            i--;
        }
        v[i+1] = key;
    }
}

void ejemplo001(){
    vector<int> v = {5, 3, 2, 1, 4, 6};

    insertion_sort(v);

    for_each(v.begin(), v.end(), [](int x){cout << x << " ";});
}

// El invariante de bucle es: v[0..j-1] está ordenado en cada iteración del primer bucle for

/*
    -> Notación Big-O: Es una notación matemática que describe el comportamiento de una función cuando el argumento tiende a infinito
        - O(1): Constante -> Operaciones básicas (asignaciones, comparaciones, aritméticas, etc)
        - O(log n): Logarítmica -> Búsqueda binaria
        - O(n): Lineal -> Búsqueda lineal, usar bucles
        - O(n log n): Logarítmica lineal -> Merge Sort, Quick Sort
        - O(n^2): Cuadrática -> Bubble Sort, Insertion Sort, usar bucles anidados
        - O(n^3): Cúbica -> Floyd-Warshall
        - O(2^n): Exponencial -> Fibonacci
        - O(n!): Factorial -> Permutaciones
 */

/*
    BINARY SERACH: Algoritmo logarítimico
*/

void binarySearch(vector<int>& v, int x){
    int start = 0;
    int end = v.size()-1;
    while(start <= end){
        int mid = (start + end)/2;
        if(v[mid] == x){
            cout << "Encontrado en la posición: " << mid << endl;
            return;
        }
        else if(v[mid] < x){
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
    cout << "No encontrado" << endl;
}

void ejemplo002(){
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8};

    binarySearch(v, 5);
}

int main(){
    ejemplo002();

    return 0;
}
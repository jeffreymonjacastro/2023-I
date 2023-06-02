#include <iostream>
#include <vector>

using namespace std;

int encontrarSegundoMinimo(vector<int>& A){
    int min1 = 1e9; // Dos números muy grandes
    int min2 = 1e9;

    // Por cada elemento de A O(n)
    for (int i = 0; i < A.size(); ++i) {
        // Si el elemento Ai es menor al minimo1, entonces ese elemento es el menor
        if (A[i] < min1){
            // El valor que estaba antes en minimo1 ahora para a ser el segundo minimo
            min2 = min1;
            // El nuevo minimo es el elemento Ai
            min1 = A[i];

        // Si el elemento Ai no es menor que el minimo1, pero sí es menor al minimo2, entonces ese elemento es el segundo menor
        } else if (A[i] < min2){
            // El nuevo segundo minimo es el elemento Ai
            min2 = A[i];
        }

        cout << "min1: " << min1 << " min2: " << min2 << endl;
    }

    return min2;
}

/*
 * 1. Describa el Invariante de Bucle.
    El algoritmo sirve para hallar el segundo elemento mínimo de un 
    El invariante de bucle es

    es una propiedad que se cumple en cada iteración del bucle. En este caso, el invariante de bucle es que el minimo1 y minimo2 son los dos menores elementos del vector A[0..i-1].

 * 2. Utilice el Invariante de Bucle para demostrar el algoritmo:
    - Inicialización: ¿El I.B. se cumple en la primera iteración?¿Cómo?
        Answer: El I.B. se cumple en la primera iteración porque el minimo1 y minimo2 son muy grandes, por lo que cualquier elemento de A[i] será menor que ellos.

    - Mantenimiento: Asumiendo que el I.B. se cumple al comenzar la iteración i, ¿Este se mantiene al terminar la iteración?¿Cómo?
        Answer: Si el I.B. se cumple al comenzar la iteración i, entonces el minimo1 y minimo2 son los dos menores elementos de A[0..i-1]. Al terminar la iteración, se compara el elemento A[i] con minimo1 y minimo2. Si A[i] es menor que minimo1, entonces el nuevo minimo1 es A[i] y el nuevo minimo2 es el antiguo minimo1. Si A[i] no es menor que minimo1, pero sí es menor que minimo2, entonces el nuevo minimo2 es A[i]. En ambos casos, el I.B. se mantiene.

    - Terminación: Al terminar el bucle, utilice el I.B. para demostrar el algoritmo.
        Answer: Al terminar el bucle, el I.B. se cumple porque el minimo1 y minimo2 son los dos menores elementos de A[0..n-1], por lo que el algoritmo es correcto.

*/


int main(){
    vector<int> v = {5, 2, 3, 6, 9};
    cout << encontrarSegundoMinimo(v) << endl;

    return 0;
}
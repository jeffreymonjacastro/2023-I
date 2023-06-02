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
    El algoritmo sirve para hallar el segundo elemento mínimo de un conjunto de enteros. Para lograrlo, el algoritmo itera a través del conjunto para buscar el elemento mínimo y asignarlo a la variable min1. Luego, si encuentra otro elemento mínimo, el número que estaba almacenado en min1 pasa a ser el segundo mínimo (min2) y el min1 será denuevo el menor elemento. Este proceso lo realiza en O(n), ya que debe recorrer cada uno de los elementos del arreglo.

    Por lo tanto, el invariante de bucle es que, en cada iteración, la variable min1 y min2 son el primer y segundo elemento mínimo respectivamente para la secuencia A[0...i-1] a partir de la segunda iteración, ya que para que existan dos mínimos, debe haber como mínimo 2 elementos en el conjunto.

 * 2. Utilice el Invariante de Bucle para demostrar el algoritmo:
    - Inicialización: ¿El I.B. se cumple en la primera iteración?¿Cómo?
        Answer: El I.B. se cumple en la segunda iteración, ya que se necesitan como mínimo 2 elementos en el conjunto para que existan los dos menores. Además, el minimo1 y minimo2 son muy grandes, por lo que cualquier elemento de A[i] será menor que ellos.

    - Mantenimiento: Asumiendo que el I.B. se cumple al comenzar la iteración i, ¿Este se mantiene al terminar la iteración?¿Cómo?
        Answer: Como el I.B. se cumple al comenzar la iteración i, entonces el minimo1 y minimo2 son los dos menores elementos de A[0..i-1]. En cada iteración, si encuentra otro elemento mínimo A[i], el número que estaba almacenado en min1 pasa a ser el segundo mínimo (min2) y el min1 será denuevo el menor elemento A[i]. Por lo que el I.B se mantiene.

    - Terminación: Al terminar el bucle, utilice el I.B. para demostrar el algoritmo.
        Answer: Al terminar el bucle, el I.B. se cumple porque el minimo1 y minimo2 son los dos menores elementos de el conjunto entero A[0..n-1], por lo que se confirma la correctitud del algoritmo.
*/


int main(){
    vector<int> v = {5, 2, 3, 6, 9};
    cout << encontrarSegundoMinimo(v) << endl;

    return 0;
}
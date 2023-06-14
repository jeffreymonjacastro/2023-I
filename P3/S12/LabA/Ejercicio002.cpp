#include <iostream>
#include <stack>

using namespace std;

string decimalABinario(int decimal) {
    stack<int> pila;

    while (decimal > 0) {
        int bit = decimal % 2;
        pila.push(bit);
        decimal /= 2;
    }

    string resultado;
    while (!pila.empty()) {
        resultado += to_string(pila.top());
        pila.pop();
    }

    return resultado;
}

int main() {
    int decimal = 42;
    string binario = decimalABinario(decimal);
    cout << decimal << " -> " << binario << endl;
    // Salida: 42 -> 101010

    return 0;
}
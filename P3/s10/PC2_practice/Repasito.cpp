#include <iostream>

// Función para calcular el inverso multiplicativo utilizando el algoritmo de Euclides extendido
int euclideanExtendedAlgorithm(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    int x1, y1;
    int gcd = euclideanExtendedAlgorithm(b, a % b, x1, y1);

    x = y1;
    y = x1 - (a / b) * y1;

    return gcd;
}

// Función para encontrar el inverso multiplicativo de 'a' módulo 'mod'
int findMultiplicativeInverse(int a, int mod) {
    int x, y;
    int gcd = euclideanExtendedAlgorithm(a, mod, x, y);

    if (gcd != 1) {
        throw std::runtime_error("El inverso multiplicativo no existe.");
    }

    return (x % mod + mod) % mod;
}

int main() {
    int a = 7;
    int mod = 26;

    try {
        int inverse = findMultiplicativeInverse(a, mod);
        std::cout << "Inverso multiplicativo de " << a << " módulo " << mod << " es: " << inverse << std::endl;
    } catch (const std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}

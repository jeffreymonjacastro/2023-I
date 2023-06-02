#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Transformer {
    string modo;
    int n;

    Transformer(string s, int x): modo(s), n(x){};

    void operator()(int& x){
        if(modo == "SUMAR")
            x += n;
        else if(modo == "RESTAR")
            x -= n;
        else if(modo == "MULTIPLICAR")
            x *= n;
        else if(modo == "DIVIDIR")
            x /= n;
    }
};

void modificar_matriz(int** M, Transformer& T){
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3 ; ++j) {
            T(M[i][j]);
        }
    }
}

void print(int** M){
    for (int i = 0; i < 3; ++i) {
        for_each(M[i], M[i] + 3, [](int x){cout << setw(3) << x << " ";});
        cout << endl;
    }
}

int main(){
    int ** M = new int *[3];
    for ( int i = 0; i < 3; i ++)
        M [ i ] = new int [3];

    M [0][0] = 1; M [0][1] = 2; M [0][2] = 3;
    M [1][0] = 4; M [1][1] = 5; M [1][2] = 6;
    M [2][0] = 7; M [2][1] = 8; M [2][2] = 9;

    cout << "Original: "<< endl;
    print(M);
    cout << endl;

    cout << "Suma: "<< endl;
    Transformer transformer1("SUMAR" , 3) ; // Paso 1
    modificar_matriz(M, transformer1) ; // Paso 2
    print(M) ; // Paso 3
    cout << endl;

    cout << "Resta: "<< endl;
    Transformer transformer2("RESTAR", 1);
    modificar_matriz(M, transformer2);
    print(M);
    cout << endl;

    cout << "Multiplicacion: "<< endl;
    Transformer transformer3("MULTIPLICAR", 2);
    modificar_matriz(M, transformer3);
    print(M);
    cout << endl;

    cout << "Division: "<< endl;
    Transformer transformer4("DIVIDIR", 3);
    modificar_matriz(M, transformer4);
    print(M);
    cout << endl;

    // Implemente los tres pasos para cada transformacion
    for ( int i = 0; i < 3; i ++)
        delete [] M [ i ];
    delete [] M ;
}
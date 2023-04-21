#include <iostream>

using namespace std;

// Especializacion de la sobrecarga
template<class T>
string Tipo1(T a){
    return "No es puntero.";
}

template<class T>
string Tipo1(T* a){
    return "Es puntero.";
}

template<>
string Tipo1(int* a){
    return "Es puntero 'int'.";
}

// Especializacion de la funcion plantilla original
template<class T>
string Tipo2(T a){
    return "No es puntero.";
}

template<>
string Tipo2(int* a){
    return "Es puntero 'int'.";
}

template<class T>
string Tipo2(T* a){
    return "Es puntero.";
}



int main(){
    float x1;
    cout << Tipo1(x1) << endl;
    cout << Tipo2(x1) << endl;

    float *x2;
    cout << Tipo1(x2) << endl;
    cout << Tipo2(x2) << endl;

    int *x3;
    cout << Tipo1(x3) << endl;
    cout << Tipo2(x3) << endl;

    return 0;
}
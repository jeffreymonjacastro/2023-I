#include <iostream>

using namespace std;

// Crear una variable dentro de esa función
template<typename T>
T input(string s) {
    T r;
    cout << s;
    cin >> r;

    return r;
}

int main(){
    int x = input<int>("Ingrese x:");
    string s = input<string>("Ingrese s:");

    cout<<x;
    cout<<s;
}
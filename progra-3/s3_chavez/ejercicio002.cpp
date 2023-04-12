#include <iostream>

using namespace std;

// Función platilla
template<class T>
T foo(T x, int n) {
    T sum = 1;

    for (int i = 1; i < n; ++i) {
        sum += i * x;
    }

    return sum;
}

int main(){
    // La variable x puede tener diferentes tipos

    float x = 3.14;
    int n = 20;

    cout<<foo(x,n)<<endl;


    return 0;
}
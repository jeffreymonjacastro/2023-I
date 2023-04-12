#include <iostream>

using namespace std;

// El template genera que la función foo reciba multiples tipos
template<class T1, class T2, class T3>

// El tipo de dato que regresa T1 depende del tipo que se envía como primer parámetro
T1 foo(T1 x, T2 y, T3& z){
    z = x/y;
    return x * y;
}

int main() {
    float x = 1.1;
    int y = 2;
    float z;
    float s = foo(x, y, z);

    cout << "prod= "<< s<< endl;
    cout << "div= "<<z<<endl;

    return 0;
}
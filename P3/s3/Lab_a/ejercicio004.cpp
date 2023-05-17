#include <iostream>

using namespace std;

template<typename T>
class Numeros {
private:
    T _a;
    T _b;

public:
    Numeros(T a, T b): _a(a), _b(b){};

    T suma(){return _a + _b;}

    T resta(){return _a - _b;}

    T mult(){return _a * _b;}

    T div(){return _a / _b;}

    void mostrar(){
        cout<<"suma: "<<suma()<<endl;
        cout<<"resta: "<<resta()<<endl;
        cout<<"mult: "<<mult()<<endl;
        cout<<"div: "<<div()<<endl;
    }

    ~Numeros() = default;
};

int main(){
    // Para las clases plantilla, se les debe especificar el tipo del template
    Numeros<int> obj(2,3);
    obj.mostrar();

    Numeros<double> obj2(2.1, 3.2);
    obj2.mostrar();


    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

//typedef long long int lli;

// Función polimórfica
template<typename T1, typename T2>
T1 suma(T1 a, T2 b){
    return a + b;
}

// Clases polimórficas
template<typename T>
class Poligono {
private:
    T base;
    T altura;
public:
    Poligono(T a, T b): base(a), altura(b){}

    void print(){
        cout << base << " " << altura <<endl;
    }
};

int main(){
//    cout << suma(3, 4.4) << endl;
//    cout << suma(4.5, 1) << endl;


    Poligono<string> p1("2.2", "3.3");

    p1.print();


}
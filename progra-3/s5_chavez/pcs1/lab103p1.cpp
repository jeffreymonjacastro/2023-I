#include <iostream>
#include <ctime>

using namespace std;

class Polinomio {
private:
    int grado = 0;
    int* coeficientes = nullptr;
public:
    Polinomio(int n){
        grado = n;
        coeficientes = new int[n+1]{5, 2,3,1};

//        srand(time(nullptr));
//
//        for (int i = 0; i <= n; ++i) {
//            coeficientes[i] = rand()%20 -10;
//        }
    }

    friend ostream& operator<<(ostream& os, const Polinomio& p);
};

ostream& operator<<(ostream& os, const Polinomio& p){
    for (int i = p.grado; i > 0; i--) {
        if (p.coeficientes[i] != 0) {
            if (p.coeficientes[i - 1] > 0) {
                os << p.coeficientes[i] << "x^" << i << " +";
            } else if (p.coeficientes[i - 1] < 0) {
                os << p.coeficientes[i] << "x^" << i << " ";
            } else if (p.coeficientes[i-1] == 0){
                os << p.coeficientes[i] << "x^" << i << " ";
            }
        } else {
            if (p.coeficientes[i-1] > 0 && p.coeficientes[i-1] != p.coeficientes[0]){
                os << " +";
            } else if (p.coeficientes[i-1] < 0 && p.coeficientes[i-1] != p.coeficientes[0]) {
                os << " ";
            }
        }
    }

    if (p.coeficientes[0] != 0)
        os << p.coeficientes[0];


    return os;
}

int main(){
    Polinomio pol1(3);

    cout<<pol1;

    return 0;
}
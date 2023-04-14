#include <iostream>
#include <ctime>

using namespace std;

template<int n = 2, typename T = int>
class Polinomio{
public:
    void print(){
        for(int i=n; i >= 0; i--){
            T r = rand() % 1000 - 500;
            r /= 10;
            if (r == 0){
                continue;
            } else if (i == n) {
                cout<< r << "x^" << i;
            } else if (r > 0) {
                cout << '+' << r;

                if (i > 0) {
                    cout<< "x^" << i;
                }
            } else {
                cout << r;
                if (i > 0) {
                    cout<<"x^"<<i;
                }
            }
        }
    }
};

int main(){
    srand(time(NULL));
    Polinomio<4, float> pol1;
    pol1.print();

    cout<<endl;

    Polinomio<> pol2;
    pol2.print();
}
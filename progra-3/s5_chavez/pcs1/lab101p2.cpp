#include <iostream>
#include <ctime>

using namespace std;

template<typename T = int>
class MatVector {
private:
    int length = 0;
    T* container = nullptr;
public:
    MatVector(int n){
        length = n;
        container = new T[n];

        srand(time(nullptr));

        for (int i = 0; i < n; ++i)
            container[i] = (rand()%100) / 10.0;
    }

    T operator[](size_t n){
        return container[n];
    }

    template<typename T2, typename T3>
    friend double operator*(MatVector<T2>& mt1, MatVector<T3>& mt2);

    template<typename T1>
    friend ostream& operator<<(ostream& os, const MatVector<T1>& mt);
};

template<typename T2, typename T3>
double operator*(MatVector<T2>& mt1, MatVector<T3>& mt2){
    double sum = 0;

    if (mt1.length == mt2.length) {
        for (int i = 0; i < mt1.length; ++i) {
            sum += mt1[i] * mt2[i];
        }

        return sum;
    }

    return 0;
}


template<typename T1>
ostream& operator<<(ostream& os, const MatVector<T1>& mt){
    os << "[ ";

    for (int i = 0; i < mt.length; ++i) {
        os << mt.container[i];
        if (i < mt.length - 1) {
            os << " ";
        };
    }

    os << " ]";

    return os;
}


int main(){
    MatVector<> v1(4);
    MatVector<float> v2(4);

    cout<< v1 <<endl;
    cout<< v1[2] <<endl;

    cout<< v2 <<endl;

    cout<<v1*v2<<endl;

    return 0;
}
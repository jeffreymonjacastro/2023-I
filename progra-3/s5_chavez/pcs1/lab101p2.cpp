#include <iostream>

using namespace std;

template<typename T = int>
class MatVector {
private:
    int length = 0;
    T* container = new T[length];
public:
    MatVector(int n){
        for (int i = 0; i < n; ++i)
            container[i] = (rand()%100) / 10;
    }

    template<typename T1>
    friend ostream& operator<<(ostream& os, const MatVector<T1>& mt);
};

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

    cout<< v1 <<endl;

    return 0;
}
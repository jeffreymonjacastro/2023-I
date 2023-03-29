#include <iostream>
#include <cmath>

using namespace std;

class Vector3D {
private:
    float* ptr;

public:
    Vector3D(){
        ptr = new float[3];
        for(int i = 0; i < 3; i++){
            ptr[i] = 0;
        }
    };

    Vector3D(float x, float y, float z){
        ptr = new float[3];
        ptr[0] = x;
        ptr[1] = y;
        ptr[2] = z;
    }

    ~Vector3D(){
        delete[] ptr;
        ptr = nullptr;
    }

    float modulo(){
        return sqrt(ptr[0]*ptr[0] + ptr[1]*ptr[1] + ptr[2]*ptr[2]);
    }

    friend ostream &print(ostream&, const Vector3D&);

    // Se hace la clase amiga a Matriz2D para que esta pueda acceder a los atributos del vector
    friend class Matriz2D;
};


class Matriz2D {
private:
    int n;
    int m;
    int** ptr;
public:
    Matriz2D(const Vector3D& obj, int k){
        n = 3;
        m = k;

        ptr = new int*[n];
        for(int i = 0; i < n; i++){
            ptr[i] = new int[m];
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                ptr[i][j] = ptr
            }
        }
    }
};

ostream &print(ostream& os, const Matriz2D& item){
    for(int i = 0; i < item.n; i++){
        for(int j = 0; j < item.m; j++){
            os << item.ptr[i][j] << " ";
        }

        os << endl;
    }

    return os;
}


int main(){
    Vector3D obj1(7,2,3);
    Matriz2D obj2(obj1, 9);
    print(cout, obj2);
}
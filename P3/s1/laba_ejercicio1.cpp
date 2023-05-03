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
};

// Función auxiliar que es amiga de la clase para imprimir los datos de la clase
ostream &print(ostream& os, const Vector3D& item){
    for(int i = 0; i < 3; i++){
        os << item.ptr[i] << " ";
    }

    os << endl;
    return os;
}

int main(){
    Vector3D obj1(1, 2, 3);
    print(cout, obj1);
    cout << "Modulo: " << obj1.modulo() << endl;

    Vector3D obj2;
    print(cout, obj2);
    cout << "Modulo: " << obj2.modulo() << endl;


    return 0;
}
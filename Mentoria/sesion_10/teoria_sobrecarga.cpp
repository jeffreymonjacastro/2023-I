#include <iostream>
#include <fstream>

using namespace std;

/* SOBRECARGA DE OPERADORES

 + La sobrecarga de operadores permite que un operador tenga diferentes significados en diferentes contextos.
 + Se realiza mediante la definición de una función que se llama cuando se utiliza el operador.
 + Existen 2 tipos operadores que se pueden sobrecargar:
    - Operadores unarios: operan sobre un solo operando.
        Por ejemplo: operador de incremento (++) y decremento (--).

    - Operadores binarios: operan sobre dos operandos.
        Por ejemplo: operador de suma (+) y resta (-).

 + Existen 3 formas de declarar una sobrecarga de operadores:
    - Funciones miembro (método de una clase)
    - Funciones amigas (friend)
    - Funciones globales (con atributos públicos o getters)

 Sintaxis:
 Tipo_retorno operator op (parámetros){
    // Código
 }

*/

class Vector3D {
private:
    int x,y,z;
public:
    Vector3D() = default;
    Vector3D(int _x, int _y, int _z): x(_x), y(_y), z(_z){}
    // Sobrecarga de operador en función amiga (friend)
    // friend Vector3D operator+(Vector3D& v1, Vector3D& v2);

    Vector3D operator++(){
        Vector3D newvector;

        newvector.x = this->x + 1;
        newvector.y = this->y + 1;
        newvector.z = this->z + 1;

        return newvector;
    }

    Vector3D operator+(Vector3D& v2){
        Vector3D newvector;

        newvector.x = v2.x + this->x;
        newvector.y = v2.y + this->y;
        newvector.z = v2.z + this->z;

        return newvector;
    }

    friend ostream& operator<<(ostream& os, Vector3D& v);

    Vector3D operator-(Vector3D& v1){
        Vector3D newvector(x - v1.x, y - v1.y, z- v1.z);
        return newvector;
    }

    int operator*(){
        return x + y + z;
    }

    friend Vector3D operator+=(Vector3D& v1, Vector3D& v2);
};

Vector3D operator+=(Vector3D& v1, Vector3D& v2){
    v1 = v1 + v2;
    return v1;
}

ostream& operator<<(ostream& os, Vector3D& v){
    os << "[" << v.x << ", " << v.y << ", " << v.z << "]" << endl;

    return os;
}


// Sobrecarga de operador + en función global
//Vector3D operator+(Vector3D& v1, Vector3D& v2){
//    Vector3D newvector;
//
//    newvector.x = v1.x + v2.x;
//    newvector.y = v1.y + v2.y;
//    newvector.z = v1.z + v2.z;
//
//    return newvector;
//}


int main(){
    Vector3D v1(1,1,1);
    Vector3D v2(2,2,2);
    Vector3D v3 = v1 + v2;
    Vector3D v4;
    v4 = ++v1;

    Vector3D v5 = v1 - v3;

    cout << v1;
    cout << v2;
    cout << v3;
    cout << *v4;
    cout << v5;

    v1 += v2;

    cout << v1;

//===========================

    string richtext;

    ifstream doc("../tarea/document.txt", ios::in);

    if (doc.is_open()) {
        string linea;

        while (getline(doc, linea))
            richtext += linea + " ";

        doc.close();

    } else {
        cout << "No se pudo abrir el archivo" << endl;
    }
}

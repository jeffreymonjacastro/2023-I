#include <iostream>

using namespace std;

class Matriz2D {
private:
    int n;
    int m;
    int** ptr;

public:
    // Constructor de asignación
    Matriz2D(int n, int m): n(n), m(m){
        // Crear matriz dinamica (ptr) de n filas
        ptr = new int*[n];

        // Crear cada fila de la matriz dinamica (ptr de m columnas
        for(int i = 0; i < n; i++){
            ptr[i] = new int[m];
        }

        // Inicializar la matriz dinamica (ptr) con numeros aleatorios entre 0 y 9
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                ptr[i][j] = rand()%10;
            }
        }
    };

    // Constructor por defecto (3x3)
    Matriz2D(): n(3), m(3){
        ptr = new int*[3];

        for(int i = 0; i < n; i++){
            ptr[i] = new int[3];
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                ptr[i][j] = rand()%10;
            }
        }
    };

    // Constructor con un dato (n)
    Matriz2D(int n): n(n), m(n){
        ptr = new int*[n];

        for(int i = 0; i < n; i++){
            ptr[i] = new int[n];
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                ptr[i][j] = rand()%10;
            }
        }
    };

    // Destructor
    ~Matriz2D(){
        for(int i = 0; i < n; i++){
            delete [] ptr[i];
        }

        delete[] ptr;
        ptr = nullptr;
    }

    friend ostream &print(ostream&, const Matriz2D&);
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
    Matriz2D obj1(2,3);
    print(cout, obj1);
    cout << endl;

    Matriz2D obj2(5);
    print(cout, obj2);
    cout << endl;

    Matriz2D obj3;
    print(cout, obj3);
}
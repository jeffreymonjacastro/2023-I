#include <iostream>

using namespace std;

class Matriz2D {
private:
    int n;
    int m;
    int** ptr;

public:
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

    ~Matriz2D(){
        for(int i = 0; i < n; i++){
            delete [] ptr[i];
        }

        delete[] ptr;
        ptr = nullptr;
    }

    friend ostream &print(ostream&, const Matriz2D&);
};

int main(){
    Matriz2D obj1(2,3);
    print(cout, obj1);
    cout << obj1;
}
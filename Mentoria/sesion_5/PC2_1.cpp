#include <iostream>
#include <ctime>

using namespace std;

int** crearMatriz(int n, int m){
    int** matrix = new int*[n];
    for (int i = 0; i < n; ++i) {
        matrix[i] = new int[m];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            matrix[i][j] = rand()%99 + 1;
        }
    }

    return matrix;
}

void imprimirMatriz(int** matrix, int n, int m){
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void liberarMatriz(int** matrix, int n){
    for (int i = 0; i < n; ++i) {
        delete [] matrix[i];
    }

    delete [] matrix;
    matrix = nullptr;
}

int main(){
    srand(time(nullptr));

    int a, n, m;
    int** matrix = nullptr;

    while (true){
        cout << "MENU :\n"
                "1. Generar matriz aleatoria con numeros entre 1 y 99.\n"
                "2. Detectar los multiplos de 3.\n"
                "3. Salir."<<endl;

        cout << "Opcion: "; cin>>a;

        if (a == 3) {
            liberarMatriz(matrix, n);

            break;
        } else if (a == 1){
            cout<< "#Filas: "; cin>>n;
            cout<< "#Columnas: "; cin>>m;

            matrix = crearMatriz(n, m);

            imprimirMatriz(matrix, n, m);

            cout << endl;
        } else if (a == 2){
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    if (matrix[i][j] % 3 == 0)
                        cout << matrix[i][j] << " ";
                    else
                        cout << 0 << " ";
                }

                cout << endl;
            }
        }
    }

    return 0;
}
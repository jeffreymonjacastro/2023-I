#include <iostream>
#include <iomanip>

using namespace std;

int** declararMatriz(int n, int m){
    int** M = new int*[n];

    for (int i = 0; i < n; ++i) {
        M[i] = new int[m];
    }

    return M;
}

void definirMatriz(int** matrix, int n, int m){
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            matrix[i][j] = rand()%9 + 1;
        }
    }
}

void imprimirMatriz(int** matrix, int n, int m){
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << setw(3) << matrix[i][j];
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
    int n, m;
    cin >> n >> m;

    int** Matrix = declararMatriz(n,m);

    definirMatriz(Matrix, n, m);

    imprimirMatriz(Matrix, n, m);

    liberarMatriz(Matrix, n);







//    int n = 2, m = 3;

//    int matrix1[2][3] = {1,2,3,4,5,6};
//
//    for (int i = 0; i < 3; ++i) {
//        for (int j = 0; j < 3; ++j) {
//            cout << matrix1[i][j] << " ";
//        }
//        cout<<endl;
//    }

//    int** matrix = new int*[n];
//
//    for (int i = 0; i < n; ++i) {
//        matrix[i] = new int[m];
//    }
//
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < m; ++j) {
//            matrix[i][j] = 5;
//            cout << matrix[i][j] << " ";
//        }
//        cout<<endl;
//    }
//
//    for (int i = 0; i < n; ++i) {
//        delete [] matrix[i];
//    }
//
//    delete [] matrix;

    return 0;
}
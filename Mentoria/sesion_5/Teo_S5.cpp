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


int** sumaMatrices(int** M1, int** M2, int n, int m){
    int** sum = new int*[n];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            sum[i][j] = M1[i][j] + M2[i][j];
        }
    }

    return sum;
}

int** transpuesta(int** M, int n, int m){
    int** transp = new int*[m];
    for (int i = 0; i < n; ++i) {
        transp[i] = new int[n];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            transp[j][i] = M[i][j];
        }
    }

    return transp;
}



int** multipliMatrices(int** M1, int**M2, int n, int m){
    int** multi = new int*[n];
    for (int i = 0; i < n; ++i) {
        multi[i] = new int[n];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            multi[i][j] = 0;
            for (int k = 0; k < m; ++k) {
                multi[i][j] += M1[i][k] * M2[k][i];
            }
        }
    }

    return multi;
}

int main(){
    int n, m;
    cin >> n >> m;

    int** Matrix1 = declararMatriz(n,m);

//    int** Matrix2 = declararMatriz(n,m);
//
    definirMatriz(Matrix1, n, m);
//    definirMatriz(Matrix2, n, m);
//
    imprimirMatriz(Matrix1, n, m);

    int** transp = transpuesta(Matrix1, n, m);
    imprimirMatriz(transp, n,m);

//    cout<<endl;
//    imprimirMatriz(Matrix2, n, m);
//    cout<<endl;
//
//    int** result = multipliMatrices(Matrix1,Matrix2,n,m);
//
//    imprimirMatriz(result, n, m);
//
//    liberarMatriz(Matrix1, n);
//    liberarMatriz(Matrix2, n);
//    liberarMatriz(result, n);







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
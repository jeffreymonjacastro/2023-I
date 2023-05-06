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
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }

    cout << endl;
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
    for (int i = 0; i < m; ++i) {
        transp[i] = new int[n];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            transp[j][i] = M[i][j];
        }
    }

    return transp;
}

int** multipliMatrizTranspuesta(int** M1, int n, int m){
    int** multi = new int*[n];
    for (int i = 0; i < n; ++i) {
        multi[i] = new int[n]{};
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < m; ++k) {
                multi[i][j] += M1[i][k] * M1[k][j];
            }
        }
    }

    return multi;
}

int main(){
//    int n = 2, m = 3;

    int matrix1[2][3] = {1,2,3,4,5,6};

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << matrix1[i][j] << " ";
        }
        cout<<endl;
    }

    int** matrix = new int*[n];

    for (int i = 0; i < n; ++i) {
        matrix[i] = new int[m];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            matrix[i][j] = 5;
            cout << matrix[i][j] << " ";
        }
        cout<<endl;
    }

    for (int i = 0; i < n; ++i) {
        delete [] matrix[i];
    }

    delete [] matrix;

// =====================================

    int n, m;
    cin >> n >> m;

    int** Matrix1 = declararMatriz(n,m);

    definirMatriz(Matrix1, n, m);

    imprimirMatriz(Matrix1, n, m);

    int** transp = transpuesta(Matrix1, n, m);
    imprimirMatriz(transp, m,n);

    int** result = multipliMatrizTranspuesta(Matrix1,n,m);
    imprimirMatriz(result, n, n);

    liberarMatriz(Matrix1, n);
    liberarMatriz(transp, n);
    liberarMatriz(result, n);








    return 0;
}
#include <iostream>
#include <vector>
#include <ctime>
#include <iomanip>

using namespace std;

/* PRIMERA PREGUNTA DE PC2 */


vector<int> generarVector(int n){
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        v[i] = rand()%99 + 1;
    }
    return v;
}

void imprimirVector(vector<int>& v){
    for(auto i:v){
        cout << i << " ";
    }
    cout << endl;
}

int promedioVector(vector<int>& v){
    int sum = 0;

    for(auto i: v){
        sum += i;
    }

    return sum/v.size();
}


int main(){
    srand(time(nullptr));

    vector<int> v1 = generarVector(20);

    imprimirVector(v1);

    cout << promedioVector(v1) << endl;

    vector<int> v2, v3;

    for (auto i:v1){
        if (i % 2 == 0)
            v2.push_back(i);
        else
            v3.push_back(i);
    }

    imprimirVector(v2);
    imprimirVector(v3);

    return 0;
}




/* SEGUNDA PREGUNTA DE PC2 */

int** crearMatriz(int n){
    srand(time(nullptr));

    int** M = new int*[n];

    for (int i = 0; i < n; ++i) {
        M[i] = new int[n];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            M[i][j] = rand()%50 + 1;

            cout << setw(5) << M[i][j];
        }
        cout << endl;
    }

    return M;
}

void liberarMatrix(int** M, int n){
    for (int i = 0; i < n; ++i) {
        delete [] M[i];
    }

    delete [] M;
    M = nullptr;
}


int main(){
    int n;

    while (true) {
        cout << "Filas [mayor que 2]: " << endl;
        cin >> n;

        if (n > 2)
            break;
    }

    int** matrix = crearMatriz(n);

    vector<int> diagonales;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j)
                diagonales.push_back(matrix[i][j]);
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if ((i+j) == n-1)
                diagonales.push_back(matrix[i][j]);
        }
    }

    cout << "Vector:" << endl;

    for (int i : diagonales)
        cout << i << " ";


    liberarMatrix(matrix, n);

    return 0;
}
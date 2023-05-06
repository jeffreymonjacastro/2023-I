#include <iostream>
#include <iterator>

using namespace std;



int main() {
//
//    int matrix1[2][2];
//    int matrix2[3][3] = {};
//    int matrix3[][3] = {0};
//  int matrix4[2][2] = {1,2,3,4};
//  int matrix5[2][2] = {{1,2}, {3,4}};

    int** matrix2 = new int*[2]{new int[2]{1,2}, new int[2]{3}};

    int** matrix = nullptr;
    matrix = new int*[3];

    for (int i = 0; i < 3; ++i)
        matrix[i] = new int[3];

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j)
            matrix[i][j] = 3;
    }

    for (int i = 0; i < 3; ++i)
        delete[] matrix[i];

    delete [] matrix;




    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            cout << matrix2[i][j] << " ";
        }
        cout << endl;
    }

}



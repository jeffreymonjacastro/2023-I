// Pawn on a Grid

#include <iostream>

using namespace std;

int main(){
    int H, W, sum = 0;
    string x;
    cin>>H>>W;

    char matrix[H][W];

    for (int i = 0; i < H; ++i) {
        cin>>x;

        for (int j = 0; j < W; ++j) {
            matrix[i][j] = x[j];
        }
    }

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (matrix[i][j] == '#')
                sum += 1;
        }
    }

    cout<<sum;

    return 0;
}

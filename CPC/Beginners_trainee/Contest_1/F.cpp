// ACSII Art

#include <iostream>

using namespace std;

int main(){
    int H, W, x;
    cin>>H>>W;

    char matrix[H][W];

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin>>x;

            if (x == 0)
                matrix[i][j] = '.';
            else {
                x += 64;

                matrix[i][j] = x;
            }
        }
    }

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cout<<matrix[i][j];
        }

        cout<<endl;
    }


    return 0;
}
#include <iostream>

using namespace std;


// Algoritmo para hallar la suma de los dos números máximos de una lista de números
int main(){
    int n, x, maxi1 = -1e9, maxi2 = -1e9;
    cin>>n;

    for (int i = 0; i < n; ++i) {
        cin>>x;

        if (x >= maxi1){
            maxi2 = maxi1;
            maxi1 = x;
        } else if (x > maxi2) {
            maxi2 = x;
        }
    }

    cout<< maxi1 + maxi2<<endl;

    return 0;
}
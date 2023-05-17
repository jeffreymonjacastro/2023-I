#include <iostream>

using namespace std;

template<typename T>

void BubbleSort(T a[], int n){
    int right = n-1;
    T temp = 0;

    while(right > 0){
        int k = 0;

        for (int i = 0; i < right; ++i) {
            if(a[i+1] < a[i]){
                temp = a[i+1];
                a[i+1] = a[i];
                a[i] = temp;
                k = i;
            }
        }

        right = k;
    }
}

int main(){

    int array[5] = {5, 3, 4, 2, 1};

    for (auto i:array) {
        cout<< i << " ";
    }

    cout<<endl;
    BubbleSort(array, 5);

    for (auto i:array) {
        cout<< i <<" ";
    }
}
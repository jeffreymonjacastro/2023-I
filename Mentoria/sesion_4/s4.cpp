#include <iostream>

using namespace std;

void print(int* list, int n){
    cout << "[";
    for (int i = 0; i < n-1; ++i) {
        cout << list[i]<<", ";
    }
    cout << list[n-1];
    cout << "]";
    cout << endl;
}

int* append(int n){
    int* newlist = new int[n];

    for (int i = 0; i < n; ++i) {
        cin>>newlist[i];
    }

    return newlist;
}


int main(){
//    int arr_est[100]; // Estática
//    int* arr_din = new int[100]; // Dinámica
//
//    for (int i = 0; i < 100; ++i) {
//        arr_est[i] = i;
//        arr_din[i] = i;
//    }

    int n; cin>>n;
    int* arr_din = nullptr;

    arr_din = append(n);

    print(arr_din, n);

    int* soyunalista = append(7);


    print(soyunalista, 7);


    return 0;
}
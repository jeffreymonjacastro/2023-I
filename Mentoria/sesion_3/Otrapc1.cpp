#include <iostream>

using namespace std;

void imprime(int arr[]){
    for (int i = 0; i < 6; ++i) {
        cout<<arr[i]<<" ";
    }
}

void Rodar(int arr[], int n){
    if (n > 0){
        for (int i = 0; i < 6; ++i) {

        }
    }

}

int main(){
    int array[6] = {1,2,3,4,5,6};
    int* arr = &array[6];
    int n;

    imprime(array);
    cout<<"N:"<<endl;
    cin>>n;



    return 0;
}
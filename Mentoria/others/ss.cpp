#include <iostream>
#include <iterator>

using namespace std;



int main(){

//    int arr1[3];
//    int arr2[3] = {1,2,3};
//    int arr3[5]{1,2,3};
//
//    int size = 4;
////    char arr4[size]{'a','b','c'};
//
//
//    int* arrd1 = new int[3];
//    int* arrd2 = new int[3]{1,2,3};
//
//    int* arrd3 = nullptr;
//    arrd3 = new int[5]{1,2,3};
//
//    int sized = 4;
//    char* arrd4 = nullptr;
//    arrd4 = new char[sized]{'a','b','c'};
//
//    delete [] arrd1;
//    delete [] arrd2;
//    delete [] arrd3;
//    delete [] arrd4;
//
//

    int* arr = new int[10];

    for (int i = 0; i < 10; ++i) {
        arr[i] = rand()%99;
        cout<<arr[i]<<" ";
    }

    cout<<endl;

    int max1 = -1e9, max2 = -1e9;

    for (int i = 0; i < 10; ++i) {
        if (arr[i] > max1){
            max2 = max1;
            max1 = arr[i];
        } else if (arr[i] > max2) {
            max2 = arr[i];
        }
    }

    cout<<max1<<" "<<max2;

    return 0;
}



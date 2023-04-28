#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// CALLBACKS

void bubbleSort(vector<int> &A, bool (*func)(int, int)) {
    for (int i = 0; i < A.size() - 1; ++i) {
        for (int j = 0; j < A.size() - i - 1; ++j) {
            if (func(A[j], A [j+1]))
                swap(A[j], A[j+1]);
        }
    }
}

bool comp1(int a, int b){
    return a > b;
}

bool comp2(int a, int b){
    return a < b;
}

bool comp3(int a, int b){
    return abs(a) > abs(b);
}

int main(){
    vector<int> A = {5,1,-7,-4,-2,6,3,8};

    for_each(A.begin(), A.end(), [](int i){cout<<i<<" ";});
    cout<<endl;

    bubbleSort(A, comp1);
    for_each(A.begin(), A.end(), [](int i){cout<<i<<" ";});
    cout<<endl;

    bubbleSort(A, comp2);
    for_each(A.begin(), A.end(), [](int i){cout<<i<<" ";});
    cout<<endl;

    bubbleSort(A, comp3);
    for_each(A.begin(), A.end(), [](int i){cout<<i<<" ";});
    cout<<endl;

    return 0;
}
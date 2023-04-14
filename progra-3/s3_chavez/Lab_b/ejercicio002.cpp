#include <iostream>
#include <vector>

using namespace std;

// Un template dentro de otro template
template<template<typename> class C, class T>
void print_poly(C<T>){

    for (int i = 0; i < l.; ++i) {
        cout<<l[i]<<" ";
    }
}

int main(){
    vector<int> v1{3,2,7};

    print_poly(v1);

    return 0;
}
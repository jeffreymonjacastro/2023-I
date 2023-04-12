#include <iostream>

using namespace std;

template<typename T>
void swap_func(T& x, T& y){
    T temp = x;
    x = y;
    y = temp;
}

int main() {
    int x = 1, y = 5;

    cout<<x<<" "<<y<<endl;

    swap_func(x, y);

    cout<<x<<" "<<y<<endl;

    return 0;
}
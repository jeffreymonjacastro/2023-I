#include <iostream>

using namespace std;

template<typename... Ts>
void foo(Ts... xs){
    cout << sizeof...(xs) << endl;
}

int main(){
    foo(1,2);
    foo(1,2,3,3,4,5);
    foo();

    return 0;
}

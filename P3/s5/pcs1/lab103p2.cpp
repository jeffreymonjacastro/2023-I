#include <iostream>

using namespace std;

void print() {
    cout << endl;
}

template<typename... Ts, typename T>
void print(T arg, Ts... args) {
    cout << arg << " ";
    print(args...);
}


int main(){
    print(1, 'a', 4.5, "Hola Mundo", false);

    return 0;

}
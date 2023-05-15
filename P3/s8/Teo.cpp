#include <iostream>
#include <thread>

using namespace std;

void foo(){
    cout << "Hello from foo" << endl;
}

int main(){
    thread t(&foo)


    return 0;
}
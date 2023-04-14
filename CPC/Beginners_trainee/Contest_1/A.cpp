#include <iostream>

void recursion(int &n){
    std::cout<<n<<" ";
    if(n == 1)
        return;
    else {
        if (n%2 == 0) {
            n /= 2;
            recursion(n);
        } else {
            n = n * 3 +1;
            recursion(n);
        }
    }
}

int main(){
    int n; std::cin>>n;

    recursion(n);

    return 0;
}
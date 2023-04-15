#include <iostream>

typedef long long int ll;

int main(){
    ll n = 0; std::cin>>n;

    while(n > 0){
        std::cout << n << " ";
        if(n == 1) {
            break;
        } else {
            if (n % 2 == 0) {
                n /= 2;
            } else {
                n = n * 3 + 1;
            }
        }
    }

    return 0;
}
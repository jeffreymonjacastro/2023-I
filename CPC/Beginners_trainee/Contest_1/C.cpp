// Permutations

#include <iostream>

using namespace std;

int main(){
    long long int n,m; cin>>n;

    if (n == 1){
        cout<<n<<" ";
    } else if (n > 4){
        m = n;
        for (int i = 0; i < n; ++i) {
            if (m % 2 == 0) {
                if (m == 2) {
                    cout << m << " ";
                    m = n - 1;
                } else {
                    cout << m << " ";
                    m -= 2;
                }
            } else {
                if (m == 1) {
                    cout << m << " ";
                    m = n - 1;
                } else {
                    cout << m << " ";
                    m -= 2;
                }
            }
        }
    } else {
        cout<<"NO SOLUTION"<<endl;
    }
}
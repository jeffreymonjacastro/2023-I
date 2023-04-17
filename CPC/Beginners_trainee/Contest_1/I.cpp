// Inverse Prefix Sum

#include <iostream>
#include <vector>

using namespace std;

typedef long long int ll;

int main() {
    ll n, m, sum = 0;
    cin >> n;

    ll S[n];
    ll A[n];

    for (int i = 0; i < n; ++i) {
        cin >> m;

        S[i] = m;
    }

    for(int i = 0; i < n; i++){
        A[i] = S[i] - sum;
        sum += A[i];
    }

    for(ll i: A)
        cout<<i<<" ";

    return 0;
}
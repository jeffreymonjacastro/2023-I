// merge sequences

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long int ll;

int main(){
    long long int n,m,x;

    cin>>n>>m;

    vector<ll> A;
    vector<ll> B;
    vector<ll> C;
    vector<ll> resultA;
    vector<ll> resultB;

    for (int i = 0; i < n; ++i) {
        cin>>x;

        A.push_back(x);
    }

    for (int i = 0; i < m; ++i) {
        cin>>x;

        B.push_back(x);
    }

    for (int i = 0; i < n+m; ++i) {
        if (i < n){
            C.push_back(A[i]);
        } else {
            C.push_back(B[i-n]);
        }
    }

    sort(C.begin(), C.end());

    for (int i = 0; i < C.size(); ++i) {
        for (ll j : A) {
            if (j == C[i]){
                resultA.push_back(i+1);
            }
        }

        for (ll j : B) {
            if (j == C[i]) {
                resultB.push_back(i+1);
            }
        }
    }

    for(ll i : resultA){
        cout<<i<<" ";
    }
    cout<<endl;
    for(ll i : resultB){
        cout<<i<<" ";
    }

    return 0;
}
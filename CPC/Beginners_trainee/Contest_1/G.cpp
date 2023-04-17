// merge sequences

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long int ll;

int main(){
    ll n,m;

    cin>>n>>m;

    vector<ll> A(n);
    vector<ll> B(m);
    vector<pair<ll,char>> C(n+m); // OJITO Solución de Alejandro
    string resultA, resultB;

    for (int i = 0; i < n; i++) {
        cin>>A[i];
    }

    for (int i = 0; i < m; i++) {
        cin>>B[i];
    }

    for (int i = 0; i < n+m; ++i) {
        if (i < n){
            C[i] = {A[i], 'A'};
        } else {
            C[i] = {B[i-n], 'B'};
        }
    }

    sort(C.begin(), C.end());

    for (int i = 0; i < C.size(); ++i) {
        if (C[i].second == 'A') {
            resultA += to_string(i+1)+ " ";
        } else {
            resultB += to_string(i+1) + " ";
        }
    }

    cout<<resultA<<endl;
    cout<<resultB;

    return 0;
}
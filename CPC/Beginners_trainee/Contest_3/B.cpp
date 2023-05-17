#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n; cin>>n;
    vector<int> v(n);
    vector<int> prefixsum(n);

    for (int i = 0; i < n; ++i) {
        cin>>v[i];

        if (i == 0)
            prefixsum[i] = v[i];
        else
            prefixsum[i] = v[i] + prefixsum[i-1];
    }

    int q; cin>>q;
    vector<pair<int,int>> u(q);

    for (int i = 0; i < q; ++i) {
        cin>>u[i].first>>u[i].second;
    }

    for (auto i:u){
        if (i.first == 0)
            cout << prefixsum[i.second] << endl;
        else
            cout << prefixsum[i.second] - prefixsum[i.first-1] << endl;
    }

    return 0;
}
// Number Spiral

#include <iostream>
#include <vector>

using namespace std;

typedef long long int ll;

int main(){
    ll t, x, y, n; cin>>t;

    vector<pair<ll,ll>> nums(t);

    for (int i = 0; i < t; ++i) {
        cin >> x >> y;

        nums[i] = {x, y};
    }

    for(auto i:nums){
        n = max(i.first, i.second);

        if (i.first == i.second) {
            cout<<n*n-n+1<<endl;
        } else if (n%2 == 0) {
            if (i.first > i.second) {
                cout << n * n - n + 1 + (i.first - i.second) << endl;
            } else {
                cout << n * n - n + 1 - (i.second - i.first) << endl;
            }
        } else {
            if (i.first > i.second){
                cout<<n * n - n + 1 - (i.first - i.second) << endl;
            } else {
                cout << n * n - n + 1 + (i.second - i.first) << endl;
            }
        }
    }

    return 0;
}
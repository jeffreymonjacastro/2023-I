#include <iostream>
#include <vector>

using namespace std;

int main(){
    int t, n, q, sum = 0;
    cin>>t;

    for (int i = 0; i < t; ++i) {
        cin>>n>>q;
        vector<int> v(n);
        vector<vector<int>> u(q);
        vector<int> prefixsum(n);

        for (int j = 0; j < n; ++j) {
            cin>>v[j];

            if (j == 0)
                prefixsum[j] = v[j];
            else
                prefixsum[j] = v[j] + prefixsum[j-1];
        }

        for (int j = 0; j < q; ++j) {
            vector<int> temp(3);
            cin>>temp[0]>>temp[1]>>temp[2];
            u[j] = temp;
        }

        vector<int> result(q);

        for (int j = 0; j < q; ++j){
            sum = (u[j][1] - u[j][0] + 1) * u[j][2];

            if (u[j][0] == 1)
                result[j] = prefixsum.back() + sum - prefixsum[u[j][1] - 1];
            else
                result[j] = prefixsum.back() + sum - (prefixsum[u[j][1]-1] - prefixsum[u[j][0]-2]);

            if (result[j] % 2 == 0)
                cout << "NO" << endl;
            else
                cout << "YES" << endl;
        }
    }

    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

int main(){
    int t, n;
    cin>>t;

    for (int i = 0; i < t; ++i) {
        cin>>n;
        vector<int> v(n);
        vector<int> prefixsum(n);

        for (int j = 0; j < n; ++j) {
            cin>>v[j];
        }

        for (int j = 0; j < n; ++j) {
            if (v[j] == -1 && j == 0)
                v[j] = 0;

            else if (v[j] == -1)
                v[j] = prefixsum[j-1]/j;

            if (j == 0)
                prefixsum[j] = v[j];
            else
                prefixsum[j] = v[j]  + prefixsum[j-1];
        }

        for(auto j:v){
            cout << j << " ";
        }

        cout << endl;
    }

    return 0;
}

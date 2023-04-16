// WAY TOO LONG WORDS

#include <iostream>

using namespace std;

int main(){
    int n, l; cin>>n;
    string s;

    string ss[n];

    for (int i = 0; i < n; ++i) {
        cin>>s;

        if (s.length() <= 10)
            ss[i] = s;
        else {
            l = s.length() - 2;

            ss[i] = s[0] + to_string(l) + s[l+1];
        }
    }

    for (string& i:ss) {
        cout<<i<<endl;
    }

    return 0;
}

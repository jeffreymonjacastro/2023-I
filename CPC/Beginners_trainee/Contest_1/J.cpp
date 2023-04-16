// Extra Character

#include <iostream>

using namespace std;

int main(){
    string s, t;

    cin>>s;
    cin>>t;

    for (int i = 0; i < t.length(); ++i) {
        if (s[i] != t[i]) {
            cout<<i+1<<endl;
            break;
        }
    }

    return 0;
}
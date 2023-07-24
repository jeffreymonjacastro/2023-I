#include <bits/stdc++.h>

using namespace std;

#define cpu() ios::sync_with_stdio(false); cin.tie(nullptr);
#define FOR(i, a) for (int i=0; i<a; i++)

void solve(){
  string s;
  cin>>s;

  string hello = "hello";
  int j = 0;

  FOR(i, s.size()){
    if(s[i] == hello[j]){
      j++;
    }
  }

  (j == 5) ? cout<<"YES" : cout<<"NO";
}

int main(){
  solve();

  return 0;
}

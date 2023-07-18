#include <bits/stdc++.h>

using namespace std;

#define cpu() ios::sync_with_stdio(false); cin.tie(nullptr);
typedef long long ll;
typedef long double lld;


void solve(){
  string cf = "codeforces";
  string s;
  cin>>s;
  int count = 0;

  for (size_t i = 0; i < 10; i++){
    if (s[i] != cf[i])
      count++;
  }
  
  cout<<count<<endl;
}

int main(){
  int t; 
  cin>>t;

  while(t--)
    solve();

  return 0;
}

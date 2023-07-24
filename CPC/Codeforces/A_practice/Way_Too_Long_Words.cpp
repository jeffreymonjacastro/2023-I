#include <bits/stdc++.h>

using namespace std;

#define cpu() ios::sync_with_stdio(false); cin.tie(nullptr);
typedef long long ll;
typedef long double lld;


void solve(){
  string s; 
  cin>>s;
  
  if(s.length() <= 10)
    cout<<s<<endl;
  else
    cout<<s[0]<<s.length()-2<<s[s.length()-1]<<endl;
}

int main(){
  int t; 
  cin>>t;

  while(t--)
    solve();

  return 0;
}

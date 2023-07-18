#include <bits/stdc++.h>

using namespace std;

#define cpu() ios::sync_with_stdio(false); cin.tie(nullptr);
typedef long long ll;
typedef long double lld;


void solve(){
  ll n, m, a;
  cin>>n>>m>>a;

  if (n == 0 || m == 0){
    cout<<0;
    return;
  }

  ll i = 1, j = 1;

  while(m - (i*a) > 0)
    i++;
  
  while(n - (j*a) > 0)
    j++;

  cout<<i*j;
}

int main(){
  solve();

  return 0;
}

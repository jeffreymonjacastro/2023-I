#include <bits/stdc++.h>

using namespace std;

#define cpu() ios::sync_with_stdio(false); cin.tie(nullptr);

void solve(){
  int n;
  cin>>n;

  int x = 0, y = 0, z = 0;
  int a, b, c;
  while(n--){
    cin>>a>>b>>c;
    x += a;
    y += b;
    z += c;
  }

  (x == 0 && y == 0 && z == 0) ? cout<<"YES" : cout<<"NO";
}

int main(){
  solve();

  return 0;
}

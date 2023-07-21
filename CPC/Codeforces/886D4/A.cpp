// To my Critics

#include <bits/stdc++.h>

using namespace std;

#define cpu() ios::sync_with_stdio(false); cin.tie(nullptr);
typedef long long ll;
typedef long double lld;
typedef vector<int> vi;


void solve(){
  int a, b, c;
  cin>> a >> b >> c;

  vi ans(3);

  ans[0] = a + b;
  ans[1] = a + c;
  ans[2] = b + c;

  if (ans[0] >= 10 || ans[1] >= 10 || ans[2] >= 10){
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}

int main(){
  int t; 
  cin>>t;

  while(t--)
    solve();

  return 0;
}

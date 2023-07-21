// Blank Space

#include <bits/stdc++.h>

using namespace std;

#define cpu() ios::sync_with_stdio(false); cin.tie(nullptr);
typedef long long ll;
typedef long double lld;


void solve(){
  int n, m=0, max = 0; 
  cin>>n;

  vector<int> a(n);

  for (size_t i = 0; i < n; i++){
    cin>>a[i];
    
    if (a[i] == 0){
      m++;
      
      if (m > max){
        max = m;
      }
    } else {
      m = 0;
    }
  }

  cout<<max<<endl; 
}

int main(){
  int t; 
  cin>>t;

  while(t--)
    solve();

  return 0;
}

#include <bits/stdc++.h>

using namespace std;

#define cpu() ios::sync_with_stdio(false); cin.tie(nullptr);
typedef long long ll;
typedef long double lld;


void solve(){
  int n, k, count = 0;
  cin>>n>>k;

  vector<int> scores(n);

  for (size_t i = 0; i < n; i++){
    cin>>scores[i];
  }

  for (size_t i = 0; i < n; i++){
    if (scores[i] >= scores[k-1] && scores[i] > 0)
      count++;
  }
  
  cout<<count;
}

int main(){
  solve();

  return 0;
}

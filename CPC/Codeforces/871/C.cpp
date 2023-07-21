// Mr. Perfectly Fine

#include <bits/stdc++.h>

using namespace std;

#define cpu() ios::sync_with_stdio(false); cin.tie(nullptr);
typedef long long ll;
typedef long double lld;


void solve(){
  int n;
  cin>>n;

  vector<pair<int, string>> a(n);
  vector<int> flag(3,0); 
  vector<int> sol(3, 1e9);

  for (size_t i = 0; i < n; i++){
    cin>>a[i].first>>a[i].second;
  }

  for (size_t i = 0; i < n; i++){
    if (a[i].second[0] == '1' && a[i].second[1] == '1'){
      if (a[i].first < sol[2]){
        sol[2] = a[i].first;
        flag[2] = 1;
      }
    } else if (a[i].second[0] == '1'){
      if (a[i].first < sol[1]){
        sol[1] = a[i].first;
        flag[1] = 1;
      }
    } else if (a[i].second[1] == '1'){
      if (a[i].first < sol[0]){
        sol[0] = a[i].first;
        flag[0] = 1;
      }
    }
  }

  if (flag[2] == 1)
    cout<<sol[2]<<endl;
  else if (flag[0] == 1 && flag[1] == 1)
    cout<<(sol[0] + sol[1])<<endl;
  else
    cout<<-1<<endl;
}

int main(){
  int t; 
  cin>>t;

  while(t--)
    solve();

  return 0;
}

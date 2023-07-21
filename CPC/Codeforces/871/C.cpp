// Mr. Perfectly Fine

#include <bits/stdc++.h>

using namespace std;

#define cpu() ios::sync_with_stdio(false); cin.tie(nullptr);
typedef long long ll;
typedef long double lld;
typedef vector<int> vi;

#define FOR(i, a) for (size_t i = 0; i < a; i++)
#define pb push_back
#define f first
#define s second

const int MAX = 1e9 + 7;

void solve(){
  int n;
  cin>>n;

  vector<pair<int, string>> a(n);
  vi flag(3,0); 
  vi sol(3, MAX);

  FOR(i, n){
    cin>>a[i].f>>a[i].s;
  }

  FOR(i, n){
    if (a[i].s[0] == '1' && a[i].s[1] == '1'){
      if (a[i].f < sol[2]){
        sol[2] = a[i].f;
        flag[2] = 1;
      }
    } else if (a[i].s[0] == '1'){
      if (a[i].f < sol[1]){
        sol[1] = a[i].f;
        flag[1] = 1;
      }
    } else if (a[i].s[1] == '1'){
      if (a[i].f < sol[0]){
        sol[0] = a[i].f;
        flag[0] = 1;
      }
    }
  }

  if (flag[0] == 1 && flag[1] == 1 && flag[2] == 1)
    (sol[0] + sol[1]) < sol[2] ? cout<<(sol[0] + sol[1])<<endl : cout<<sol[2]<<endl;
  else if (flag[2] == 1)
    cout<<sol[2]<<endl;
  else if (flag[0] == 1 && flag[1] == 1)
    cout << sol[0] + sol[1] << endl;
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

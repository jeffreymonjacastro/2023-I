// Balanced Round

#include <bits/stdc++.h>

using namespace std;

#define cpu() ios::sync_with_stdio(false); cin.tie(nullptr);
typedef long long ll;
typedef long double lld;
typedef vector<ll> vl;
typedef pair<int, int> pi;

#define F0R(i, a, b) for (int i=a; i<b; i++)
#define FOR(i, a) for (int i=0; i<a; i++)
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound


void solve(){
  ll n, k, ans = 0, max = 0;
  cin>>n>>k;

  vl a(n);

  FOR(i, n)
    cin>>a[i];

  if (n == 1){
    cout<<0<<endl;
    return;
  }

  sort(a.begin(), a.end());

  F0R(i, 1, n){
    if (a[i] - a[i-1] <= k){
      ans++;
      if (ans > max)
        max = ans;
    } else
      ans = 0;
  }

  cout<<n - (max+1)<<endl;
}

int main(){
  int t; 
  cin>>t;

  while(t--)
    solve();

  return 0;
}

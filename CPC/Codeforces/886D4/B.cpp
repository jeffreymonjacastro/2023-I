// Ten Words of Wisdom

#include <bits/stdc++.h>

using namespace std;

#define cpu() ios::sync_with_stdio(false); cin.tie(nullptr);
typedef long long ll;
typedef long double lld;
typedef vector<int> vi;
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
  int n;
  cin>>n;

  vector<pi> a(n);
  vi b;

  FOR(i, n){
    cin>>a[i].f>>a[i].s;

    if (a[i].f <= 10){
      b.pb(a[i].s);
    }
  }

  sort(b.begin(), b.end(), greater<int>());

  FOR(i, n){
    if(a[i].s == b[0]){
      cout<< i + 1 <<endl;
      return;
    }
  }
}

int main(){
  int t; 
  cin>>t;

  while(t--)
    solve();

  return 0;
}

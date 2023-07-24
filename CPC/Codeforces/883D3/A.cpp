// Rudolf_and_cut_the_rope

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

const int MAX = 1e9 + 7;
const int MIN = -1e9 - 7;

void solve(){
  int n, count = 0;
  cin>>n;

  vector<pi> v(n);

  FOR(i, n){
    cin>>v[i].f>>v[i].s;

    if (v[i].s < v[i].f)
      count++;
  }

  cout << count << endl;

}

int main(){
  int t; 
  cin>>t;

  while(t--)
    solve();

  return 0;
}

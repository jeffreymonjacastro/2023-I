// Word on the paper

#include <bits/stdc++.h>

using namespace std;

#define cpu() ios::sync_with_stdio(false); cin.tie(nullptr);
typedef long long ll;
typedef long double lld;
typedef vector<char> vc;
typedef vector<vector<char>> vvc;
typedef pair<int, int> pi;

#define F0R(i, a, b) for (int i=a; i<b; i++)
#define FOR(i, a) for (int i=0; i<a; i++)
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound


bool isAlpha(char c) {
  return c >= 'a' && c <= 'z';
}


void solve(){
  vvc m(8, vc(8, '.'));
  string s;

  FOR(i, 8){
    FOR(j, 8){
      cin>>m[i][j];
      if (isAlpha(m[i][j]))
        s += m[i][j];
    }
  }

  cout<<s<<endl;
}

int main(){
  int t; 
  cin>>t;

  while(t--)
    solve();

  return 0;
}

// Helpful maths

#include <bits/stdc++.h>

using namespace std;

#define cpu() ios::sync_with_stdio(false); cin.tie(nullptr);
typedef vector<char> vc;


#define FOR(i, a) for (int i=0; i<a; i++)
#define pb push_back


void solve(){
  string s;
  cin >> s;

  vc result;

  FOR(i, s.length()){
    if (s[i] != '+') {
      result.pb(s[i]);
    }
  }

  sort(result.begin(), result.end());

  FOR(i, result.size()){
    cout << result[i];
    if (i != result.size() - 1) cout << "+";
  }
}

int main(){
  solve();

  return 0;
}

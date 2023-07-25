// bit++

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
  int n, x = 0;
  cin>>n;
  string s;

  FOR(i, n){
    cin>>s;
    if(s[0] == '+' && s[1] == '+'){
      x++;
    }else if(s[1] == '+' && s[2] == '+'){
      x++;
    }else if(s[0] == '-' && s[1] == '-'){
      x--;
    }else if(s[1] == '-' && s[2] == '-'){
      x--;
    }
  }

  cout << x << endl;
}

int main(){
  solve();

  return 0;
}

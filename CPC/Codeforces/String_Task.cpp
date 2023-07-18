#include <bits/stdc++.h>

using namespace std;

#define cpu() ios::sync_with_stdio(false); cin.tie(nullptr);
typedef long long ll;
typedef long double lld;


void solve(){
  string s;
  cin>>s;

  vector<char> v = {'a', 'e', 'i', 'o', 'u', 'y'};

  vector<int> pos;

  for (char& c : s){
    c = tolower(c);
  }

  for (size_t i = 0; i < s.length(); i++){
    if (find(v.begin(), v.end(), s[i]) == v.end()){
      pos.push_back(i);
    }
  }
  
  for (int i : pos){
    cout << '.' << s[i];
  }
  
}

int main(){
  solve();

  return 0;
}

#include <bits/stdc++.h>

using namespace std;

#define cpu() ios::sync_with_stdio(false); cin.tie(nullptr);
typedef long long ll;
typedef long double lld;


void solve(int& count){
  int x, y, z, sum;
  cin>>x>>y>>z;

  sum = x + y + z;

  if (sum >= 2)
    count++;
}

int main(){
  int n, count = 0; 
  cin>>n;

  while(n--)
    solve(count);

  cout << count;

  return 0;
}

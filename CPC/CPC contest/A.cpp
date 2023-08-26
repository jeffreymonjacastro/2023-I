#include <bits/stdc++.h>

using namespace std;

#define cpu() ios::sync_with_stdio(false); cin.tie(nullptr)
typedef long long ll;
typedef long double lld;

const int MAX = INT32_MAX;
const int MIN = INT32_MIN;

void solve(){
  int n;
  cin>>n;

	vector<int> v(n);
	int red = 0;
	int blue = 0;
	bool flag = false;

	for (int i = 0; i < n; i++){
		cin>>v[i];
	}

	for (int i = 0; i < n; i++){
		red += v[i];
		blue = 0;
		for (int j = i + 1; j < n; j++){
			blue += v[j];
		}

		if (red % 2 == 0 && blue % 2 == 0){
				flag = true;
		} else if (red % 2 == 1 && blue % 2 == 1) {
				flag = true;
		}
	}

	if(flag) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
}

int main(){
  cpu();
  int t=1; 
  cin>>t;
  
  while(t--)
    solve();
}

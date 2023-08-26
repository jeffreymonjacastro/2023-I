#include <bits/stdc++.h>

using namespace std;

#define cpu() ios::sync_with_stdio(false); cin.tie(nullptr)
typedef long long ll;
typedef long double lld;

const int MAX = INT32_MAX;
const int MIN = INT32_MIN;

void recursion(set<ll>& v, int n){
	if (n % 3 != 0) return;

	int a,b;
	a = n/3;
	b = 2*a;

	v.insert(a);
	v.insert(b);
	
	recursion(v, a);
	recursion(v, b);
}


void solve(){
  ll n, m;
	cin>>n>>m;
	set<ll> v;

	if (m > n) {
		cout << "NO" << endl;
		return;
	}

	if (n == 1){
		cout << "YES" << endl;
		return;
	}

	bool flag = false;

	if (n % 3 == 0) {
		recursion(v, n);

		if (find(v.begin(), v.end(), m) != v.end()){
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
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


/*
Justificación (piedad):

En el problema gold rush hay ciertos constraits implícitos a tomar en cuenta.
Primero, m no debe ser mayor a n. Output: NO
Segundo, si n = 1 y m = 1 el output es: YES
Tercero, n debe ser múltiplo de 3, para que así pueda dividirse en un número que sea el doble que el otro
Cuarto, si cumple esto último, m debe estar dentro de todas las subdivisiones posibles de n.
		Para ello se utilizó una recursión que inserta en un set todos los números que se dividen de n. 
		La recursión termina cuando n no es múltiplo de 3, es decir, no se cumple la condición de partición.
*/

#include <bits/stdc++.h>

using namespace std;

#define cpu() ios::sync_with_stdio(false); cin.tie(nullptr)
typedef long long ll;
typedef long double lld;

const int MAX = INT32_MAX;
const int MIN = INT32_MIN;

int main(){
  cpu();
  ll n, k; 
  cin>>n>>k;

  string s, s1, s2;
	cin>>s;

	s1 = s2 = s;

	ll a = 0, b = 0;

	for(int i = 0; i < n; i++){
		if(s[i] == 'a') a++;
		else b++;
	}

	ll size1 = 0, size2 = 0;

	if (a >= b) {
		for(int i = 0; i < n; i++){
			if (s1[i] == 'b' && k != 0){
				s1[i] = 'a';
				k--;
			}
		}

		for(int i = 0; i < n; i++){
			if (s1[i] == 'a') 
				size1++;
			else break;
		}

		for(int i = n; i >= 0; i++){
			if (s2[i] == 'b' && k != 0){
				s2[i] = 'a';
				k--;
			}
		}

		for(int i = n; i >= 0; i++){
			if (s2[i] == 'a') 
				size2++;
			else break;
		}

	} else {
		for(int i = 0; i < n; i++){
			if (s1[i] == 'a' && k != 0){
				s1[i] = 'b';
				k--;
			}
		}

		for(int i = 0; i < n; i++){
			if (s1[i] == 'b') 
				size1++;
			else break;
		}

		for(int i = n; i >= 0; i++){
			if (s2[i] == 'a' && k != 0){
				s2[i] = 'b';
				k--;
			}
		}

		for(int i = n; i >= 0; i++){
			if (s2[i] == 'b') 
				size2++;
			else break;
		}
	}

	cout << max(size1, size2) << endl;
}

/*
Justificación (piedad):

Mi idea era la siguiente:
Primero, buscar qué char se repite más veces, a o b.
Segundo, como el char anterior es el que se repite más veces, procederemos a sustituir k veces el char por el otro, de izq a der.
Tercero, se cuenta la cadena más grande del char escogido.
Cuarto, se coutea el SIZE.

*/

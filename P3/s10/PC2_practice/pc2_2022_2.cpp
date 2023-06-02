#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

// PREGUNTA 1
bool es_primo(int n) {
    if (n == 1)
        return false;
    else if (n == 2)
        return true;
    else if (n % 2 == 0)
        return false;

    for (int i = 2; i <= pow(n,0.5); ++i) {
        if (n % i == 0)
            return false;
    }

    return true;
}


void pregunta1(){
    vector<int> v(1000);
    generate(v.begin(), v.end(), [](){return rand()%99 + 1;});

    // for_each(v.begin(), v.end(), [](int x){cout << x << " ";});

    map<int, bool> m_primos;
    map<int, int> m_count;

    for (auto it = v.begin(); it != v.end(); it++){
        if (es_primo(*it))
            m_primos[*it] = true;
        else
            m_primos[*it] = false;

        m_count[*it]++;
    }

    for (auto& pair: m_primos){
        cout << pair.first << ": " << (pair.second ? "true" : "false") << endl;
    }

    vector<pair<int,int>> count(m_count.begin(), m_count.end());

    sort(count.begin(), count.end(), [](pair<int,int> a, pair<int,int> b){return a.second > b.second;});

    for (auto it = count.begin(); it != count.end(); it++){
        cout << (*it).first << ": " << (*it).second << endl;
    }
}

// PREGUNTA 2
int foo (int a, int b) {
    while (b > 0) {
        cout << "a: " << a << ", b: " << b << endl;

        int q = a / b;
        int r = a - q * b;
        a = b;
        b = r;

        cout << "a: " << a << ", b: " << b << ", q: " << q << ", r: " << r << endl;

    }
    return a;
}

/*
    El algoritmo foo calcula el MCD de dos números enteros positivos a y b.
    El algoritmo funciona de la siguiente manera:
        1. Se calcula el cociente de a y b, y se guarda en q.
        2. Se calcula el residuo de a y b, y se guarda en r.
        3. Se actualiza el valor de a con el valor de b.
        4. Se actualiza el valor de b con el valor de r.

    El invariante de bucle es que, por cada iteración, el valor de a es el mismo que el MCD de los valores originales de a y b.


 */



void pregunta2(){
    cout << foo(60, 25) << endl;
}

// Paola Martinez, coordinación académica


int main(){
    pregunta2();

    return 0;
}
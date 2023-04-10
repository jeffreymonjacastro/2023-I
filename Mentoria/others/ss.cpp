#include <iostream>

using namespace std;

int fibonacci(int n){
    if (n <= 1)
        return 1;
    else
        return fibonacci(n-1) + fibonacci(n-2);
}

string deletrear(string s){
    string new_s;

    for (int i = s.length()-1; i > -1; i--){
        new_s += s[i];
    }

    return new_s;
}

int main() {
    cout << deletrear("hola");

    return 0;
}


//    int n;
//
//    cout << "Write here: ";
//    cin >> n;
//    cout << n << endl;
//
////------------------------------
//
//    int entero = -10;
//    float decimal = 10.5;
//    double decimal2 = 3.14159;
//    char caracter = 'a';
//    string cadena = "Hola mundo";
//    bool booleano = true;
//    long int entero_largo = 300000;
//    unsigned long int ent_larg_pos = 1000000;
//    const int no_cambio = 15;
//    auto chatgpt = 12345.6754;
//
//    //------------------------------
//
//    int m;
//    cin >> m;
//
//    if (m >= 3 && m <= 10) {
//        m++;
//    } else if (m <= 20) {
//        m--;
//    } else {
//        cout << "xd" << endl;
//    }
//
//    //--------------------
//    int n = 0;
//
//    for(int i = 0; i < 10; i++){
//        n += i*2;
//    }
//
//    cout<<n;
//
//    // ------------------

    return 0;
}




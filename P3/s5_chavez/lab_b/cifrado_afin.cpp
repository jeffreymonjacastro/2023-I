#include <iostream>
#include <algorithm>

using namespace std;

// CIFRADO A FIN
// c = (ax + b) % 26

struct CAfin {
    int a;
    int b;
    CAfin(int _a = 1, int _b = 1): a(_a), b(_b){}

    void operator()(string& s){
        for_each(s.begin(), s.end(), [&](char c){cout << char((a*(int(c)-65) + b)%26 + 65);});
    }
};

struct Desencriptar {
    int a;
    int b;
    Desencriptar(int _a = 1, int _b = 1): a(_a), b(_b){}

    void operator()(string& s){
        for_each(s.begin(), s.end(), [&](char c){cout << ((int(c) - b)/a + 65);});
    }
};

int main(){
    string s = "HOLAMUNDO";
    CAfin cifrar(5,8);
    cout << "Original: " << s << endl;

    cifrar(s);

    string s2 = "EVAVAUINCLAKECZWCVCRIUZIKECLWQFWIUESEIPZA";
    Desencriptar des(5,8);

    des(s2);

    return 0;
}
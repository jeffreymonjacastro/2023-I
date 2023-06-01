#include <iostream>
#include <algorithm>

using namespace std;

// PREGUNTA 1:

struct Cipher {
    int a, b;
    Cipher(int _a, int _b) : a(_a), b(_b) {}

    char operator()(char c){
        int new_c = (a * (c - 'A') + b) % 26;
        return new_c + 'A';
    }

    void operator()(string& s){
        for_each(s.begin(), s.end(), [&](char c){
            int new_c = (a * (c - 'A') + b) % 26;
            cout << char(new_c + 'A');
        });
    }
};

struct antiCipher{
    int a,b;
    string alf = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    antiCipher(int _a, int _b) : a(_a), b(_b) {}

    void operator()(string& s){
        for (int i = 0; i < s.length(); ++i) {
            for (int j = 0; j < alf.length(); ++j) {
                char temp = (a * (alf[j] - 'A') + b) % 26 + 'A';
                if (temp == s[i]){
                    cout << alf[j];
                }
            }
        }
    }
};

void pregunta1(){
    Cipher F(5, 6);
    cout << F('Y') << endl;

    Cipher H(21, 4);
    cout << H(F('Y')) << endl;

    string s = "PROGRAMACION";
    F(s);

    cout << endl;

    string p = "DNYKNGOGQUYT";
    F(p);

    cout << endl;



    string u = "PYJGOCTVYATQOGSOGS";
    H(u);

    cout << endl;

    cout << H('P') << endl;

    string alf = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for(int i=0; i<u.length()  ; i++){
        for(int j=0; j<alf.length(); j++){
            if (u[i] == H(alf[j])){
                cout << alf[j];
            }
        }
    }
    cout << endl;

//    string p = "DNYKNGOGQUYT";

    antiCipher G(5, 6);

    G(p);
}


// PREGUNTA 2:


int main(){
    pregunta1();

    return 0;
}
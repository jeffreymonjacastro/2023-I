#include <iostream>
#include <iomanip>

using namespace std;

void noretorno(){
    cout<<"hola"<<endl;
}

int entero(int a, int b){
    int sum;
    sum = a +b;
    return sum;
}

long long int hello(){
    int n = 5;

    return n;
}

string cadena(){

    return "Me llamo c++";
}

char caracter(){

    return 'a';
}




int main(){
//    Ctrl + /
//    int n, m = 0;
//
//    cout<<"Ingrese el num: "<<endl;
//    cin>>n;
//
//    m += (n%10)*100;
//    n /= 10;
//    m += (n%10)*10;
//    n /= 10;
//    m += n;
//
//    cout<<m<<endl;

//    int s1, s2, s3;
//    cout<<"Ingrese los lados: "<<endl;
//    cin>>s1>>s2>>s3;
//
//    if(s1 + s2 > s3 && s2 + s3 > s1 && s1 + s3 > s2)
//        cout<<"Es triangulo"<<endl;
//    else
//        cout<<"No es triangulo"<<endl;



//    int a, b, sum = 0;
//    cout<<"Ingrese primer numero: "<<endl; cin>>a;
//
//    while(true){
//        cout<<"Ingrese segundo numero: "<<endl; cin>>b;
//
//        if (b > a)
//            break;
//    }
//
//    string impares;
//
//    for (int i = a; i <= b; ++i) {
//        if(i % 2 != 0) {
//            impares += to_string(i) + " ";
//
//            if(i != a && i != b)
//                sum += i;
//        }
//    }
//
//    cout<<impares<<endl;
//    cout<<sum<<endl;


//    int altura;
//
//    while(true){
//        cout<<"Altura: "<<endl; cin>>altura;
//
//        if(altura >= 4 && altura <= 50 && altura % 2 == 0){
//            break;
//        }
//    }
//
//    for (int i = 0; i < altura; ++i) {
//        for (int j = 0; j < altura; ++j) {
//            if((i + j == altura/2 -1) || (j - i == altura/2) || (i - j == altura/2) || (i + j == altura-1 + altura/2))
//                cout<<"*";
//            else
//                cout<<" ";
//        }
//
//        cout<<endl;
//    }

    int n, m;
    cout<<"Filas: "<<endl; cin>>n;

    for (int i = 0; i < n; ++i) {
        m = 1;
        for (int j = 0; j < n; ++j) {
            if(i + j >= n -1) {
                cout << setw(4) <<  m;
                m++;
            } else
                cout<< setw(4) << " ";
        }

        cout<<endl;
    }

    return 0;
}
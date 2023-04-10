#include <iostream>

using namespace std;

int ejemplo001(int n){
// División entera
    int new_n = 0;

    new_n += (n % 10)*100;
    n = n/10;

    new_n += (n%10)*10;
    n = n/10;

    new_n += n;

    return new_n;
}

void ejercicio001(){
    int n, m, sum = 0;
    string result = "";
    cout<<"Primer num: "; cin>>n;
    cout<<"Segundo num: "; cin>>m;

    for (int i = n; i <= m; i++){
        if (i % 2 != 0) {
            result += to_string(i) + " ";

            if (i != n && i != m) {
                sum += i;
            }
        }
    }

    cout<<"Num impares: "<<result<<endl;
    cout<<"Suma: "<<sum<<endl;


}



void ejercicio002(){
    int n = 0;

    while(true){
        cout<<"Ingrese el alto: "<<endl; cin>>n;

        if (n >= 4 && n <= 50 && n % 2 == 0)
            break;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if ((i + j == n / 2 - 1) || (j - i == n / 2) || (i - j == n / 2) || (i + j == n - 1 + n / 2))
                cout << "*";
            else
                cout << " ";
        }
        cout << endl;
    }
}

int main(){
    ejercicio002();

    return 0;
}
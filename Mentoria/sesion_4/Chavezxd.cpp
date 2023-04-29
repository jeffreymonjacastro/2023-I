#include <iostream>
#include <cmath>

using namespace std;

//void leer(int& n){
//    cin>>n;
//}
//
//// Forma normalita
//void imprimir_triangulo1(int n){
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < n; ++j) {
//            if (j <= i) {
//                cout << "*";
//            }
//        }
//        cout<<endl;
//    }
//}
//
//// Forma recursiva
//void imprimir_triangulo(int n){
//    if (n == 1) {
//        cout<<"*"<<endl;
//    }
//    else {
//        imprimir_triangulo(n - 1);
//        for (int i = 0; i < n; ++i) {
//            cout << "*";
//        }
//        cout<<endl;
//    }
//}
//
//int main(){
//    int x;
//    leer(x);
//
//    imprimir_triangulo(x);
////    imprimir_triangulo1(x);
//
//    return 0;
//}

void cuadrado_perf_mas_proximo(int* n) {
    int raiz = sqrt(*n);
    int izquierda = pow(raiz, 2);

    int derecha = pow((raiz + 1), 2);

    if ((*n - izquierda) < (derecha - *n))
        *n = izquierda;
    else
        *n = derecha;
}

int main(){
    int n;
    cout << "Ingrese un numero : "; cin>>n;

    cuadrado_perf_mas_proximo(&n);

    cout << n << endl;

    return 0;
}
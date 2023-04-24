#include <iostream>
#include <vector>
#include <any>

using namespace std;

struct pc {
    int GBRAM;
    int Espacio;
};

int* crearlista(int n){
    int* listanueva = new int[n];

    for (int i = 0; i < n; ++i) {
        listanueva[i] = rand()%9;
    }

    return listanueva;
}

int main() {
//    int x = 5;
//    cout << x <<endl;
//    cout << &x <<endl;
//
//    int* p = &x;
//
//    cout<<p<<endl;
//    cout<<*p<<endl;
//
//    *p = 6;
//
//    cout<<x<<endl;
//
//    int x = 6;
//    char c = 'a';
//    string s = "helloworld";
//    double d = 3.3;
//    float f;
//    bool b;
//
//    char* pc = nullptr;
//    string* ps;
//    double* pd;

//    int x = 5;
//    int* p = &x;
//    int** pp = &p;
//
//    cout<<&x<<endl;
//    cout<<p<<endl;
//    cout<<*pp<<endl;
//
//    cout<<x<<endl;
//    cout<<*p<<endl;
//    cout<<**pp<<endl;

//    cout<<&pp<<endl;

//    string c = "helloworld";

    // new - delete

    // Lista estática
    int list1[5]{1,2,3,4,5};

    // Lista dinámica
    int* lista1 = new int[5];

    for (int i = 0; i < 5; ++i) {
        cin>>lista1[i];
    }

    for (int i = 0; i < 5; ++i) {
        cout<<lista1[i]<<endl;
    }

    pc* listapcsgamer = new pc[5];

    // Liberar memoria
    delete [] lista1;
    lista1 = nullptr;

}
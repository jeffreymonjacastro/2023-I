// Varadic templates

#include <iostream>
#include <cmath>

using namespace std;

template<class... Ts>
auto suma(Ts... args){
    return (args+...);
}

template<class... Ts>
auto promedio(Ts... args){
    return ((args+...)/sizeof...(args));
}

template<class... Ts>
float cuadrados(Ts... args){
    float s = (pow(args, 2)+...);
    return s / sizeof...(args);
}

// Template imprimir recursivo
void print(){cout<<endl;}

template<typename T, typename... Ts>
void print(T arg, Ts... args){
    cout << arg;
    print(args...);
}


int main(){
//    cout<<"Utilizando 'suma' "<< endl;
//    cout<<suma(1)<<endl;
//    cout<<suma(1,2)<<endl;
//    cout<<suma(1,2.1,3.6,4.09,5.1)<<endl;
//    cout<<suma('h','o','l','a')<<endl;


//    cout<<"Promedios: "<<endl;
//    cout<<promedio(10.05, 15.3, 18.1)<<endl;


//    cout<<"Cuadrados:"<<endl;
//    cout<<cuadrados(2,3,4,5,6);

    print(1,2,3);
    print();
    print(1,2,3,4,5,6);
    print();
    print("Hola", 1, "Mundo");

    return 0;
}
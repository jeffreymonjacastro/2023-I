#include "header.h"

// FUNCIONES

//int suma(int a, int b){
//    return a + b;
//}
//
//char caracter(){
//    return 'A';
//}
//
//double decimal(int a, double b){
//    return a / b;
//}
//
//string cadena(string s, char c){
//    return s + c;
//}
//
//long long int numerolargo(){
//    return 1e9;
//}
//
//
//void noretorno(string s){
//    cout<<"Hola, "<<s;
//}
//
//

//struct estudiante {
//    string name;
//    int edad;
//    string carrera;
//};
//
//estudiante Estudiante1;
//
//string nombre, carrera;
//int edad;
//
//cout<<"Escribe el nombre, edad y carrera del estudiante: "<<endl;
//
//cin>>nombre>>edad>>carrera;
//
//Estudiante1.name = nombre;
//Estudiante1.edad = edad;
//Estudiante1.carrera = carrera;
//
//cout<<Estudiante1.name<<" "<<Estudiante1.edad<<" "<<Estudiante1.carrera<<endl;
//
//struct paresOrdenados {
//    int x;
//    int y;
//};

//typedef string c;
//
//string persona(c nombre, c apellido){
//    return nombre + " " + apellido;
//}

//int n;
//n = 10;
//cout<<n<<endl;
//
//int &m = n;
//cout<<m<<endl;
//
//n += 20;
//cout<<m<<endl;
//
//m -= 5;
//cout<<n<<endl;

//f sum(f a, f b){
//  return a + b;
//}
//
//f soyfloat = 3.6;
//
//cout<<sum(decimal, soyfloat)<<endl;


// Queremos hacer un switch (cambiar de valor entre dos variables)
//// paso por valor
//
//void intercambio(int a, int b){
//    int temp = a;
//    a = b;
//    b = temp;
//}
//
////referencia
//void intercambioref(int& a, int& b){
//    int temp = a;
//    a = b;
//    b = temp;
//}

//int n; cin>>n;
//int x;
//
//int array[n];
//char arr_c[4] = {'H', 'O', 'L', 'A'};
//string arr_s[10];
//
//
//for (int i = 0; i < n; i++) {
//cin>>x;
//
//array[i] = x;
//}
//
//for (int i:array) {
//cout<<i<<" ";
//}
//
//cout<<array[0] + array[1]<<endl;
//
////++i = i++
////

// Ejercicios:
//Escribe un programa que a través de una función con paso por valor y referencia devuelva el área y el perímetro de un rectángulo.
//
//void calcular(int b, int h, int& a, int& p){
//    a = b*h;
//    p = (b+h) * 2;
//}
//
//int base, altura, area, perimetro;
//
//cin>>base>>altura;
//
//calcular(base, altura, area, perimetro);
//
//cout<<area<<" "<<perimetro<<endl;


//Escribe un programa que genere un registro de n estudiantes en una lista estática y almacene su nombre y sus notas.

//struct estudiantes {
//    string nombre;
//    int nota;
//};
//
//int n; cin>>n;
//
//estudiantes registro[n];
//
//for (int i = 0; i < n; ++i) {
//string nombre;
//int nota;
//
//cin>>nombre>>nota;
//
//registro[i].nombre = nombre;
//registro[i].nota = nota;
//}
//
//for (auto i: registro){
//cout<<i.nombre<<" "<<i.nota<<endl;
//}

string BINARIO(int A){
    if (A <= 1)
        return to_string(A);
    else
        return BINARIO(A/2) + to_string(A%2);
}


int main(){
    int n, sum = 0;
    string binarios;

    while(true){
        cout<<"INGRESE NUMERO: "; cin>>n;

        if (n == 0){
            break;
        } else if (n < 0){
            cout<<"Solo se realiza el calculo para numeros positivos"<<endl;
        } else {
            sum += n;

            string result;

            result = BINARIO(n);

            binarios += result + ",";

            cout<<"El numero "<<n<<" en binario es: "<<result<<endl;
        }
    }

    string total = BINARIO(sum);

    cout<<"La suma de los numeros binarios "<<binarios<<"es: "<<total<<endl;


    return 0;
}
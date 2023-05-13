#include <iostream>
#include <vector>

using namespace std;

//// Teoría de vectores ////
/*
### CREATE:
 ## Declarar un vector
    - vector<int> v; (se declara un vector de enteros vacío)
    - vector<string> v2; (se declara un vector de strings vacío)
    - vector<int> v3(10); (se declara un vector de enteros con 10 elementos)
    - vector<int> v4(10, 5); (se declara un vector de enteros con 10 elementos, todos con valor 5)
    - vector<int> v5 = {1, 2, 3, 4, 5}; (se declara un vector de enteros con 5 elementos, con los valores 1, 2, 3, 4, 5)

 ## Agregar elementos al vector
    - v.push_back(elem): agregar un elemento al final del vector
    - v.emplace_back(elem): agregar un elemento al final del vector (más eficiente que push_back)
    - v.insert(pos, elem): agregar un elemento en la posición i del vector
    - v.emplace(pos, elem): agregar un elemento en la posición i del vector (más eficiente que insert)

    - v.rezise(tam, val): cambiar el capacidad del vector a tam, y todos los elementos tendrán el valor val

### READ
 ## Mediante índices
    - v[i]: obtener el elemento en la posición i del vector
    - v.at(i): obtener el elemento en la posición i del vector (más seguro que v[i])

 ## Mediante iteradores
    - v.begin(): obtener un iterador al inicio del vector
    - v.end(): obtener un iterador al final del vector

### UPDATE
    - v[i] = elem: asignar el valor elem al elemento en la posición i del vector
    - v.at(i) = elem: asignar el valor elem al elemento en la posición i del vector (más seguro que v[i])

### DELETE
    - v.pop_back(): eliminar el último elemento del vector
    - v.erase(pos): eliminar un elemento en la posición i del vector
    - v.clear(): eliminar todos los elementos del vector
    - v.shrink_to_fit(): eliminar la capacidad extra del vector

### OTHERS
    - v.size(): obtener el tamaño del vector
    - v.capacity(): obtener la capacidad del vector
    - v.empty(): devuelve true si el vector está vacío, false en caso contrario
    - v.swap(v2): intercambia los elementos de v con los de v2
    - v.front(): devuelve el primer elemento del vector
    - v.back(): devuelve el último elemento del vector

*/


int main(){
    vector<int> v;
    vector<string> v2;
    vector<int> v3(10);
    vector<int> v4(10, 5);
    vector<int> v5 = {1, 2, 3};

    v.push_back(1);
    v.emplace_back(2);
    v.insert(v.begin(), 3);
    v.emplace(v.end(), 4);

//    cout << v[0];
//    cout << v.at(1);

//    for(auto i:v){
//        cout << i;
//    }

    v.begin();
    v.end();

    v[1] = 5;
    v.at(2) = 6;

//    for(auto i:v){
//        v[i]++;
//    }

    v.pop_back();
    v.erase(v.begin());
    v.clear();
    v.shrink_to_fit();

    v.size();
    v.capacity();
    v.empty();
    v.swap(v5);
    v.front();
    v.back();

//    for (int i = 0; i < v.size(); ++i) {
//        cout << v[i];
//    }

//    for(auto i:v){
//        cout << i;
//    }
//
//    for(auto i=v.begin(); i!=v.end(); ++i){
//        cout << *i;
//    }

    vector<vector<int>> vmatrix = {{1, 2, 3}, {4, 5, 6}};

    vector<int> v1 = {1, 2, 3};

    vmatrix[0].push_back(3);
    vmatrix[1].pop_back();
    vmatrix.push_back(v1);


    for(auto i: vmatrix){
        for(auto j:i){
            cout << j*j << " ";
        }

        cout << endl;
    }

    

    return 0;
}

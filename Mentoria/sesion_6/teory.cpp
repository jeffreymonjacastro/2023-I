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

    - v.rezise(tam, val): cambiar el tamaño del vector a tam, y todos los elementos tendrán el valor val

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


Size: obtener el tamaño del vector
Begin: obtener un iterador al inicio del vector
End: obtener un iterador al final del vector
Empty: determinar si el vector está vacío





*/



int main(){

    return 0;
}
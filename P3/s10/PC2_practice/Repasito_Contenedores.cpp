#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include <map>
#include <set>

using namespace std;

/* TEMAS PC2:
    * Callables y Librería Algorithm
    -> Contenedores e Iteradores
    * Complejidad Algoritmica e Invariante de Bucle
    * Programación Concurrente
*/

/*
    SEGUNDO TEMA: CONTENEDORES E ITERADORES
    -> Contenedores Secuenciales
        - Almacena los elementos en una secuencia
        - Almacena elementos del mismo tipo
        - Se puede controlar el orden (indice) en el que se accede e inserta los elementos

    * Tipos de contenedores secuenciales:
        + array: elementos adjuntos (accesos por subindices, acceso aleatorio)
        + vector: elementos adjuntos (accesos por subindices, acceso aleatorio)
        + string: elementos adjuntos (accesos por subindices, acceso aleatorio)
        + deque: elementos no adjuntos (accesos por subindices, acceso aleatorio)
        + list: elementos enlazados, acceso por punteros
        + forward_list: elementos enlazados, un solo puntero hacia adelante
*/

/*
    ARRAY
    * Rápido acceso a cualquier elemento, se accede por índices
    * No se puede añadir/eliminar elementos.
    * No se puede cambiar el tamaño del array
    * No soporta iteradores
*/

void ejemplo001(){
    int arr[5] = {1, 2, 3, 4, 5};
    int* arr2 = new int[5] {1, 2, 3, 4, 5};

    for(int i = 0; i < 5; i++){
        cout << arr[i] << endl;
        cout << arr2[i] << endl;
    }
}

/*
    VECTOR
    * Rápido acceso a cualquier elemento, se accede por índices
    * Se puede añadir/eliminar elementos (puede ser costoso si no es el último)
    * Se puede cambiar el tamaño del vector
    * Soporta iteradores
*/

void ejemplo002(){
    vector<int> v = {1, 2, 3, 4, 5};

    for(auto it = v.begin(); it != v.end(); it++){
        cout << *it << endl;
    }
}

/*
    STRING
    * Rápido acceso a cualquier elemento, se accede por índices
    * Rápido al añadir elementos al final
    * Se puede cambiar el tamaño del string
    * Soporta iteradores
*/

void ejemplo003(){
    string s = "Hola Mundo";

    for(auto it = s.begin(); it != s.end(); it++){
        cout << *it << endl;
    }
}

/*
    LIST
    * No se puede acceder a los elementos por índices, solo con punteros
    * Rápido al añadir/eliminar elementos en cualquier posición
    * Se puede cambiar el tamaño de la lista
    * Soporta iteradores
 */

void ejemplo004(){
    list<int> l = {1, 2, 3, 4, 5};

    for(auto it = l.begin(); it != l.end(); it++){
        cout << *it << endl;
    }
}

/*
    FORWARD_LIST
    * Acceso con punteros solo hacia adelante
    * Rápido al añadir/eliminar elementos en cualquier posición
    * Se puede cambiar el tamaño de la forward_list
    * Soporta iteradores
 */

void ejemplo005() {
    forward_list<int> fl = {1, 2, 3, 4, 5};

    for (auto it = fl.begin(); it != fl.end(); it++) {
        cout << *it << endl;
    }
}

/*
    ITERADORES
    * Es un tipo de objeto que se comporta como puntero y permite acceder a los elementos de un contenedor
    * Los iteradores varían según el tipo de contenedor al que apunte

    * Funciones de iteradores:
        - begin(): devuelve un iterador al primer elemento del contenedor
        - end(): devuelve un iterador a uno después del último elemento del contenedor
        - distance(it1, it2): devuelve la distancia entre dos iteradores
*/

void ejemplo006(){
    vector<int> v = {1, 2, 3, 4, 5};
    list<int> l = {1, 2, 3, 4, 5};
    forward_list<int> fl = {1, 2, 3, 4, 5};

    vector<int>::iterator it1 = v.begin();
    list<int>::iterator it2 = l.begin();
    forward_list<int>::iterator it3 = fl.begin();
}

/*
    * Funciones (SOLO EN FORWARD LIST):
        - list.insert_after(it, val): inserta un elemento después de it
        - next(it): devuelve un iterador al siguiente elemento de it
        - list.push_front(val): inserta un elemento al inicio de la lista
        - list.pop_front(): elimina el primer elemento de la lista
        - list.remove(val): elimina todos los elementos de la lista que tengan el valor val
        - list.remove_if(cond): elimina todos los elementos de la lista que cumplan con la condición cond
*/

void ejemplo007(){
    forward_list<int> fl = {1, 2, 3, 4, 5};
    auto it = fl.begin(); // El auto es god

    fl.insert_after(it, 6); // 1, 6, 2, 3, 4, 5
    it = next(it); // it apunta a 6
    fl.push_front(0); // 0, 1, 6, 2, 3, 4, 5
    fl.pop_front(); // 1, 6, 2, 3, 4, 5
    fl.remove(3); // 1, 6, 2, 4, 5
    fl.remove_if([](int x){return x % 2 == 0;}); // 1, 5
}

/*
    * Operaciones permitidas entre iteradores:
        - *it -> dereferencia
        - it++ -> apuntar al siguiente elemento
        - it-- -> apuntar al elemento anterior
        - it1 == it2 -> comparar si dos iteradores apuntan al mismo elemento
        - it1 != it2 -> comparar si dos iteradores apuntan a elementos distintos

    * Operaciones (STRING Y VECTOR):
        - it + n, it - n -> avanzar o retroceder n posiciones
        - it1 < it2, it1 > it2, it1 <= it2, it1 >= it2 -> comparar si un iterador está antes o después de otro
*/

void ejemplo008(){
    vector<int> v = {1, 2, 3, 4, 5};
    string s = "Hola Mundo";

    auto it1 = v.begin();
    auto it2 = s.begin();

    cout << *it1 << endl; // 1
    cout << *it2 << endl; // H

    it1++;
    it2++;

    cout << *it1 << endl; // 2
    cout << *it2 << endl; // o

    it1--;
    it2--;

    cout << *it1 << endl; // 1
    cout << *it2 << endl; // H
}

/*
    -> Contenedores Asociativos
        - Asocian un valor (value) con una referencia (key)
        - Cada elemento tiene pares ordenados (Tupla) -> (key, value)
        - No se puede acceder a los elementos por índices

    * Tipos de contenedores asociativos
        - map: almacena los elementos ordenados por la key. No permite keys repetidas
        - set: almacena los elementos ordenados y no permite elementos repetidos
        - unordered_map: almacena los elementos sin ordenar por la key. No permite keys repetidas.
            + Están implementados como hash tables
            + Son más rápidos
        - unordered_set: almacena los elementos sin ordenar y no permite elementos repetidos.
            + Están implementados como hash tables
            + Son más rápidos
*/

/*
    MAP
    * Almacena los elementos ordenados por la key
    * No permite key repetidas
    * No se puede acceder a los elementos por índices
    * Está representado por un árbol binario
    * Se asemeja a un vector de tuplas (key, value)

    map<key, value> m = {{key, value}, {key, value}, ...};

    m[key] = value; -> Insertar un elemento
*/

void ejemplo009(){
    map<string, int> m = {{"Hola", 1}, {"Mundo", 2}};

    m["Hola"] = 3; // {{"Hola", 3}, {"Mundo", 2}}
    m["Chao"] = 4; // {{"Hola", 3}, {"Mundo", 2}, {"Chao", 4}}
}

/*
    SET
    * Almacena los elementos ordenados (key ~ value)
    * No permite elementos repetidos
    * No se puede acceder a los elementos por índices
    * Está representado por un árbol binario
    * Se asemeja a un vector de valores

    set<value> s = {value, value, ...};

    s.insert(value); -> Insertar un elemento
*/

void ejemplo010(){
    set<int> s = {1, 2, 3, 4, 4, 5}; // 1, 2, 3, 4, 5

    s.insert(6); // {1, 2, 3, 4, 5, 6}
}


int main(){

    return 0;
}
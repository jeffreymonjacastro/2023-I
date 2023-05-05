#include <iostream>
#include <algorithm>
#include <iterator>
#include <random>
#include <ctime>
#include <forward_list>

using namespace std;

void ejercicio001(){
    /* GENERAR UN VECTOR CON NÚMEROS ALEATORIOS ENTRE EL 0 y el 99 */
    vector<int> v(10);

    srand(time(nullptr));

    // Método 1: convencional
//    for (int i = 0; i < v.size(); ++i) {
//        v[i] = rand()%100;
//    }

    // Método 2: algorithm
    generate(v.begin(), v.end(), [](){return rand()%100;});

    for_each(v.begin(), v.end(), [](int i){cout<<i<<" ";});
    cout<<endl;

    /* ENCUENTRA EL MAYOR ELEMENTO DEL VECTOR */

    // Método 1: Iteradores

    vector<int>::iterator it = v.begin();

    int max_val = *it;
    for (it = next(v.begin()); it!=v.end(); it++)
        if (*it > max_val)
            max_val = *it;

    cout<< "max_val_it: " << max_val <<endl;

    // Método 2: Como un for
    int max = v[0];
    for_each(v.begin(),v.end(), [&](int x){(max < x) ? max = x : max;});

    // Método 3:
    it = max_element(v.begin(), v.end());

    cout << "max_val_for_it: "<< max << endl;


    /* HALLA EL PROMEDIO DEL VECTOR */

    float promedio = accumulate(v.begin(), v.end(), 0.0) / v.size();
    cout << "promedio: " << promedio << endl;

}


bool es_compuesto(int x){
    for (int i = 2; i < x; ++i) {
        if (x % i == 0)
            return true;
    }

    return false;
}

bool es_uno(int x){
    if (x == 1)
        return true;
    return false;
}


void ejercicio002(){
    /* CREAR UN FORWARD LIST CON 100 NÚMEROS ALEATORIOS */

    forward_list<int> lista;

    srand(time(nullptr));

    // Método 1: Convencional
//    for (int i = 0; i < 100; i++)
//        lista.push_front(rand()%99 + 1);

    // Método 2: Iteradores
    generate_n(front_inserter(lista), 100, [](){return rand()%99 + 1;});

    for_each(lista.begin(), lista.end(), [](int i){cout<<i<<" ";});
    cout<<endl;

    /* REMOVER TODOS LOS NÚMEROS QUE NO SEAN PRIMOS */
    lista.remove_if(es_compuesto); // El método remove_if recibe una función booleana


    lista.remove_if(es_uno);


    for_each(lista.begin(), lista.end(), [](int i){cout<<i<<" ";});
    cout<<endl;

    /* CUAL ES EL TAMAÑO DE LA LISTA */
    cout<< "lista[size] = " << distance(lista.begin(), lista.end()) << endl;
}


void append(forward_list<int> lista, int x) {
    auto it = lista.begin();
//
//    while(next(it) != lista.end())
//        it++;
//
//    lista.insert_after(it, x);


}

void ejercicio003(){
    /* Crear una función que tome como entrada un forward_list<int> y un entero x. Esta función debe agregar el elemento al final de la lista. */

    forward_list<int> list;

    srand(time(nullptr));

    generate_n(list.begin(),10,[](){return rand()%10;});

    for_each(list.begin(), list.end(), [](int i){cout<<i<<" ";});
    cout<<endl;

    int distancia = distance(list.begin(), list.end());

    cout << distancia;

//    append(list, 10);
//
//    for_each(list.begin(), list.end(), [](int i){cout<<i<<" ";});
//    cout<<endl;
}

int main() {
    //    ejercicio001();
    //    ejercicio002();
    ejercicio003();

    return 0;
}
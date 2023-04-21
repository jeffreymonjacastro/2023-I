// =============================================================================
// Tarea 1a: Matrices Dinamicas, Constructores y Sobrecarga de Operadores
// =============================================================================
// 1. Utilizar unicamente los archivos de cabecera y codigo fuente provistos. Es
//    decir: main.cpp, foo.h y foo.cpp.
// 2. No se permite el uso de librerias adicionales.

#include "foo.h"

// Puede validar su codigo con la siguiente funcion main



//template<typename... Ts>
//vector<tuple<Ts...>> vectupla(Ts... args){
//    return vector<tuple<Ts...>>{make_tuple(args...)};
//}
//
//
//template <size_t I = 0, typename... Ts>
//void imprimirTupla(const tuple<Ts...>& t) {
//    if constexpr (I < sizeof...(Ts)) {
//        cout << get<I>(t) << endl;
//        imprimirTupla<I + 1>(t);
//    }
//}


int main(){
    PyList l0;
    PyList l1(1,2.2, 'a', "Hello", true, l0);



    cout << len(l1) <<endl;












//    auto vect = vectupla(1,2.2,'a',"Hello",true, l1);
////
//    for(auto i:){
//        imprimirTupla(i);
//    }

}
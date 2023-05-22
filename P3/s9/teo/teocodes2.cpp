#include <iostream>
#include <future>

using namespace std;

int f1(){
    int s1 = 0;
    for (int i=0; i<200000000; i++)
        s1 += 1;
    return s1;
}
void foo(promise<int>* obj){
    int sum = 0;
    for (int i=0; i<100000000; i++)
        sum += 1;

    obj->set_value(sum);
}

int main(){
    // Se crea un objeto future que se encargará de almacenar el resultado de la función f1
    // Promise almacena el resultado de la función foo que se utilizará en un futuro


    promise<int> promise_obj;
    future<int> future_obj = promise_obj.get_future();

    // future<int> res = async(&f1); // Promise

    thread t1(foo, &promise_obj); // El obj promise funciona como contenedor

    t1.join();

    cout << "Respuesta f1 = " << f1() << endl;
    cout << "Respuesta foo = " << future_obj.get() << endl;
}

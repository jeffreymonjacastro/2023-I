#include <iostream>

using namespace std;

/* PILAS ESTÁTICAS */

template <class T>
class PilaEstatica {
private:
    static const int MAX = 3;
    int top_index;
    T stack[MAX];
public:
    PilaEstatica(): top_index(-1){} // Inicializa el top_index en -1

    bool empty(){ return top_index == -1; } // Si top_index es -1, la pila esta vacia

    bool full(){ return top_index == MAX - 1; } // Si top_index es MAX - 1, la pila esta llena

    void push(T elem){
        if(full()) {
            cout << "Error: Pila llena" << endl;    
            return;
        }
        // se preincrementa el top_index para que apunte a la siguiente posicion
        stack[++top_index] = elem;
    }

    void pop(){
        if(empty()) {
            cout << "Error: Pila vacia" << endl;
            return; // Se retorna un valor por defecto de tipo T
        }
        // se postdecrementa el top_index para que apunte a la posicion actual
        top_index--;
    }

    T top(){
        if(empty()) {
            cout << "Error: Pila vacia" << endl;
            return T();
        }
        return stack[top_index];
    }
};

int main(){
    PilaEstatica<int> p;

    p.push(2);
    p.push(3);
    p.push(4);
    p.push(5); // Salida: Error: Pila llena

    cout << "top = " << p.top() << endl; // Salida: top = 4
    p.pop();
    cout << "top = " << p.top() << endl; // Salida: top = 3


    return 0;
}
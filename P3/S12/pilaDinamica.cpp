#include <iostream>

using namespace std;

template <class T>
struct Nodo{
    T valor;
    Nodo<T>* next;
    Nodo(T valor, Nodo<T>* next): valor(valor), next(next){}
};

/*
template<typename T>
class Pila{
private:
    int size_pila;     // Numero de elementos en la pila
    Nodo<T>* nodo_top; // Puntero al primer nodo de la pila
public:
    Pila();         // Inicializa la pila con nodo_top = NULL
    ~Pila();        // Libera memoria de todos los nodos de la pila
    bool empty();   // Retorna true si la pila está vacía
    int size();     // Retorna el número de elementos en la pila
    void push(T);   // Agrega un elemento a la pila
    void pop();     // Elimina el elemento en el tope(TOP) de la pila
    T top();        // Retorna el elemento en el tope(TOP) de la pila
};
*/


template<typename T>
class Pila {
private:
    int size_pila; 
    Nodo<T>* nodo_top; 
public:
    Pila(): nodo_top(NULL), size_pila(0){}; 
    ~Pila();

    bool empty(){ return nodo_top == NULL; };
    int size(){ return size_pila; };

    void push(T elem){
        Nodo<T>* nuevo_nodo = new Nodo<T>(elem, nodo_top);
    }

    void pop(){

    }

    T top(){

    }
};


int main(){
    /* El primer nodo n1 tiene de valor el 3 y su next apunta a un null*/
    Nodo<int>* n1 = new Nodo<int>(3, NULL);
    cout << "valor = " << n1->valor << endl; // Salida: valor = 3

    /* El segundo nodo n2 tiene el valor de 5 y su next apunta al nodo n1 */
    Nodo<int>* n2 = new Nodo<int>(5, n1);
    cout << "valor = " << n2->valor << endl; // Salida: valor = 5

    cout << "valor = " << n2->next->valor << endl; // Salida: valor = 3

    Nodo<int>* n3 = new Nodo<int>(7, n2);
    cout << "valor = " << n3->valor << endl; // Salida: valor = 7
    cout << "valor = " << n3->next->valor << endl; // Salida: valor = 5
    cout << "valor = " << n3->next->next->valor << endl; // Salida: valor = 3
}

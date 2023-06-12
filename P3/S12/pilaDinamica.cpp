#include <iostream>

using namespace std;

/* PILAS DINÁMICASS */

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
    Nodo<T> *nodo_top;
public:
    Pila() : nodo_top(NULL), size_pila(0) {};

    bool empty() { return nodo_top == NULL; };

    int size() { return size_pila; };

    /* El metodo push() agrega un nuevo nodo al inicio de la pila (nodo_top), el nodo 'nuevo' ahora apunta
    al nodo que estaba en el tope de la pila (nodo_top). El elemento 'e' se guarda en el nodo 'nuevo'.
    Esta operación tiene complejidad constante O(1)*/

    void push(T elem) {
        Nodo<T> *nuevo_nodo = new Nodo<T>(elem, nodo_top);
        nodo_top = nuevo_nodo;
        size_pila++;
    }

    /* El metodo pop() elimina el nodo que esta en el tope de la pila (nodo_top) y libera la memoria del nodo
    eliminado. El nuevo tope de la pila es el nodo que estaba apuntado por el nodo eliminado.
    Esta operación tiene complejidad constante O(1) */

    void pop() {
        if (empty()) {
            cout << "Error: Pila vacia" << endl;
            return;
        }
        Nodo<T> *temp = nodo_top;
        nodo_top = nodo_top->next;
        delete temp;
        size_pila--;
    }

    /*El método top() retorna el elemento que esta en el tope de la pila (nodo_top) sin eliminarlo.
    Esta operación tiene complejidad O(1)*/
    T top() {
        if(empty()) {
            cout << "Error: Pila vacia" << endl;
            return T();
        }
        return nodo_top->valor;
    }

    /* El destructor libera la memoria de todos los nodos de la pila usando el metodo pop()
    hasta que la pila este vacia. Esta operación tiene complejidad lineal O(n) */
    ~Pila(){
        while(!empty()){
            pop();
        }
    };
};


void nodos(){
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

int main(){
    Pila<int> pila;
    pila.push(2); // |2|
    pila.push(4); // |2|4|
    pila.push(3); // |2|4|3|
    cout << pila.top() << endl; // 3

    pila.pop();   // |2|4|
    pila.push(9); // |2|4|9|
    pila.pop();   // |2|4|
    cout << "size = " << pila.size() << endl; // size = 2
    cout << pila.top() << endl; // 4

    return 0;
}

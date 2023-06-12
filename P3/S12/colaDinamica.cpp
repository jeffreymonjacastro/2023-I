#include <iostream>

using namespace std;

/* COLAS (QUEUE) DINÁMICASS */

template <class T>
struct Nodo{
    T valor;
    Nodo<T>* next;
    Nodo(T valor, Nodo<T>* next): valor(valor), next(next){}
};

/*
template<typename T>
class Cola{
private:
    int size_cola;       // Numero de elementos en la cola
    Nodo<T>* nodo_front; // Puntero al frente de la cola
    Nodo<T>* nodo_back;  // Puntero al final de la cola
public:
    Cola();
    bool empty();  // Retorna true si la cola esta vacia
    int size();    // Retorna el numero de elementos en la cola
    T front();     // Retorna el elemento en el frente de la cola
    T back();      // Retorna el elemento en el final de la cola
    void push(T);  // Agrega un elemento al final de la cola
    void pop();    // Elimina el elemento en el frente de la cola
*/

template<typename T>
class Cola {
private:
    int size_cola;
    Nodo<T>* nodo_front; // Indice que apunta al frente de la cola
    Nodo<T>* nodo_back; // Indice que apunta al final de la cola
public:
    /* El constructor inicializa los atributos de la clase donde 'nodo_front' y
    'nodo_back' apuntan a NULL y 'size_cola' es 0 */
    Cola(): size_cola(0), nodo_front(nullptr), nodo_back(nullptr){}

    bool empty(){ return nodo_front == nullptr; }

    int size(){ return size_cola; }

    /* El método front() retorna el elemento en el frente de la cola */
    T front(){ return nodo_front->valor; }

    /* El metodo back() retorna el elemento en el final de la cola */
    T back(){ return nodo_back->valor; }

    /* El metodo push() agrega un nuevo nodo al final de la cola, el nodo 'nuevo' ahora apunta a NULL y el
    elemento 'e' se guarda en el nodo 'nuevo'. Si la cola esta vacia (nodo_front == NULL) entonces el
    nodo 'nuevo' tambien es el frente de la cola (nodo_front = nuevo) y si la cola no esta vacia entonces el
    nodo 'nuevo' se agrega al final de la cola (nodo_back->next = nuevo) y el nodo 'back' ahora apunta al
    nodo 'nuevo' (nodo_back = nuevo) */
    void push(T elem){
        Nodo<T>* nuevo_nodo = new Nodo<T>(elem, nullptr);
        if(empty()) {
            nodo_front = nuevo_nodo;
        } else {
            nodo_back->next = nuevo_nodo;
        }
        nodo_back = nuevo_nodo;
        size_cola++;
    }

    /* El metodo pop() elimina el nodo en el frente de la cola (front) y el nodo 'nodo_front' ahora
    apunta al siguiente nodo en la cola (nodo_front = nodo_front->next). Si la cola esta vacia
    (nodo_front == NULL) entonces el nodo 'nodo_back' tambien es NULL (nodo_back = NULL) y si
    la cola no esta vacia entonces el nodo 'nodo_front' se elimina y el nodo 'nodo_back' no cambia*/
    void pop(){
        if(!empty()){
            Nodo<T>* tmp = nodo_front;
            nodo_front = nodo_front->next;
            delete tmp;
            size_cola--;
            if(empty()) {
                nodo_back = nullptr;
            }
        }
    }

    /* El destructor elimina todos los nodos de la cola */
    ~Cola(){
        while(!empty()){
            pop();
        }
    }
};

int main(){
    Cola<int> cola;
    cola.push(7); //    |7|
    cola.push(2); //    |7|2|
    cola.push(5); //    |7|2|5|
    cola.pop();   //    |2|5|
    cout << cola.front() << endl; // 2
    cout << cola.back() << endl;  // 5
}
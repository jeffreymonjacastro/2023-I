#include <iostream>
#include <queue>

using namespace std;

struct Nodo {
    int valor;
    Nodo* next;

    Nodo(int valor, Nodo* next): valor(valor), next(next){}
};

class MinMaxStack {
private:
    Nodo* nodo_top;
    int size_stack;
    int min_valor;
    int max_valor;
public:
    MinMaxStack(): nodo_top(nullptr), size_stack(0){}

    bool empty(){ return nodo_top == nullptr; }

    int size(){ return size_stack; }

    void push(int elem){
        Nodo* nuevo_nodo = new Nodo(elem, nodo_top);
        nodo_top = nuevo_nodo;
        size_stack++;

        if(size_stack == 1){
            min_valor = elem;
            max_valor = elem;
        } else {
            if(elem < min_valor){
                min_valor = elem;
            }

            if(elem > max_valor){
                max_valor = elem;
            }
        }
    }

    int top() {
        if(empty()){
            cout << "Error: Pila vacia" << endl;
            return 0;
        }
        return nodo_top->valor;
    }

    int min(){
        if(empty()){
            cout << "Error: Pila vacia" << endl;
            return 0;
        }
        return min_valor;
    }

    int max(){
        if(empty()){
            cout << "Error: Pila vacia" << endl;
            return 0;
        }
        return max_valor;
    }


    void pop(){
        if(empty()){
            cout << "Error: Pila vacia" << endl;
            return;
        }

        Nodo* temp = nodo_top;
        nodo_top = nodo_top->next;

        if (temp->valor == min_valor){
            if (nodo_top == nullptr)
                return;

            min_valor = nodo_top->valor;
            Nodo* temp2 = nodo_top;

            // No sé hacerlo en O(1)
            while(temp2 != nullptr){
                if(temp2->valor < min_valor){
                    min_valor = temp2->valor;
                }


                temp2 = temp2->next;
            }
            delete temp2;

        }

        delete temp;

        size_stack--;
    }

    ~MinMaxStack(){
        while(!empty()){
            pop();
        }
    };
};


int main(){
    MinMaxStack pila;

    pila.push(5);
    pila.push(3);
    pila.push(7);
    pila.push(1);
    pila.push(2);
    pila.pop();
    pila.pop();
    pila.pop();

    cout << "Top: " << pila.top() << endl;
    cout << "Min: " << pila.min() << endl;
    cout << "Max: " << pila.max() << endl;

    return 0;
}
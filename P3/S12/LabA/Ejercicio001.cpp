#include <iostream>
#include <stack>

using namespace std;

//template <class T>
//struct Nodo{
//    T valor;
//    Nodo<T>* next;
//    Nodo(T valor, Nodo<T>* next): valor(valor), next(next){}
//};
//
//template<typename T>
//class Pila {
//private:
//    int size_pila;
//    Nodo<T>* nodo_top;
//public:
//    Pila() : nodo_top(nullptr), size_pila(0) {};
//
//    bool empty() { return nodo_top == nullptr; };
//
//    int size() { return size_pila; };
//
//    void push(T elem) {
//        Nodo<T> *nuevo_nodo = new Nodo<T>(elem, nodo_top);
//        nodo_top = nuevo_nodo;
//        size_pila++;
//    }
//
//    void pop() {
//        if (empty()) {
//            cout << "Error: Pila vacia" << endl;
//            return;
//        }
//        Nodo<T>* temp = nodo_top;
//        nodo_top = nodo_top->next;
//        delete temp;
//        size_pila--;
//    }
//
//    T top() {
//        if(empty()) {
//            cout << "Error: Pila vacia" << endl;
//            return T();
//        }
//        return nodo_top->valor;
//    }
//
//    ~Pila(){
//        while(!empty()){
//            pop();
//        }
//    }
//};

string validarParentesis(string s){
    stack<char> pila;

    for (char c: s){
        if(c == '[' || c == '(' || c == '{')
            pila.push(c);
        else if(c == ']' || c == ')' || c == '}'){
            if(pila.empty())
                return "Error: Operacion incorrecta!";

            char top = pila.top();
            pila.pop();

            if((c == ']' && top != '[') || (c == ')' && top != '(') || (c == '}' && top != '{'))
                return "Error: Operacion incorrecta!";
        }
    }

    if(!pila.empty())
        return "Error: Operacion incorrecta!";
    return "Operacion correcta!";
}


int main(){
    string cadena1 = "]1+(3*5)-3]}";
    cout << validarParentesis(cadena1) << endl;
    // Error: Operacion incorrecta!

    string cadena2 = "{1+[1-(3*4)/7]";
    cout << validarParentesis(cadena2) << endl;
    // Error: Operacion incorrecta!

    string cadena3 = "[1+(5*2)]";
    cout << validarParentesis(cadena3) << endl;
    // Operacion correcta!


    return 0;
}

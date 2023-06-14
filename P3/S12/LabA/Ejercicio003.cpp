#include <iostream>
#include <stack>

using namespace std;

class EditorTexto{
private:
    string texto;
    stack<string> pila;
public:
    EditorTexto(){}

    void agregarTexto(string newtexto){
        pila.push(texto);
        texto += newtexto;
    }

    string getTexto(){
        return texto;
    }

    void deshacer() {
        if (!pila.empty()) {
            texto = pila.top();
            pila.pop();
        }
    }
};

int main(){
    EditorTexto editor;

    editor.agregarTexto("Hola ");
    cout << editor.getTexto() << endl; // Salida: Hola

    editor.agregarTexto("Mundo ");
    editor.agregarTexto("en C++");
    cout << editor.getTexto() << endl; // Salida: Hola Mundo en C++

    editor.deshacer();
    cout << editor.getTexto() << endl; // Salida: Hola Mundo

    editor.deshacer();
    cout << editor.getTexto() << endl; // Salida: Hola

    return 0;
}
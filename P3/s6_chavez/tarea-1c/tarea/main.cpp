// =============================================================================
// Tarea 1a: Matrices Dinamicas, Constructores y Sobrecarga de Operadores
// =============================================================================
// 1. Utilizar unicamente los archivos de cabecera y codigo fuente provistos. Es
//    decir: main.cpp, foo.h y foo.cpp.
// 2. No se permite el uso de librerias adicionales.

#include "foo.h"

// Puede validar su codigo con la siguiente funcion main
int main(){
    string richtext;
    ifstream doc("The Y2K Saga.html");

    if(doc.is_open()){
        while(getline(doc, richtext))
            cout << richtext << endl;
        doc.close();
    } else {
        cout << "No se pudo abrir el archivo" << endl;
    }

}
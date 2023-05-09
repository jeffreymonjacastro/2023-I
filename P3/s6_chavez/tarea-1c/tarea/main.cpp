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
    ifstream doc("document.html");

    if(doc.is_open()){
        string linea;

        while(getline(doc, linea))
            richtext += linea;

        doc.close();

    } else {
        cout << "No se pudo abrir el archivo" << endl;
    }

    cout << richtext << endl;




    return 0;
}
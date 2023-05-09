// =============================================================================
// Tarea 1a: Matrices Dinamicas, Constructores y Sobrecarga de Operadores
// =============================================================================
// 1. Utilizar unicamente los archivos de cabecera y codigo fuente provistos. Es
//    decir: main.cpp, foo.h y foo.cpp.
// 2. No se permite el uso de librerias adicionales.

#include "foo.h"

// Puede validar su codigo con la siguiente funcion main
int main(){
//    string richtext;
//    ifstream doc(R"(C:\Users\Usuario\Github\2023-I\P3\s6_chavez\tarea-1c\tarea\document.html)");
//
//    if(doc.is_open()){
//        string linea;
//
//        while(getline(doc, linea))
//            richtext += linea + "\n";
//
//        doc.close();
//
//    } else {
//        cout << "No se pudo abrir el archivo" << endl;
//    }
//
//    cout << richtext << endl;


    regex pattern("<body>");

    smatch match;

    string text = "<head> Hola mundo </head> <body>/..--.123456Hola mundo como estas xd123</body>";

    bool found = regex_search(text, match, pattern);

    if(found){
        sregex_iterator iter(text.begin(), text.end(), pattern);
        sregex_iterator end;

        while (iter != end){
            string match_str = iter->str();
            cout << match_str;
            iter++;
        }
    }



    return 0;
}
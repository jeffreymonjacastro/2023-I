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
    ifstream doc(R"(C:\Users\Usuario\Github\2023-I\P3\s6_chavez\tarea-1c\tarea\document.html)");

    if(doc.is_open()){
        string linea;

        while(getline(doc, linea))
            richtext += linea + "\n";

        doc.close();

    } else {
        cout << "No se pudo abrir el archivo" << endl;
    }

    // todo: Para quitar todo lo que está arriba del <head>

    string newtext;

    for (int i = 0; i < richtext.size(); ++i) {
        string subtext = richtext.substr(i,5);

        if (subtext == "<body")
            for (int j = i; j < richtext.size(); ++j) {
                newtext += richtext[j];
            }
    }

    cout << newtext << endl;

    regex pattern("[a-z][A-Z]");

    smatch match;

    bool found = regex_search(newtext, match, pattern);

    if(found){
        sregex_iterator iter(newtext.begin(), newtext.end(), pattern);
        sregex_iterator end;

        while (iter != end){
            string match_str = iter->str();
            cout << match_str;
            iter++;
        }
    }



    return 0;
}
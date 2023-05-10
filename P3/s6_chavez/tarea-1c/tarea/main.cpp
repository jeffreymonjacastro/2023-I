// =============================================================================
// Tarea 1a: Matrices Dinamicas, Constructores y Sobrecarga de Operadores
// =============================================================================
// 1. Utilizar unicamente los archivos de cabecera y codigo fuente provistos. Es
//    decir: main.cpp, foo.h y foo.cpp.
// 2. No se permite el uso de librerias adicionales.

#include "foo.h"

// Puede validar su codigo con la siguiente funcion main
int main() {
    Counter C("C:\\Users\\Usuario\\Github\\2023-I\\P3\\s6_chavez\\tarea-1c\\tarea\\document.html");





//    // todo: Código para leer el html como un archivo
//
//    string richtext;
//
//    ifstream doc(R"(C:\Users\Usuario\Github\2023-I\P3\s6_chavez\tarea-1c\tarea\document.html)");
//
//    if (doc.is_open()) {
//        string linea;
//
//        while (getline(doc, linea))
//            richtext += linea + "\n";
//
//        doc.close();
//
//    } else {
//        cout << "No se pudo abrir el archivo" << endl;
//    }
//
//
//    // todo: Para quitar todo lo que está arriba del <head>
//
//    string newtext;
//
////    for(int i = 0; i < richtext.size(); i++){
////        if (richtext.substr(i,5) == "<body"){
////            richtext.erase(0,i);
////            break;
////        }
////    }
//
//    auto it = richtext.begin();
//    while (it != richtext.end()) {
//        if (string(it, it+5) == "<body") {
//            richtext.erase(richtext.begin(), it);
//            break;
//        }
//        ++it;
//    }
//
//
//    // todo: Código para eliminar las etiquetas <html>
//
//    bool pos = true;
//
//    for (auto it = richtext.begin(); it != richtext.end(); it++) {
//        if (*it == '<') {
//            pos = false;
//        } else if (pos) {
//            if (*it == '\n')
//                newtext += " ";
//            else
//                newtext += *it;
//        } else if (*it == '>' && !pos) {
//            pos = true;
//        }
//    }
//
//    // todo: Código para leer solamente alfanuméricos con RegEx
//
//    string prolijtext;
//
//    regex pattern("[a-z A-Z \\']");
//
//    sregex_iterator iter(newtext.begin(), newtext.end(), pattern);
//    sregex_iterator end;
//
//    while (iter != end){
//        prolijtext += iter->str();
//        iter++;
//    }
//
//    cout << prolijtext;

    return 0;
}
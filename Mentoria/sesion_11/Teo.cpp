#include <iostream>
#include <fstream>
#include <sstream> // stringstream
#include <vector>

/* Fstream es la librería que se utiliza para escribir y leer

    fstream: para ambos (lectura/escritura)
    - ios::in -> Lectura
    - ios::out -> Escritura
    - ios::app -> Modificar archivo

    Leer: ifstream
    Funciona solo cuando existe la ruta del archivo. Sino va a salir error.
         ifstream data("ruta del archivo")

    Escribir: ofstream
    Escribe en el archivo de la ruta. Si no encuentra el archivo, crea uno.
        oftream salida("ruta del archivo")

    Modificar: fstream
    Modifica el archivo escribiendo debajo. Si no encuentra el archivo, lo crea.
        fstream modify("ruta del archivo", ios::app)
 */

using namespace std;

int main(){
    // Escribir (Salida)
    fstream salida(R"(C:\Users\Usuario\Github\2023-I\Mentoria\sesion_11\salida.txt)", ios::out);


    for (int i = 0; i < 3; ++i) {
        string texto;
        getline(cin,texto); // Leer everything lo que escribes con espacio y everything
        salida << texto + "\n";
    }

    salida.close();


    // Leer (Entrada)
    fstream data(R"(C:\Users\Usuario\Github\2023-I\Mentoria\sesion_11\salida.txt)", ios::in);

    vector<string> words;
    if (data.is_open()){
        string linea;

        while(getline(data, linea)){
            string linea_separada;
            stringstream separado(linea);

            while(getline(separado,linea_separada, ',')){
                words.push_back(linea_separada);
            }
        }

    } else {
        cout << "No se pudo abrir" << endl;
    }

    for (int i = 0; i < words.size(); ++i) {
        if(i % 4 == 0){
            cout << words[i] << endl;
        }
    }

    data.close();


    return 0;
}
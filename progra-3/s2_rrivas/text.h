#ifndef INC_2023_I_TEXT_H
#define INC_2023_I_TEXT_H

#include <cstring>
#include <iostream>

using namespace std;

// Construcción explícita:
//      Text t1("hola");
// Construcción implícita (asignación):
//      t1 = "hola";

class Text {
    char* _data = nullptr;
    int _sz = 0;
public:
    // Constructor por defecto
    // (Los atributos deben estar inicializados/definidos para utilizar este constructor)
    // Text t1;
    Text() = default;

    // Constructor con parámetros
    // (Los parámetros recibidos por el constructor deben rellenar los atributos de la clase)
    // Text t1("hola");
    Text(const char* text){
        _sz = strlen(text); //strlen sirve para hallar el largo de un string
        _data = new char[_sz + 1];
        strcpy(_data, text); //strcpy copia todos los valores de un array a otro
    };

    // Constuctor Copy
    // (Se debe copiar todos los atributos correctamente)
    // Text t1 = "UTEC";
    // Text t2 = t1; (Asignación)
    // t1 = "Hola";
    Text(const Text& other){
        this->_sz = other._sz;
        // this->_data = other._data; (Si se hace de esta forma, tanto el _data anterior como el actual apuntan a la misma dirección)
        this->_data = new char[_sz + 1];
        strcpy(_data, other._data);
    };

    // Constructor assigment Copy
    // (Este constructor devuelve una referencia a uno mismo, por ello debe retornar una dereferencia)
    // Text t1 = "UTEC";
    // Text t2 = "Hello";
    // t2 = t1;
    Text& operator=(const Text& other){
        // OJITO (rivas truco) [this es como la clase actual]
        if(this == &other)
            return *this;
        this->_sz = other._sz;
        delete [] this->_data; // En este caso se debe eliminar la memoria del anterior antes de copiar
        this->_data = new char[_sz + 1];
        strcpy(_data, other._data);
        // *this es para devolver la dereferencia del constructor
        return *this;  // Constructores = funciones, aceptan return
    };

    // Constructor Move
    // (Los rvalue no tienen nombre)
    // Text t1 = Text("Hola");
    // auto getText(const char* pt){
    //     return Text(pt);
    // }
    // Text t2 = getText("Hola UTEC");
    Text(Text&& other) noexcept{ // No hay excepción en move
        this->_sz = other._sz;
        this->_data = other._data; // Aquí sí aplica
        // Se elimina el objeto temporal
        other._sz = 0;
        other._data = nullptr;
    };

    // Constructor assigment move
    // Text t1 = "Hola";
    // t1 = Text("UTEC");
    // t1 = std::move(t1);
    Text& operator=(Text&& other) noexcept{
        _sz = other._sz;
        delete [] _data;
        _data = other._data;
        other._sz = 0;
        other._data = nullptr;
        return *this;
    };

    // Bonus: para recibir un string de parámetro y pasar de string a clase Text
    Text(const string& text){

    };

    // Sobrecargar la salida
    friend istream& operator>>(istream& in, Text& text);
    friend istream& getline(istream& in, Text& text);

    // Pasar de objeto a string
    // Text t1 = "Hola";
    // string t2 = t1;
    operator string();
};

istream& operator>>(istream& in, Text& text);
istream& getline(istream& in, Text& text);

#endif //INC_2023_I_TEXT_H

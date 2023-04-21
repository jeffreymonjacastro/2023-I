#include <iostream>
#include <vector>
#include <string>
#include <type_traits>

using namespace std;

class PyList{
private:
    int length; // El largo de la lista

    vector<string> myList;

    string toString() const {
        string result = "[";
        for (const auto& elem : myList) {
            result += elem + ",";
        }

        result.back() = ']';
        return result;
    }

    template<typename T>
    void addToList(T elem) {
        if constexpr (is_same<T, PyList>()) {
            myList.push_back(elem.toString());
        } else {
            if constexpr (is_same<T,const char*>()){
                myList.push_back(elem);
            } else {
                myList.push_back(to_string(elem));
            }
        }
    }

    template<typename T, typename... Rest>
    void addToList(T elem, Rest... rest) {
        if constexpr (is_same<T, PyList>()) {
            myList.push_back(elem.toString());
        } else {
            if constexpr (is_same<T,const char*>()){
                myList.push_back(elem);
            } else {
                myList.push_back(to_string(elem));
            }
        }
        addToList(rest...);
    }


public:

    // Constructor por defecto
    PyList(){length = 0;}


    // Constructor de asignación
    template<typename... Args>
    PyList(Args... args){
        length = sizeof...(args); // Se asigna al length el largo del paquete
        addToList(args...);
    }

    vector<string> getMyList(){
        return myList;
    }

    template<typename T>
    T get(int index) const {
        if constexpr (is_same<T, int>()) {
            return stoi(myList[index]);
        } else if constexpr (is_same<T, double>()) {
            return stod(myList[index]);
        } else if constexpr (is_same<T, char>()) {
            return myList[index][0];
        } else if constexpr (is_same<T, const char*>()) {
            return myList[index].c_str();
        } else if constexpr (is_same<T, bool>()) {
            return (myList[index] == "true" || myList[index] == "1");
        } else if constexpr (is_same<T, PyList>()) {
            return PyList(myList[index]);
        } else {
            static_assert(is_same<T, void>(), "Invalid type");
        }
    }


    // Método append para agregar elementos
    template<typename T>
    void append(T t){
        length += 1;
    }

    // Sobrecarga al operador de igualdad para comparar dos elemento
    bool operator==(const PyList& l) const{
        // TODO
    }

    // Método para devolver un subconjunto de una lista
    PyList from_to(int i, int j) const{
        // TODO
    }

    // Sobrecarga al operador [] para la búsqueda de índices
    template<typename T>
    T& operator[](size_t t){
        // TODO
    }

    // Sobrecarga constante?
    template<typename T>
    const T& operator[](T t) const{
        // TODO
    }

    // Función amiga para imprimir los elementos
    friend ostream& operator<<(ostream& os, const PyList& l);

    // Función amiga para calcular el largo de la lista
    friend int len(const PyList& l);


};


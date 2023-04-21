#include <iostream>
#include <vector>
#include <type_traits>

using namespace std;





class PyList{
private:
    int length; // El largo de la lista

    std::vector<std::string> myList;

    template<typename T>
    void addToList(T elem) {
        if constexpr (is_same<T, PyList>()) {
            myList.push_back(elem.toString());
        } else {
            myList.push_back(to_string(elem));
        }
    }

    template<typename T, typename... Rest>
    void addToList(T elem, Rest... rest) {
        if constexpr (is_same<T, PyList>()) {
            myList.push_back(elem.toString());
        } else {
            myList.push_back(to_string(elem));
        }
        addToList(rest...);
    }

    string toString() const {
        string result = "[";
        for (const auto& elem : myList) {
            result += elem + ",";
        }
        result.back() = ']';
        return result;
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

//    template<typename T>
//    T get(int index) const {
//        static_assert(myList.size() > index, "Index out of range");
//        if constexpr (std::is_same<T, int>) {
//            return std::stoi(myList[index]);
//        } else if constexpr (std::is_same<T, double>) {
//            return std::stod(myList[index]);
//        } else if constexpr (std::is_same<T, char>) {
//            return myList[index][0];
//        } else if constexpr (std::is_same<T, const char*>) {
//            return myList[index].c_str();
//        } else if constexpr (std::is_same<T, bool>) {
//            return (myList[index] == "true" || myList[index] == "1");
//        } else if constexpr (std::is_same<T, PyList>) {
//            return PyList(myList[index]);
//        } else {
//            static_assert(std::is_same<T, void>, "Invalid type");
//        }
//    }

    void print() const {
        for (const auto& elem : myList) {
            cout << elem << " ";
        }
        cout << std::endl;
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


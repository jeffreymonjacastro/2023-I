#include <iostream>
#include <vector>

using namespace std;

template<typename T = int>
class MiLista {
private:
    vector<T> content;
public:
    MiLista() {};

    template<typename... Args>
    explicit MiLista(Args... args) {
        (content.push_back(args), ...);
    }

    // Sirve para hacer operaciones unarias sucesivas
    MiLista &operator<<(T element) {
        content.push_back(element);
        return *this;
    }

    // Cuando se hace sobrecarga dentro de una clase, la clase misma (this->) también es un operador, por lo que se recibe un parámetro de la función.
    MiLista operator+(MiLista<T> Other){
        MiLista<T> result;
        for (int i = 0; i < this->content.size(); ++i)
            result<<content[i];

        for (int i = 0; i < Other.content.size(); ++i)
            result<<Other.content[i];

        return result;
    }

//    template<typename T2>
//    friend MiLista<T2> operator+(MiLista<T2> l1, MiLista<T2> l2);

    template<typename T1>
    friend ostream& operator<<(ostream& os, const MiLista<T1>& l);

};

template<typename T2>
MiLista<T2> operator+(MiLista<T2> l1, MiLista<T2> l2){
    MiLista<T2> result;

    for (int i = 0; i < l1.content.size(); ++i)
        result<<l1.content[i];

    for (int i = 0; i < l2.content.size(); ++i)
        result<<l2.content[i];

    return result;
}

template<typename T1>
ostream& operator<<(ostream& os, const MiLista<T1>& l){
    os << "[ ";

    for(auto i: l.content){
        os << i << " ";
    }

    os << "]";

    return os;
};


int main(){
    MiLista<> lista1;
    MiLista<int> lista2 (1);
    MiLista<float> lista3 (2.1 ,3.2 ,0.4);

    cout << lista1 << endl;
    cout << lista2 << endl;
    cout << lista3 << endl;

    lista1 << 2 << 5;
    lista2 << 9;

    cout << lista1 << endl;
    cout << lista2 << endl;

    MiLista<int> lista4 = lista1 + lista2;
    cout << lista4 << endl;


    return 0;
}
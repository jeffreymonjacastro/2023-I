#include <iostream>
#include <vector>

using namespace std;

template<typename T = int>
class MiLista {
private:
    vector<T> content;
public:
    MiLista(){};

    template<typename... Args>
    explicit MiLista(Args... args){
        (content.push_back(args),...);
    }

    // Sirve para hacer operaciones unarias sucesivas
    MiLista& operator<<(T element){
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
    }

    template<typename T1>
    friend ostream& operator<<(ostream& os, const MiLista<T1>& l);

};


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
    MiLista<int> lista2(1,2);
    MiLista<double> lista3(1.1,2.2,3.3);

    cout<<lista1<<endl;

    lista1<<1<<2<<3;

    cout<<lista1<<endl;


    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

template<typename... Ts>
class MiLista {
private:
    vector<Ts...> content;
public:
    MiLista(Ts... args){
        (content.emplace_back(args),...);
    }

    MiLista(){};

    template<typename T>
    friend ostream& operator<<(ostream& os, const MiLista<T>& l);

};


template<>
class MiLista<>{
public:
    MiLista(){};

    friend ostream& operator<<(ostream& os, const MiLista<>& l);
};

template<typename T>
ostream& operator<<(ostream& os, const MiLista<T>& l){
    os << "[ ";

    for(auto i: l.content){
        os << i << " ";
    }

    os << "]";

    return os;
};


ostream& operator<<(ostream& os, const MiLista<>& l){
    os << "[ ";

    os << "]";

    return os;
};


int main(){
    MiLista<> lista1;
    MiLista<int> lista2(1,2);

    cout<<lista1<<endl;

    cout<<lista2<<endl;

    return 0;
}
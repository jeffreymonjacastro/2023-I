#include <iostream>
#include <vector>
#include <any>


using namespace std;

class PyList {
private:
    int length;
    vector<any> box;
public:
    PyList(){
        length = 0;
    }

    template<typename... Args>
    PyList(Args... args){
        length = sizeof... (args);
        (box.emplace_back(args),...);
    }

    template<typename T>
    void append(T t) {
        box.emplace_back(t);
    }

    friend int len(const PyList& l);
    friend ostream& operator<<(ostream& os, const PyList& l);
};
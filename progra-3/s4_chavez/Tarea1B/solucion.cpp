#include <iostream>
#include <typeinfo>
#include <vector>
#include <assert.h>
#include <cmath>

using namespace std;

class PyList;

struct Data {
    void *p;
    char t;
    template <typename T> Data(T n) {
        p = new T(n);
        t = typeid(n).name()[0];
    }

    Data(const char *pc) {
        string s = pc;
        p = new string(s);
        t = 's';
    }

    bool operator==(const Data &other) const {
        if (t != other.t)
            return false;
        switch (t) {
            case 'i':
                return *(int *)p == *(int *)other.p;
            case 'd':
                return *(double *)p == *(double *)other.p;
            case 'b':
                return *(bool *)p == *(bool *)other.p;
            case 'c':
                return *(char *)p == *(char *)other.p;
            case 's':
                return *(string *)p == *(string *)other.p;
            default:
                return false;
        }
    }
    template<typename T>
    Data& operator=(T x){
        p = new T(x);
        t = typeid(x).name()[0];
        return *this;
    }

    friend ostream& print(ostream& os, const Data data);
    friend bool is_equal(const Data &data, float x);
};

bool is_equal(const Data &data, float x){
    float eps = 0.0001;
    if (abs(x - *(double*)data.p) < eps)
        return true;
    return false;
}

class PyList {
    friend ostream &operator<<(ostream &os, const PyList &item);
    friend int len(const PyList &item);
private:
    vector<Data> vec;
    int length=0;
public:
    PyList() {}
    template <typename... Ts> 
    PyList(Ts... args) {
        this->append(args...);
    }

    template<typename T>
    void append(T x){
        vec.push_back(Data(x));
        length++;
    }

    template<typename T, typename... Ts>
    void append(T x, Ts... args){
        vec.push_back(Data(x));
        length++;
        append(args...);
    }

    Data& operator[](int i){
        return vec[i];
    }

    const Data& operator[](int i) const{
        return vec[i];
    }

    PyList& operator=(const PyList& other){
        vec = other.vec;
        length = other.length;
        return *this;
    }

    PyList from_to(int i, int j){
        PyList res;
        for(int k=i; k<j; k++)
            res.append(vec[k]);
        return res;
    }
};

int len(const PyList &item) { return item.length; }

ostream& print(ostream& os, const Data data){
    switch (data.t){
        case 'i': os << *(int*)data.p; break;
        case 'd': os << *(double*)data.p; break;
        case 'b': os << *(bool*)data.p; break;
        case 'c': os << *(char*)data.p; break;
        case 's': os << *(string*)data.p; break;
        case '6': // typeid(PyList).name() -> 6PyList
            cout << *(PyList*)data.p;
            break;
        default: os << "unknown"; break;
    }
    return os;
}

ostream& operator<<(ostream& os, const PyList& item){
    if (item.length == 0){
        os << "[]";
        return os;
    }
    os << '[';
    for(int i=0; i<item.length-1; i++){
        print(os, item[i]);
        os <<',';
    }
    print(os, item[item.length-1]);
    os << ']';
    return os;
}

int main() {    
    cout << "\nConstructores" << endl;
    cout << "-------------------------------------" << endl;
    PyList l1;
    PyList l2(1,1.3);
    PyList l3(1,"hola",1.3,true,0,10,"mundo",'a');

    cout << l1 << endl;
    cout << l2 << endl;
    cout << l3 << endl;

    assert(len(l1) == 0);
    assert(len(l2) == 2);
    assert(len(l3) == 8);

    cout << "\nMetodos" << endl;
    cout << "-------------------------------------" << endl;
    l1.append(1.3);
    assert(len(l1) == 1);

    PyList l4("hola");
    l4.append(1.3);
    l4.append(2.3);
    assert(len(l4) == 3);

    PyList l5(1,"hola");
    l5.append(PyList(2,"mundo"));
    cout << l5 << endl;
    assert(len(l5) == 3);

    cout << "\nIndices" << endl;
    cout << "-------------------------------------" << endl;
    assert(is_equal(l3[2], 1.3));
    assert(l3[0] == 1);
    assert(l3[7] == 'a');
    
    
    l3[2] = 'x';
    l3[1] = 5;
    l3[7] = false;
    assert(l3[2] == 'x');
    assert(l3[1] == 5);
    assert(l3[7] == false);

    cout << l3 << endl;
    PyList l6 = l3;
    PyList l7 = l3.from_to(3,5);

    assert(l7[1] == l6[4]);

    return 0;
}
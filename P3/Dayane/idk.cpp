//
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//class Lista{
//    friend ostream& operator<<(ostream& os, const Lista& l);
//    friend int len(const Lista& l);
//private:
//    int length;
//public:
//    template<typename... Args>
//    Lista(Args... args){
//        length = sizeof...(args);
//    }
//
//    bool operator==(const Lista& l) const{
//        if (length != l.length){
//            return false;
//        }
//        for (int i=0; i<length; i++){
//            if ((*this)[i] != l[i]){
//                return false;
//            }
//        }
//        return true;
//    }
//
//    Lista from_to(int i, int j) const{
//        Lista result;
//        for (int k=i; k<j; k++){
//            result.append((*this)[k]);
//        }
//        return result;
//    }
//
//    template<typename T>
//    T& operator[](T t){
//        vector<T> args = {t};
//        return const_cast<T&>((*this)[args]);
//    }
//
//    template<typename T, typename... Args>
//    T& operator[](T t, Args... args){
//        vector<T> rest_args = {args...};
//        int idx = t;
//        for (T arg : rest_args){
//            idx = idx * length + arg;
//        }
//        return const_cast<T&>((*this)[idx]);
//    }
//
//    template<typename T>
//    const T& operator[](T t) const{
//        vector<T> args = {t};
//        return const_cast<const T&>((*this)[args]);
//    }
//
//    template<typename T, typename... Args>
//    const T& operator[](T t, Args... args) const{
//        vector<T> rest_args = {args...};
//        int idx = t;
//        for (T arg : rest_args){
//            idx = idx * length + arg;
//        }
//        return const_cast<const T&>((*this)[idx]);
//    }
//};
//
//class PyList : public Lista {
//public:
//    template<typename... Args>
//    PyList(Args... args) : Lista(args...) {}
//
//    template<typename T>
//    void append(T t){
//        (*this)[length] = t;
//        length++;
//    }
//
//};
//
//int len(const Lista& l){
//    return l.length;
//}
//
//ostream& operator<<(ostream& os, const Lista& l){
//    os << "[";
//    for (int i=0; i<len(l); i++){
//        if (i > 0){
//            os << ",";
//        }
//        os << l[i];
//    }
//    os << "]";
//    return os;
//}
//int main() {
//    PyList l1;
//    cout << len(l1) << endl; // 0
//    PyList l2(1, 1.3);
//    cout << len(l2) << endl; // 2
//    PyList l3(1, "hola", 1.3, true, 0, 10, "mundo", 'a');
//    cout << len(l3) << endl; // 8
//    l1.append(1.3);
//    cout << len(l1) << endl; // 1
//    PyList l2("hola");
//    l2.append(1.3);
//    l2.append(2.3);
//    cout << len(l2) << endl; // 3
//    PyList l4 = l2.from_to(1, 3);
//    cout << l4 << endl; // [hola
//}
#include "foo.h"

int len(const PyList& l){
    return l.length;
}

ostream& operator<<(ostream& os, const PyList& l){
    os << "[";
    for (int i = 0; i < l.length; i++) {
        os << l.box[i];
        if (i != l.length - 1) {
            os << ", ";
        }
    }
    os << "]";
    return os;
}
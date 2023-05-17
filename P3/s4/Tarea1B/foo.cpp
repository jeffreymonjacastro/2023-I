#include "foo.h"

int len(const PyList& l){
    return l.length;
}


ostream& operator<<(ostream& os, const PyList& l){
    os << '[';

    for (int i = 0; i < l.myList.size()-1; ++i) {
        cout<<l.myList[i]<<", ";
    }

    cout<<l.myList.back();

    os << ']';

    return os;
}


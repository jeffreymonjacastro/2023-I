#include <iostream>
#include <vector>

using namespace std;

class Padre {
protected:
    int x;
public:
    Padre(){}
    Padre(int _x): x(_x){}

    virtual void print(){
        cout << "Padre: " << x << endl;
    }

    friend void print(Padre *p);

    virtual ~Padre(){}
};

void print(Padre *p){
    cout << "Padre: " << p->x << endl;
}


class Hijo: public Padre {
private:
    int y;
public:
    Hijo(int _x, int _y){
        x = _x;
        y = _y;
    }

    void print() override{
        cout << "Hijo: " << x << " " << y << endl;
    }

    virtual ~Hijo(){}
};

class Hermano: public Padre {
private:
    int z;
public:
    Hermano(int _x, int _z): Padre(_x), z(_z){}

    void print(){
        cout << "Hermano: " << x << " " << z << endl;
    }

    virtual ~Hermano(){}
};

int main(){
    Padre *p = new Padre(1);
    Hijo *h1 = new Hijo(2, 3);
    Hijo *h2 = new Hijo(4, 5);
    Hermano *h3 = new Hermano(6, 7);

    vector<Padre*> vPadres = {p, h1, h2, h3};

    for (int i = 0; i < vPadres.size(); ++i) {
        vPadres[i]->print();
    }

    return 0;
}

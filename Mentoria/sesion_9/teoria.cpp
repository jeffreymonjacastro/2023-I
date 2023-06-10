#include <iostream>
#include <vector>

using namespace std;

class Poligono {
protected:
    int base;
    int altura;
public:
    Poligono() {}

    Poligono(int b, int h) : base(b), altura(h) {}

    virtual int calcularArea() {
        return base * altura;
    }

//    virtual void printName() = 0;

    virtual void print(){
        cout << base << " " << altura << endl;
    }

//    friend void print(Poligono* p);

    virtual ~Poligono(){}
};

//void print(Poligono* p){
//    cout << p->base << " " << p->altura << endl;
//}


class Triangulo: public Poligono {
private:
    string name;
public:
    Triangulo(int b, int h): Poligono(b, h){}

    int calcularArea() override {
        return (base * altura) / 2;
    }

    void printName(){
        cout << name << endl;
    }

    virtual ~Triangulo(){}
};


class Cuadrado: public Poligono {
private:
    string name;
public:
    Cuadrado(int b, int h): Poligono(b,h){}
};


int main(){
    auto t1 = new Triangulo(3,4);
    auto t2 = new Triangulo(5,6);
    auto c1 = new Cuadrado(2,2);
    auto c2 = new Cuadrado(3,3);

    vector<Poligono*> vec = {t1, t2, c1, c2};

    for (auto i: vec){
        i->print();
    }

    return 0;
}

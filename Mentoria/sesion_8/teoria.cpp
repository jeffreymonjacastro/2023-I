#include <iostream>
#include <vector>

using namespace std;

// ASOCIACIÓN
class Taxi {
private:
    string modelo;
public:
    Taxi(string s): modelo(s){}
};

class Chofer {
private:
    string name;
    Taxi* miTaxi;
public:
    Chofer(string s, Taxi* t): name(s), miTaxi(t){}
};


//int main(){
//    Taxi* Furgoneta = new Taxi("Nissan");
//
//    Chofer person1("Juancito", Furgoneta);
//
//
//    return 0;
//}


// COMPOSICIÓN

class Fecha {
public:
    int dia, mes, anhio;
    Fecha(){}
    Fecha(int d, int m, int a): dia(d), mes(m), anhio(a){}
};

class Hora {
public:
    int horas, minutos;
    Hora(){}
    Hora(int h, int m): horas(h), minutos(m){}
};

class Evento {
private:
    Fecha f_evento;
    Hora h_evento;
public:
    Evento(int a, int b, int c, int d, int e){
        f_evento = Fecha(a,b,c);
        h_evento = Hora(d,e);
    }

    void print(){
        cout << "Fecha: " << f_evento.dia << "/" << f_evento.mes << "/" << f_evento.anhio << endl;
        cout << "Hora: " << h_evento.horas << ":" << h_evento.minutos << endl;
    }
};

//int main(){
//    Evento fiestaFinDeParciales(15,07,2023,16,30);
//
//    fiestaFinDeParciales.print();
//}


// AGREGACIÓN
class Estudiante {
public:
    string name;
    int id;
    Estudiante(string s, int i): name(s), id(i){}
};

class UTEC {
public:
    int m2;
    vector<Estudiante*> Estudiantes;
    UTEC(int n): m2(n){}

    void agregar_estudiante(Estudiante* E){
        Estudiantes.push_back(E);
    }
};

//int main(){
//    Estudiante* e1 = new Estudiante("Pablito", 20201067);
//    Estudiante* e2 = new Estudiante("Maria", 20211088);
//    Estudiante* e3 = new Estudiante("Piedri", 20231033);
//
//    UTEC u1(2000);
//    u1.agregar_estudiante(e1);
//    u1.agregar_estudiante(e2);
//    u1.agregar_estudiante(e3);
//
//    for (int i = 0; i < u1.Estudiantes.size(); ++i) {
//        cout << u1.Estudiantes[i]->name << ": " << u1.Estudiantes[i]->id << endl;
//    }
//}


// HERENCIA
class Figura2D {
protected:
    int lados, vertices;
public:
    Figura2D(){}
    Figura2D(int l, int v): lados(l), vertices(v){}

    virtual ~Figura2D(){}

    // POLIMORFISMO
    virtual void printFigura() = 0;
};

class Triangulo: public Figura2D{
private:
    string color;
public:
    Triangulo(int l, int v, string c){
        lados = l;
        vertices = v;
        color = c;
    }

    void printFigura(){
        cout<<"Triangulo color "<<color<<endl;
    }

    virtual ~Triangulo(){}
};

class Cuadrado: public Figura2D{
private:
    string estampado;
public:
    Cuadrado(int l, int v, string e){
        lados = l;
        vertices = v;
        estampado = e;
    }

    void printFigura(){
        cout <<"Cuadrado con "<<estampado<<endl;
    }

    virtual ~Cuadrado(){}
};

int main(){
    auto t1 = new Triangulo(3, 3, "Rojo");
    auto t2 = new Triangulo(3, 3, "Verde");
    auto c1 = new Cuadrado(4,4,"Estrellitas");


    vector<Figura2D*> vec;

    vec.push_back(t1);
    vec.push_back(c1);
    vec.push_back(t2);

    for (int i = 0; i < vec.size(); ++i) {
        vec[i]->printFigura();
    }


}
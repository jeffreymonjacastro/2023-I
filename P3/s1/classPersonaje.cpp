#include <iostream>

using namespace std;

class Personaje {
private:
    string nombre;
    int vida;
    int ataque;
    int defensa;
    int magia;
public:
    Personaje(string n, int v, int a, int d, int m): nombre(n), vida(v), ataque(a), defensa(d), magia(m){}

    Personaje(const Personaje &newp){
        vida = newp.vida;
        ataque = newp.ataque;
        defensa = newp.defensa;
        magia = newp.magia;
    }

    void cambiarNombre(string newname){
        nombre = newname;
    }

    void mostrar(){
        if(nombre.empty())
            cout<<"El personaje no tiene un nombre" <<endl;
        else
            cout<<"Nombre: "<<nombre<<endl;

        cout<<"Vida: "<<vida<<endl;
        cout<<"Ataque: "<<ataque<<endl;
        cout<<"Defensa: "<<defensa<<endl;
        cout<<"Magia: "<<magia<<endl;
    }

    ~Personaje(){}
};

int main(){
    Personaje p1("Arthias", 100, 50, 30, 100);
    p1.mostrar();

    Personaje p2 = p1;
    p2.cambiarNombre("Jaina");

    p2.mostrar();
}
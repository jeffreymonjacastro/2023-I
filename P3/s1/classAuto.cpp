#include <iostream>

using namespace std;

class Auto {
private:
    string color;
    int precio;
    int kilometraje = 0;
public:
    Auto(string c, int p): color(c), precio(p){}

    Auto(const Auto &A){
        color = A.color;
        precio = A.precio;
        kilometraje = A.kilometraje;
    }

    void viajar(int k){
        kilometraje += k;
        precio -= k;

        cout<<"Cantidad de Kilometros recorridos: "<<this->kilometraje<<endl;
        cout<<endl;
    }

    ~Auto(){}

    friend void mostrar(const Auto &A);
};

void mostrar(const Auto &A){
    cout<<"Color del carro: "<<A.color<<endl;
    cout<<"Precio del carro: "<<A.precio<<endl;
    cout<<"Kilometraje del carro: "<<A.kilometraje<<endl;
    cout<<endl;
}

int main(){
    Auto a1("Rojo", 50000);
    mostrar(a1);
    Auto a2 = a1; // Constructor de copia

    a1.viajar(100);
    a1.viajar(250);
    mostrar(a1);

    mostrar(a2);

    a2.viajar(50);

    mostrar(a2);


    return 0;
}

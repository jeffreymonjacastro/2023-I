#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Dados{
private:
    int cantidad;
    int *valores;
public:
    // Constructor de asignación
    Dados(int c): cantidad(c){
        valores = new int[c];
    }

    // Constructor copia [Ctrl + c]
    Dados(const Dados &d){
        this->cantidad = d.cantidad;
        valores = new int[cantidad];
        for(int i = 0; i < cantidad; i++){
            valores[i] = d.valores[i];
        }
    }

    // Constructor de movimiento [Ctrl + x]
    Dados(Dados &&d){
        this->cantidad = d.cantidad;
        valores = d.valores;
        d.valores = nullptr;
    }

    void lanzar(){
        int suma = 0;
        srand(time(nullptr));
        for(int i = 0; i < cantidad; i++){
            valores[i] = rand()%6 +1;
            suma += valores[i];
        }

        if (suma / cantidad >= 4){
            cout<<"Ganaste!"<<endl;
        } else{
            cout << "Perdiste!" << endl;
        }
    }



    ~Dados(){
        delete [] valores;
    }
};

int main(){
    int cantidad;
    cout<<"cantidad de dados: "; cin>>cantidad;

    Dados d1(cantidad);
    d1.lanzar();
    d1.mostrar();

    Dados d2 = d1;
    d2.mostrar();

    Dados d3 = move(d1);
    d3.mostrar();


    return 0;
}

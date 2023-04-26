#include <iostream>

using namespace std;

class Obstaculo {
private:
    float x;
public:
    Obstaculo(float n): x(n){}

    float getX(){return x;}

    ~Obstaculo() = default;
};


class VehiculoAutonomo {
private:
    float x = 0;
    float v_x = 0;
    bool sentido = true; // Si es true es positivo, si es false es negativo
public:
    // Constructor de asignación
    VehiculoAutonomo(float n, float m): x(n), v_x(m){}

    ~VehiculoAutonomo() = default;

    VehiculoAutonomo operator>>(Obstaculo& O){
        if (sentido) {
            while (true) {
                this->x += this->v_x;

                if (this->x >= O.getX()) {
                    sentido = false;
                    break;
                }

                cout << "Avanzando... Posicion: " << this->x << endl;
            }
        } else {
            while (true) {
                this->x -= this->v_x;

                if (this->x <= O.getX()) {
                    sentido = true;
                    break;
                }

                cout << "Avanzando... Posicion: " << this->x << endl;
            }
        }

        cout << "Obstaculo detectado!" << endl;
        cout << "Girando..." << endl;

        return *this;
    }
};

int main(){
    VehiculoAutonomo v (0 , 1.3);
    Obstaculo o1 (10) ;
    // Avanzar
    v >> o1;

    Obstaculo o2 ( -20) ;
    v >> o2 ;

    return 0;
}
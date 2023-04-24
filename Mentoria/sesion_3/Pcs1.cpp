#include <iostream>
#include <cmath>

using namespace std;

struct punto {
    int x;
    int y;
};

struct cliente {
    int x1;
    int y1;
    int x2;
    int y2;
};

cliente menorRiesgo(int* horas, int* velocidad, int n){
    int origen = 0;
    int maximo = 1000;

    cliente tipocliente;

    int distancias_min[n];
    for (int i = 0; i < n; ++i) {
        distancias_min[i] = sqrt(pow(horas[i]-origen,2) + pow(velocidad[i]-origen,2));
    }

    int min = distancias_min[0];
    for (int i = 0; i < n; ++i) {
        if (distancias_min[i] < min){
            min = distancias_min[i];
        }
    }

    for (int i = 0; i < n; ++i) {
        if(min == distancias_min[i]){
            tipocliente.x1 = horas[i];
            tipocliente.y1 = velocidad[i];
        }
    }

    int distancias_max[n];
    for (int i = 0; i < n; ++i) {
        distancias_min[i] = sqrt(pow(horas[i]-maximo,2) + pow(velocidad[i]-maximo,2));
    }

    int max = distancias_max[0];
    for (int i = 0; i < n; ++i) {
        if (distancias_max[i] < max){
            max = distancias_max[i];
        }
    }

    for (int i = 0; i < n; ++i) {
        if(max == distancias_max[i]){
            tipocliente.x2 = horas[i];
            tipocliente.y2 = velocidad[i];
        }
    }

    return tipocliente;
}


int main() {
    int* horas = new int[10] {3, 1, 8, 9, 2, 2, 8, 1, 7,10};
    int* velocidad = new int[10] {50, 30,99,80,15,42,90,41,95,39};

    cliente client = menorRiesgo(horas,velocidad,10);

    cout<<"("<<client.x1<<","<<client.y1<<")"<<endl;
    cout<<"("<<client.x2<<","<<client.y2<<")"<<endl;



    return 0;
}
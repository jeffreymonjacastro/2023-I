#include <iostream>
#include <vector>
#include <stack>

using namespace std;

string validar(vector<stack<int>>& torres){
    int discoAnterior = INT_MIN;
    cout << discoAnterior << endl;

    for (auto& torre: torres) {
        while(!torre.empty()){
            if (torre.top() < discoAnterior)
                return "Configuracion incorrecta!";

            discoAnterior = torre.top();
            torre.pop();
        }

        discoAnterior = INT_MIN;
    }

    return "Configuracion correcta";
}

int main(){
    vector<stack<int>> torres(3); // 3 torres

    // Agregar discos a las torres (configuración de ejemplo)
    torres[0].push(3);  // Torre 1: Disco con radio 3
    torres[0].push(2);
    torres[0].push(1);
    cout <<  validar(torres) << endl; // Salida: Configuracion correcta!

    torres[1].push(5);  // Torre 2: Disco con radio 4
    torres[1].push(4);
    cout <<  validar(torres) << endl; // Salida: Configuracion incorrecta!

    torres[2].push(1e9);
    torres[2].push(0);
    cout <<  validar(torres) << endl; // Salida: Configuracion correcta!

    return 0;
}
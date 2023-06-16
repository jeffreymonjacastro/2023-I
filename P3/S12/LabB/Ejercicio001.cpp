#include <iostream>
#include <queue>

using namespace std;

class Banco {
private:
    queue<string> clientes;
public:
    Banco() = default;

    void agregarCliente(const string& nombre){
        clientes.push(nombre);
        cout << "Cliente " << nombre << " agregado." << endl;
    }

    void atenderCliente(){
        if(clientes.empty()){
            cout << "No hay clientes en espera." << endl;
            return;
        }

        cout << "Atendiendo: " << clientes.front() << endl;
        clientes.pop();
    }

    void mostrarClientesEnEspera(){
        if(clientes.empty()){
            cout << "No hay clientes en espera." << endl;
            return;
        }

        cout << endl << "Clientes en espera:" << endl;
        int i = 1;
        queue<string> clientesTemp = clientes;
        while(!clientesTemp.empty()){
            cout << i << ". " << clientesTemp.front() << endl;
            clientesTemp.pop();
            i++;
        }

        cout << endl;
    }

};

int main(){
    Banco banco;

    banco.agregarCliente("Juan");
    banco.agregarCliente("Maria");
    banco.agregarCliente("Pedro");
    banco.mostrarClientesEnEspera(); // 1. Juan 2. Maria 3. Pedro
    banco.atenderCliente();
    banco.mostrarClientesEnEspera(); // 1. Maria 2. Pedro
    banco.atenderCliente();
    banco.atenderCliente();
    banco.mostrarClientesEnEspera(); // No hay clientes en espera.

    return 0;
}
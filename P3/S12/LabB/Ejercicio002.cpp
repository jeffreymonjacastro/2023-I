#include <iostream>
#include <queue>

using namespace std;

class Solicitud {
private:
    int id;
    string descripcion;
public:
    Solicitud(int i, string s): id(i), descripcion(s){}

    friend class Servidor;
};

class Servidor {
private:
    queue<Solicitud> solicitudes;
public:
    Servidor() = default;

    void agregarSolicitud(Solicitud& soli){
        solicitudes.push(soli);

        cout << "Solicitud agregada - ID: " << solicitudes.back().id << endl;
    }

    void procesarSolicitudes(){
        cout << endl << "Procesando solicitudes..." << endl;
        while(!solicitudes.empty()){
            cout << "Solicitud procesada - ID: " << solicitudes.front().id;
            cout << ", Descripcion: " << solicitudes.front().descripcion << endl;
            solicitudes.pop();
        }
    }

};

int main(){
    Servidor servidor;

    Solicitud solicitud1(212, "Solicitud de acceso al sistema");
    Solicitud solicitud2(103, "Solicitud de actualizacion de datos");
    Solicitud solicitud3(111, "Solicitud de generacion de reporte");

    servidor.agregarSolicitud(solicitud1); // Salida: Solicitud agregada - ID: 212
    servidor.agregarSolicitud(solicitud2); // Salida: Solicitud agregada - ID: 103
    servidor.agregarSolicitud(solicitud3); // Salida: Solicitud agregada - ID: 111

    servidor.procesarSolicitudes();
    // Salida:
    // Procesando solicitudes...
    // Solicitud procesada - ID: 212, Descripcion: Solicitud de acceso al sistema
    // Solicitud procesada - ID: 103, Descripcion: Solicitud de actualizacion de datos
    // Solicitud procesada - ID: 111, Descripcion: Solicitud de generacion de reporte

}
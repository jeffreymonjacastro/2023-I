#include <iostream>
#include <vector>
#include <sstream>
#include <limits>

using namespace std;

class CVehiculo {
private:
    string placa;
    int anioFabricacion;
public:
    CVehiculo(){}
    CVehiculo(string s, int a): placa(s), anioFabricacion(a){}

    friend class CTransporte;
    friend class CTaxi;
    friend class CBus;

    ~CVehiculo(){}
};

class CTransporte {
protected:
    string tipo, pais, ciudad;
    CVehiculo vehiculo;
public:
    CTransporte(){}
    CTransporte(string t, string p, string c, string s, int a){
        tipo = t;
        pais = p;
        ciudad = c;
        vehiculo = CVehiculo(s, a);
    }

    friend class CApp;

    virtual void printInfo(){
        cout << "Tipo: " << tipo << " Pais: " << pais << " Ciudad: " << ciudad << " Placa: " << vehiculo.placa << " Anio: " << vehiculo.anioFabricacion << endl;
    };

    virtual ~CTransporte(){}
};

class CTaxi: public CTransporte {
public:
    CTaxi(){}
    CTaxi(string t, string p, string c, string s, int a): CTransporte(t,p,c,s,a){}

    void printInfo() override {
        cout << "Tipo: " << tipo << " Pais: " << pais << " Ciudad: " << ciudad << " Placa: " << vehiculo.placa << " Anio: " << vehiculo.anioFabricacion << endl;
    }

    virtual ~CTaxi(){}
};

class CBus: public CTransporte {
private:
    int pasajeros;
public:
    CBus(){}
    CBus(string t, string p, string c, string s, int a, int pas): CTransporte(t,p,c,s,a), pasajeros(pas){}

    void printInfo() override {
        cout << "Tipo: " << tipo << " Pais: " << pais << " Ciudad: " << ciudad << " Placa: " << vehiculo.placa << " Anio: " << vehiculo.anioFabricacion << " Pasajeros: " << pasajeros << endl;
    }

    virtual ~CBus(){}
};

class CApp {
private:
    string nombre;
    vector <CTransporte> transportes;
public:
    CApp(){}
    CApp(string n): nombre(n){}

    void operator<<(CTransporte& transport){
        transportes.push_back(transport);
    }

    void operator()(string s){
        int cont = 0;
        for(auto& i: transportes){
            if (i.ciudad == "Lima"){
                i.printInfo();
            }
        }
    }

    ~CApp(){}
};

int main(){
    string name;
    cout << "Ingresar nombre de la App: "; cin>>name;
    CApp App(name);

    int n;
    cout << "Cantidad de transportes: "; cin>>n;
    cout << "Ingrese los " << n << " transportes:" << endl;
    cin.ignore();

    while(n--){
        string frase;

        getline(cin, frase);

        istringstream iss(frase);

        vector<string> palabras;

        string palabra;
        while (iss >> palabra) {
            palabras.push_back(palabra);
        }

        if (palabras[0] == "Taxi"){
            CTaxi taxi(palabras[0], palabras[1], palabras[2], palabras[3], stoi(palabras[4]));
            App << taxi;
        } else {
            CBus bus(palabras[0], palabras[1], palabras[2], palabras[3], stoi(palabras[4]), stoi(palabras[5]));
            App << bus;
        }
    }

    string ciudad;
    cout << "Ingrese la ciudad a buscar:"; cin>>ciudad;

    App(ciudad);

    return 0;
}

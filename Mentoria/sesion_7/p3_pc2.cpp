// PC2 de José Chavez de 2022_2

#include <iostream>
#include <vector>

using namespace std;

class Curso {
private:
    string nombre;
    int ciclo;
    int creditos;
    vector<pair<string, int>> alumnos;

public:
    Curso(){};
    Curso(string n, int c, int cr): nombre(n), ciclo(c), creditos(cr){};

    void setAlumno(string name, int nota){
        pair<string, int> alumno;
        alumno.first = name;
        alumno.second = nota;

        alumnos.push_back(alumno);
    }

    double getProm(){
        double prom = 0;

        for (int i = 0; i < alumnos.size(); ++i) {
            prom += alumnos[i].second;
        }

        return prom / alumnos.size();
    }

    void printRecord(){
        cout << "Curso : " << nombre << endl;
        cout << "Ciclo : " << ciclo << endl;
        cout << "Creditos : " << creditos << endl;
        cout << endl;

        cout << "Alumno\tNota" << endl;

        for (int i = 0; i < alumnos.size(); ++i) {
            cout << alumnos[i].first << "\t-> " << alumnos[i].second << endl;
        }
    }

    ~Curso(){ cout << "FIN" << endl; };
};

int main(){
    Curso obj("Prog2", 2, 4);

    obj.setAlumno("Juan", 14);
    obj.setAlumno("Maria", 13);
    obj.setAlumno("Miguel", 11);
    obj.setAlumno("Elena", 17);

    cout << "El promedio es: " << obj.getProm() << endl;
    cout <<endl;
    obj.printRecord();
    cout<<endl;

    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

class Perro {
private:
    string name = "";
    int age = 0;

public:
    // Constructor por defecto
    Perro(){};

    //Perro() = default;

    // Constructor de asignación
    Perro(string _name){
        name = _name;
    }

    Perro(int _age){
        age = _age;
    }

    Perro(string _name, int _age){
        name = _name;
        age = _age;
    };

    //Perro(string nombre, int n): name(nombre), age(n){};

    //  Constructor de copia
    Perro(Perro& p){
        name = p.name;
        age = p.age;
    };

    // Destructor
    ~Perro(){};

    const string &getName() const {
        return name;
    }

    void setName(const string &name) {
        Perro::name = name;
    }

    int getAge() const {
        return age;
    }

    void setAge(int age) {
        Perro::age = age;
    }

    void printPerro(){
        cout << "Me llamo " << name << " y tengo " << age << " anios" << endl;
    }
};


int main() {
//    Perro aleman; // default
//
//    Perro pitbul("Firulais", 5); // asignación
//
//    Perro chihuahua(pitbul); // copy
//
//    aleman.setName("Juancito");
//    aleman.setAge(4);
//
//    aleman.printPerro();
//    pitbul.printPerro();

    // Objetos dinámicos

//    Perro pitbul("Roger", 10);
//
//    Perro* ptrPerro = &pitbul;
//
//    cout << ptrPerro->getName() << endl;
//
//    // Con new
//    Perro* chihuahua = new Perro("Firulais", 5);
//
//    cout << chihuahua->getAge() << endl;
//
//    // Contenedores de objetos
//    Perro* arrPerros = new Perro[5];
//
//    arrPerros[0] = Perro("Jaimito", 11);
//    arrPerros[1] = Perro("Tulio", 2);
//    arrPerros[2] = Perro("Juancito", 5);
//    arrPerros[3] = Perro("Maria", 3);
//    arrPerros[4] = Perro("Pelusa", 9);
//
//    for (int i = 0; i < 5; ++i) {
//        arrPerros[i].printPerro();
//    }
//
    vector<Perro*> jauriaPerros;

    string name;
    int age;

    for (int i = 0; i < 5; ++i) {
        cin>>name>>age;

        Perro* aleman = new Perro(name, age);

        jauriaPerros.push_back(aleman);
    }

    for (int i = 0; i < jauriaPerros.size(); ++i) {
        jauriaPerros[i]->printPerro();
    }






    return 0;
}

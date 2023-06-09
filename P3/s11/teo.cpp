#include <iostream>
#include <vector>

using namespace std;

/*  Ejemplo Iterator
En una aplicación de gestión de usuarios, necesitamos mostrar sus nombres almacenados
en una base de datos sin preocuparnos por cómo está implementada internamente.
Para ello, utilizaremos el patrón Iterator para recorrer la lista de usuarios
de manera sencilla y sin tener que conocer los detalles internos de la base de datos.
*/

class Usuario {
private:
    string nombre;
public:
    Usuario(const string& nombre) : nombre(nombre) {}

    string getNombre() const {
        return nombre;
    }
};

class DatabaseIterator {
private:
    vector<Usuario>& usuarios;
    int indice;
public:
    DatabaseIterator(vector<Usuario>& usuarios): usuarios(usuarios), indice(0){}

    Usuario& getCurrent() {
        return usuarios[indice];
    }
    void next() {
        indice++;
    }
    bool hasNext() {
        return indice < usuarios.size();
    }
};


class Database {
private:
    vector<Usuario> usuarios;

public:
    void agregarUsuario(const string& nombre) {
        usuarios.push_back(Usuario(nombre));
    }

    DatabaseIterator createIterator() {
        return DatabaseIterator(usuarios);
    }
};


int main(){
    Database database;
    database.agregarUsuario("Alice");
    database.agregarUsuario("Bob");
    database.agregarUsuario("Charlie");

    DatabaseIterator iterator = database.createIterator();
    while (iterator.hasNext()) {
        Usuario& usuario = iterator.getCurrent();
        cout << "Nombre de usuario: " << usuario.getNombre() << endl;
        iterator.next();
    }

    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

/*  EJEMPLO ITERATOR

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

void ejemploIterator(){
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
}


/* EJEMPLO MEMENTO

 En una aplicación de dibujo, necesitamos implementar la funcionalidad de deshacer/rehacer,
 que permita a los usuarios revertir y restaurar los cambios realizados en el lienzo.
 Utilizando el patrón Memento, implementar esta funcionalidad.

 */

class Memento {
private:
    string state;

public:
    Memento(const string& s) : state(s) {}

    string getState() const {
        return state;
    }
};

class Lienzo {
private:
    string contenido;

public:
    void dibujar(const string& figura) {
        cout << "Dibujando " << figura << endl;
        contenido += figura + ' ';
    }
    Memento guardarEstado() const {
        return Memento(contenido);
    }
    void restaurarEstado(const Memento& memento) {
        contenido = memento.getState();
    }
    string getContenido() const {
        return contenido;
    }
};

class Historial {
private:
    vector<Memento> estados;

public:
    void agregarEstado(const Memento& estado) {
        estados.push_back(estado);
    }

    Memento getEstadoAnterior() {
        if (estados.size() > 1) {
            estados.pop_back();
            return estados.back();
        }

        return Memento("");
    }
};


void ejemploMemento(){
    Lienzo lienzo;
    Historial historial;

    lienzo.dibujar("Cuadrado");
    historial.agregarEstado(lienzo.guardarEstado());

    lienzo.dibujar("Circulo");
    historial.agregarEstado(lienzo.guardarEstado());

    lienzo.dibujar("Triangulo");
    historial.agregarEstado(lienzo.guardarEstado());

    cout << "Estado actual del lienzo: " << lienzo.getContenido() << endl;

    Memento estadoAnterior = historial.getEstadoAnterior();
    lienzo.restaurarEstado(estadoAnterior); // Restaurar el estado anterior

    cout << "Estado actual del lienzo: " << lienzo.getContenido() << endl;
}


//int main(){
//
//}
#include <iostream>
#include <vector>

using namespace std;

class EstadoJuego {
private:
    string nombreNivel;
    int posicionX;
    int posicionY;

public:
    EstadoJuego(const string& nombreNivel, int posicionX, int posicionY)
            : nombreNivel(nombreNivel), posicionX(posicionX), posicionY(posicionY) {}

    string getNombreNivel() const { return nombreNivel;}
    int getPosicionX() const { return posicionX;}
    int getPosicionY() const { return posicionY;}
};

// Memento: Almacena los estados del juego
class Memento {
private:
    EstadoJuego estado;
public:
    Memento(const EstadoJuego& estado) : estado(estado) {}

    EstadoJuego getEstado() const { return estado; }
};

class Personaje {
private:
    string nombre;
    int nivel;
    int puntos;
    vector<Memento*> mementos;

public:
    Personaje(const string& nombre, int nivel, int puntos)
            : nombre(nombre), nivel(nivel), puntos(puntos) {}

    string getNombre() const { return nombre;}
    int getNivel() const { return nivel;}
    int getPuntos() const { return puntos;}

    void setEstado(const EstadoJuego& estado) {
        // Guardar el estado del juego en el Memento
        Memento* memento = new Memento(estado);
        mementos.push_back(memento);
    }

    // Restaurar el último estado del memento
    EstadoJuego getEstadoActual() const {
        if(!mementos.empty()){
            Memento* memento = mementos.back();
            return memento->getEstado();
        }

        // Si no hay mementos, retornar un estado predeterminado
        return EstadoJuego("Nivel 1", 0, 0);
    }
};


int main(){
    Personaje personaje("Heroe", 1, 0); // Crear el personaje del juego
    personaje.setEstado(EstadoJuego("Nivel 1", 10, 20));
    Memento* memento1 = new Memento(personaje.getEstadoActual()); // Guardar

    personaje.setEstado(EstadoJuego("Nivel 2", 30, 40)); // Jugar
    Memento* memento2 = new Memento(personaje.getEstadoActual());

    personaje.setEstado(memento1->getEstado()); // Restaurar
    cout << "Estado actual del juego: " << personaje.getEstadoActual().getNombreNivel()
         << ", Posicion: (" << personaje.getEstadoActual().getPosicionX() << ", "
         << personaje.getEstadoActual().getPosicionY() << ")" << endl;

    delete memento1;
    delete memento2;
}
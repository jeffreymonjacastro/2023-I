#include <iostream>
#include <vector>

using namespace std;

// Se crea la canción que tendrá los datos
class Cancion {
private:
    string titulo;
    string artista;
public:
    Cancion(const string& titulo, const string& artista) : titulo(titulo), artista(artista) {}

    string getTitulo() { return titulo; }
    string getArtista() { return artista; }
};

// Se crea el iterador que recorrerá un objeto de clase ReproductorMusical
class Iterador {
private:
    vector<Cancion>& canciones;
    int indiceS;
    int indiceP;
public:
    Iterador(vector<Cancion>& canciones): canciones(canciones), indiceS(0), indiceP(canciones.size() - 1){}

    Cancion* siguiente() {
        return &canciones[indiceS++];
    }

    Cancion* previo() {
        return &canciones[indiceP--];
    }

    bool tieneSiguiente() {
        return indiceS < canciones.size();
    }

    bool tienePrevio(){
        return indiceP >= 0;
    }
};

// Se crea la clase que tendrá las canciones (tipo Spotify)
class ReproductorMusical {
private:
    vector<Cancion> canciones;
public:
    ReproductorMusical(){}

    void agregarCancion(const Cancion& cancion) {
        canciones.push_back(cancion);
    }

    Iterador* createIterador(){
        return new Iterador(canciones);
    }
};

int main(){
    ReproductorMusical reproductor;

    Cancion cancion1("Cancion 1", "Artista 1");
    Cancion cancion2("Cancion 2", "Artista 2");
    Cancion cancion3("Cancion 3", "Artista 3");

    reproductor.agregarCancion(cancion1);
    reproductor.agregarCancion(cancion2);
    reproductor.agregarCancion(cancion3);

    Iterador* iterador = reproductor.createIterador();

    while(iterador->tieneSiguiente()) {
        Cancion* cancion = iterador->siguiente();
        cout << "Reproduciendo: " << cancion->getTitulo() << " - " << cancion->getArtista() << endl;
    }

    cout << endl;

    while(iterador->tienePrevio()) {
        Cancion* cancion = iterador->previo();
        cout << "Reproduciendo: " << cancion->getTitulo() << " - " << cancion->getArtista() << endl;
    }

    delete iterador;
}
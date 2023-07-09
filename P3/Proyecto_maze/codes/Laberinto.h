#include "Librerias.h"

// Clase que representa un laberinto
class Laberinto {

private:
    // Dimensiones del laberinto
    int filas_;
    int columnas_;

    // Representación del laberinto como una matriz
    vector<vector<string>> laberinto_;

    // Direcciones adyacentes: arriba, derecha, abajo, izquierda
    vector<int> filasAdyacentes_ = { -1, 0, 1, 0 };
    vector<int> columnasAdyacentes_ = { 0, 1, 0, -1 };

    // Generación recursiva del laberinto
    void generarLaberintoRecursivo(int fila, int columna) {
        // Marcar la celda actual como pasillo
        laberinto_[fila][columna] = "   ";

        // Obtener una lista aleatoria de direcciones
        vector<int> direcciones = { 0, 1, 2, 3 };
        shuffle(direcciones.begin(), direcciones.end(), random_device());

        // Recorrer las direcciones
        for (int direccion : direcciones) {
            int nuevaFila = fila + 2 * filasAdyacentes_[direccion];
            int nuevaColumna = columna + 2 * columnasAdyacentes_[direccion];

            // Verificar si la nueva celda es válida
            if (esCeldaValida(nuevaFila, nuevaColumna)) {
                // Marcar la celda adyacente como pasillo
                laberinto_[nuevaFila][nuevaColumna] = "   ";

                // Marcar la celda intermedia como pasillo
                laberinto_[fila + filasAdyacentes_[direccion]][columna + columnasAdyacentes_[direccion]] = "   ";

                // Llamada recursiva para la nueva celda
                generarLaberintoRecursivo(nuevaFila, nuevaColumna);
            }
        }
    }

    // Establecer la entrada y la salida en paredes aleatorias
    void establecerEntradaYSalida() {
        // Generar un generador de números aleatorios
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(0, 1);

        // Pared lateral izquierda o derecha
        if (dis(gen) == 0) {
            int filaEntrada = 1 + 2 * (dis(gen) % (filas_ / 2));
            laberinto_[filaEntrada][0] = "001";

            int filaSalida = 1 + 2 * (dis(gen) % (filas_ / 2));
            laberinto_[filaSalida][columnas_ - 1] = "002";
        }
            // Pared superior o inferior
        else {
            int columnaEntrada = 1 + 2 * (dis(gen) % (columnas_ / 2));
            laberinto_[0][columnaEntrada] = "001";

            int columnaSalida = 1 + 2 * (dis(gen) % (columnas_ / 2));
            laberinto_[filas_ - 1][columnaSalida] = "002";
        }
    }

    void reemplazarValores() {
        int contador = 3;

        for (auto& fila : laberinto_) {
            for (auto& elemento : fila) {
                if (elemento == "   ") {
                    elemento = to_string(contador);
                    elemento = string(3 - elemento.length(), '0') + elemento;
                    contador++;
                }
            }
        }
    }

    // Verificar si una celda es válida
    bool esCeldaValida(int fila, int columna) {
        return (fila >= 0 && fila < filas_ && columna >= 0 && columna < columnas_ && laberinto_[fila][columna] == "###");
    }

public:
    // Constructor que inicializa el laberinto con las dimensiones dadas
    Laberinto(int filas, int columnas) : filas_(filas), columnas_(columnas) {
        // Inicializar el laberinto con paredes en todas las celdas
        laberinto_.resize(filas_, vector<string>(columnas_, "###"));
    }

    // Generar el laberinto utilizando el algoritmo Recursive Backtracking
    void generarLaberinto() {
        // Generar un generador de números aleatorios
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(0, 3);

        // Elegir una celda aleatoria como punto de partida
        int filaInicial = 1 + 2 * (dis(gen) % (filas_ / 2));
        int columnaInicial = 1 + 2 * (dis(gen) % (columnas_ / 2));

        // Llamar a la función de generación recursiva
        generarLaberintoRecursivo(filaInicial, columnaInicial);

        // Establecer la entrada y la salida en paredes aleatorias
        establecerEntradaYSalida();

        // Colocar nombres a los nodos
        reemplazarValores();
    }

    vector<pair<string, string>> encontrar_relaciones() {
        set<pair<string, string>> relaciones;
        int filas = laberinto_.size();
        int columnas = laberinto_[0].size();

        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                if (isdigit(laberinto_[i][j][0])) {
                    if (i + 1 < filas && isdigit(laberinto_[i + 1][j][0])) {
                        relaciones.insert(std::make_pair(laberinto_[i][j], laberinto_[i + 1][j]));
                    }
                    if (j + 1 < columnas && isdigit(laberinto_[i][j + 1][0])) {
                        relaciones.insert(std::make_pair(laberinto_[i][j], laberinto_[i][j + 1]));
                    }
                }
            }
        }

        vector<pair<string, string>> relaciones_encontradas;
        for (const auto& relacion : relaciones) {
            relaciones_encontradas.push_back(relacion);
        }

        return relaciones_encontradas;
    }

    // Imprimir el laberinto
    void imprimirLaberinto() {
        for (int fila = 0; fila < filas_; ++fila) {
            for (int columna = 0; columna < columnas_; ++columna) {
                if (laberinto_[fila][columna] == "###") cout << laberinto_[fila][columna] << ' ';
                else if(laberinto_[fila][columna] == "001") cout << "EEE" << ' ';
                else if(laberinto_[fila][columna] == "002") cout << "SSS" << ' ';
                else cout << "   " << ' ';
            }
            cout << endl;
        }
    }

    vector<vector<string>> getMaze() { return laberinto_; }
};

#include "Grafos.h"

class Visual {

private:
    vector<vector<string>> laberinto;
    vector<string> camino;
    unordered_set<string> visitas;

    bool esNumerico(const std::string& str) const {
        std::istringstream iss(str);
        int num;
        return (iss >> num >> std::ws) && (iss.eof());
    }

public:
    Visual(const vector<vector<string>>& lab, const vector<string>& cam, const unordered_set<string>& vis)
            : laberinto(lab), camino(cam), visitas(vis) {}

    void procesarLaberinto() {
        for (auto& fila : laberinto) {
            for (auto& elemento : fila) {
                if (elemento == "001") {
                    elemento = "EEE";
                }
                else if (elemento == "002") {
                    elemento = "SSS";
                }
                else if (std::find(camino.begin(), camino.end(), elemento) != camino.end()) {
                    elemento = " * ";
                }
                else if (visitas.find(elemento) != visitas.end()) {
                    elemento = " V ";
                }
                else if (esNumerico(elemento)) {
                    elemento = "   ";
                }
            }
        }
    }

    void imprimirLaberinto() const {
        for (const auto& fila : laberinto) {
            for (const auto& elemento : fila) {
                std::cout << elemento << " ";
            }
            std::cout << std::endl;
        }
    }
};

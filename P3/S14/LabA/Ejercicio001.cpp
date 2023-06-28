#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

template<typename T>
struct Grafo{
    unordered_map<T,unordered_set<T>> g_map;
    unordered_set<T> visitados;

    void nueva_arista(T v1, T v2){
        g_map[v1].insert(v2);
        g_map[v2].insert(v1);
    }

    void DFS(T u){
        if (visitados.find(u) != visitados.end())
            return;

        visitados.insert(u);
        for(const T& next: g_map[u])
            DFS(next);
    }

    // Método que verifica si hay ciclos en el grafo
    bool ciclosDFS(T u, T padre){
        cout << "Visitando -> " << u << endl;

        // Se marca el nodo como visitado
        visitados.insert(u);

        // Se recorre los nodos adyacentes al nodo actual
        for(const T& next: g_map[u]) {

            // Si el nodo no ha sido visitado, entra a la condición
            if (visitados.find(next) == visitados.end()) {
                // Recursión donde ahora el nodo actual es el padre y el nodo next es el nodo actual
                if (ciclosDFS(next, u))
                    // Si se encuentra un ciclo, se retorna true
                    return true;

            // Si el nodo ya ha sido visitado y no es el padre, entra a la condición
            } else if (next != padre) {
                // Se imprime el ciclo encontrado
                cout << "Ciclo encontrado en " << u << endl;
                return true;
            }
        }

        // Si termina el bucle y no se ha encontrado un ciclo, se retorna false
        return false;
    }
};

int main(){
    Grafo<char> g;
    g.nueva_arista('A','B');
    g.nueva_arista('A','C');
    g.nueva_arista('B','D');
    g.nueva_arista('C','E');
    g.nueva_arista('F','B');
    g.nueva_arista('F','D');

    if (g.ciclosDFS('A','A')) // ciclosDFS(nodo, padre)
        cout << "Hay ciclos" << endl;
    else
        cout << "No hay ciclos" << endl;

    return 0;
}

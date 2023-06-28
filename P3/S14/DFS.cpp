#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

template<typename T>
struct Grafo{
    unordered_map<T,unordered_set<T>> g_map; // Variable que contiene las conexiones entre nodos
    unordered_set<T> visitados; // Variable que contiene los nodos visitados

    // Funcion que crea una nueva arista entre dos nodos
    void nueva_arista(T v1, T v2){
        // Se crea una nueva arista entre v1 y v2
        g_map[v1].insert(v2);
        // Se crea una nueva arista entre v2 y v1
        g_map[v2].insert(v1);
    }

    // Funcion que verifica si hay ciclos en el grafo
    void DFS(T u){
        // Si el nodo ya fue visitado, se retorna
        if (visitados.find(u) != visitados.end())
            return;

        cout << "Visitando " << u << endl; // [A C E B D]

        // Se marca el nodo como visitado
        visitados.insert(u);

        // Se recorren los nodos adyacentes al nodo actual
        for(const T& next: g_map[u])
            DFS(next);
    }
};

int main(){
    Grafo<char> g;
    g.nueva_arista('A','B');
    g.nueva_arista('A','C');
    g.nueva_arista('B','C');
    g.nueva_arista('B','D');
    g.nueva_arista('C','E');

    g.DFS('A'); // A C E B D
}
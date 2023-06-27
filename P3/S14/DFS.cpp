#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;


// La clase Grafo tiene como atributo un unordered_set para los nodo visitado y un unordered_map para crear las conexiones entre nodos.
template<typename T>
struct Grafo{
    unordered_map<T,unordered_set<T>> g_map;
    unordered_set<T> visitados;

    void nueva_arista(T v1, T v2);
    void DFS(T u);
};

template<typename T>
void Grafo<T>::nueva_arista(T v1, T v2){
    g_map[v1].insert(v2);
    g_map[v2].insert(v1);
}

template<typename T>
void Grafo<T>::DFS(T u){
    if (visitados.find(u) != visitados.end())
        return;
    visitados.insert(u);
    cout << "Visitando -> " << u << endl;
    for(const T& next: g_map[u])
        DFS(next);
}

int main(){
    Grafo<char> g;
    g.nueva_arista('A','B');
    g.nueva_arista('A','C');
    g.nueva_arista('B','C');
    g.nueva_arista('B','D');
    g.nueva_arista('C','E');

    g.DFS('A'); // A C E B D
}
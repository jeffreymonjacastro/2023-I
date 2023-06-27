#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

template<typename T>
struct Grafo{
    unordered_map<T,unordered_set<T>> g_map;
    unordered_set<T> visitados;

    void nueva_arista(T v1, T v2);
    void BFS(T u);
};

template<typename T>
void Grafo<T>::nueva_arista(T v1, T v2){
    g_map[v1].insert(v2);
    g_map[v2].insert(v1);
}

template<typename T>
void Grafo<T>::BFS(T u){
    queue<T> Q;
    Q.push(u);

    while (Q.size() != 0){
        T v = Q.front();
        Q.pop();
        if (visitados.find(v) == visitados.end()){
            visitados.insert(v);
            cout << "Visitando -> " << v << endl;
            for (const T& e: g_map[v]){
                if (visitados.find(e) == visitados.end())
                    Q.push(e);
            }
        }
    }
}

int main(){
    Grafo<char> g;
    g.nueva_arista('A','B');
    g.nueva_arista('A','C');
    g.nueva_arista('B','C');
    g.nueva_arista('B','D');
    g.nueva_arista('C','E');

    g.BFS('A'); // Salida: A C B E D
}
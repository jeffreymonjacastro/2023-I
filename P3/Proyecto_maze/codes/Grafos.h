#include "Laberinto.h"

template<typename T>
class Grafo{
private:
    unordered_map<T, unordered_set<T>> g_map12;
    unordered_map<T, unordered_map<T, int>> g_map3;

    unordered_set<T> visitados1;
    unordered_set<T> visitados2;
    unordered_set<T> visitados3;
public:
    Grafo() = default;
    ~Grafo() = default;

    void nueva_arista12(T v1, T v2){
        g_map12[v1].insert(v2);
        g_map12[v2].insert(v1);
    }

    void nueva_arista3(T v1, T v2, int peso){
        g_map3[v1][v2] = peso;
        g_map3[v2][v1] = peso;
    }

    vector<unordered_set<T>> visitados(){
        vector<unordered_set<T>> guardados;
        guardados.push_back(visitados1);
        guardados.push_back(visitados2);
        guardados.push_back(visitados3);
        return guardados;
    }

    vector<vector<T>> pathsBFS(T inicio, T final);

    vector<T> graphDFS(T origen, T destino);

    vector<T> dijkstra(T origen, T destino);


};


template<typename T>
vector<vector<T>> Grafo<T>::pathsBFS(T inicio, T final){
    queue<vector<T>> Q;
    Q.push({inicio});
    vector<vector<T>> paths;

    while (!Q.empty()){
        vector<T> currentPath = Q.front();
        Q.pop();
        T currentVertex = currentPath.back();

        visitados1.insert(currentVertex);  // Agregar el vértice actual a visitados

        if (currentVertex == final) {
            paths.push_back(currentPath);
            continue;
        }

        for (const T& neighbor : g_map12[currentVertex]){
            bool neighborVisited = false;
            for (const T& vertex : currentPath){
                if (vertex == neighbor){
                    neighborVisited = true;
                    break;
                }
            }
            if (!neighborVisited){
                vector<T> newPath = currentPath;
                newPath.push_back(neighbor);
                Q.push(newPath);
            }
        }
    }

    return paths;
}

template<typename T>
vector<T> Grafo<T>::graphDFS(T origen, T destino) {
    unordered_map<T, T> padre;
    padre[origen] = origen;

    stack<T> pila;
    pila.push(origen);

    while (!pila.empty()) {
        T actual = pila.top();
        pila.pop();

        visitados2.insert(actual);  // Agregar el nodo actual a visitados

        if (actual == destino) {
            // Se encontró el destino, construir el camino
            vector<T> camino;
            T nodo = destino;
            while (nodo != origen) {
                camino.push_back(nodo);
                nodo = padre[nodo];
            }
            camino.push_back(origen);
            reverse(camino.begin(), camino.end());

            return camino;
        }

        for (const T& vecino : g_map12[actual]) {
            if (padre.find(vecino) == padre.end()) {
                padre[vecino] = actual;
                pila.push(vecino);
            }
        }
    }

    return vector<T>();
}

template<typename T>
vector<T> Grafo<T>::dijkstra(T origen, T destino){
    unordered_map<T, int> distancias;
    unordered_map<T, T> padres;

    for (const auto& kvp : g_map3){
        distancias[kvp.first] = numeric_limits<int>::max();
    }
    distancias[origen] = 0;

    using Node = pair<int, T>;
    priority_queue<Node, vector<Node>, greater<Node>> heap;
    heap.push({0, origen});

    while (!heap.empty()) {
        T nodo_actual = heap.top().second;
        int distancia_actual = heap.top().first;
        heap.pop();

        visitados3.insert(nodo_actual);

        if (distancia_actual > distancias[nodo_actual]){
            continue;
        }

        if (nodo_actual == destino){
            vector<T> camino;
            T nodo = destino;
            while (nodo != origen){
                camino.push_back(nodo);
                nodo = padres[nodo];
            }
            camino.push_back(origen);
            reverse(camino.begin(), camino.end());
            return camino;
        }

        for (const auto& kvp : g_map3[nodo_actual]){
            T vecino = kvp.first;
            int peso_arista = kvp.second;

            int nueva_distancia = distancia_actual + peso_arista;

            if (nueva_distancia < distancias[vecino]){
                distancias[vecino] = nueva_distancia;
                padres[vecino] = nodo_actual;
                heap.push({nueva_distancia, vecino});
            }
        }
    }

    // Si no se encontró un camino al nodo de destino, devolver un vector vacío
    return vector<T>();
}




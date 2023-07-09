#include "Visual.h"

int main() {
    int filas = 13;
    int columnas = 17;
    cout << endl;

    Laberinto laberinto(filas, columnas);
    laberinto.generarLaberinto();
    laberinto.imprimirLaberinto();
    auto relaciones = laberinto.encontrar_relaciones();
    auto maze = laberinto.getMaze();

    Grafo<string> grafito;

    for (const auto& elemento : relaciones) {
        grafito.nueva_arista12(elemento.first,elemento.second);
        grafito.nueva_arista3(elemento.first,elemento.second,1);
    }

    vector<string> path_BFS = grafito.pathsBFS("001","002")[0];
    vector<string> graph_DFS = grafito.graphDFS("001","002");
    vector<string> Dijkstra = grafito.dijkstra("001","002");
    auto visitas = grafito.visitados();

    cout << endl;

    Visual vis1(maze,path_BFS,visitas[0]);
    vis1.procesarLaberinto();
    vis1.imprimirLaberinto();

    cout << endl;

    Visual vis2(maze,graph_DFS,visitas[1]);
    vis2.procesarLaberinto();
    vis2.imprimirLaberinto();

    cout << endl;

    Visual vis3(maze,Dijkstra,visitas[2]);
    vis3.procesarLaberinto();
    vis3.imprimirLaberinto();

    return 0;
}

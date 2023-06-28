#include <iostream>
#include <vector>

using namespace std;

void explorarDFS(vector<vector<char>>& laberinto, int x, int y, int fx, int fy){
    if (x < 0 || x >= laberinto.size() || y < 0 || y >= laberinto.size())
        return;
    if (laberinto[x][y] == 'X' || laberinto[x][y] == 'V')
        return;
    if (x == fx && y == fy){
        // Llegando a la meta
        laberinto[x][y] = '@';
        return;
    }
    laberinto[x][y] = 'V';
    explorarDFS(laberinto,x+1,y,fx,fy);
    explorarDFS(laberinto,x-1,y,fx,fy);
    explorarDFS(laberinto,x,y+1,fx,fy);
    explorarDFS(laberinto,x,y-1,fx,fy);
}

void print(vector<vector<char>>& laberinto){
    for(int i = 0; i < laberinto.size(); i++){
        for(int j = 0; j < laberinto[0].size(); j++)
            cout << laberinto[i][j] << " ";
        cout << endl;
    }
}

int main(){
    vector<vector<char>> laberinto =
            {{'I','X',' ','X','X'},
             {' ',' ',' ',' ','X'},
             {'X',' ','X',' ','X'},
             {'X',' ','X',' ','F'},
             {' ',' ','X',' ','X'}};

    explorarDFS(laberinto,0,0,3,4);
    print(laberinto);
}
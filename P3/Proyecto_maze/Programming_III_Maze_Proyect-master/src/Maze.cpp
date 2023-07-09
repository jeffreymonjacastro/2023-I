#include <bits/stdc++.h>
#include "laberinto.h"
#include "Na_No_hA_Stricker.h"
using namespace std;
int main() {

    Laberinto A;
    Player Alfa(1, 1, LIGHTGRAY);
    Player Beta(123, 124, GREEN);
    Bot Teta(123, 124);

    float speed = 1;
    srand(time(nullptr));
    for (int i = 0; i < MAZE_HEIGHT; ++i) {
        for (int j = 0; j < MAZE_WIDTH; ++j) {
           A(i,j) = 0;
      }
       cout<<endl;
    }
    //for (int i = 0; i < MAZE_HEIGHT; ++i) {
    //        for (int j = 0; j < MAZE_WIDTH; ++j) {
    //            A(i,j) = 0;
    //        }
    //        cout<<endl;
    //    }
    //    for (int i = 0; i < MAZE_HEIGHT; ++i) {
    //        for (int j = 0; j < MAZE_WIDTH; ++j) {
    //            cout<< setw(3)<<i << j<<" ";
    //        }
    //        cout<<endl;
    //    }

    backtraking(A);
    InitAudioDevice();  //Inicializo
    InitWindow(MAP_WIDTH, MAP_HEIGHT, "Marisa");
        SetTargetFPS(30);
    float timePlayed = 0.0f;        // Time played normalized [0.0f..1.0f]
    bool pause = false;
    A(62,61) = 1;
    Texture2D block_ = LoadTexture(R"(..\assets\block_.png)");
    Texture2D finish = LoadTexture(R"(..\assets\META1.png)");
    Music soundtrack = LoadMusicStream(R"(..\assets\BOCCHIGOD.mp3)");
    PlayMusicStream(soundtrack);
    while (!WindowShouldClose()) {
        //UpdateMusicStream(soundtrack);
        if (IsKeyPressed(KEY_P))
        {
            pause = !pause;
            if (pause) PauseMusicStream(soundtrack);
            else ResumeMusicStream(soundtrack);
        }
        BeginDrawing();
        ClearBackground(BLACK);
        for (int x = 0; x < MAZE_HEIGHT; x++) {
            for (int y = 0; y < MAZE_WIDTH; y++) {
                if (A(y,x) != 1 and A(y,x) != 2 and A(y,x)!=3) {
                    DrawTextureRec(
                            block_,
                            Rectangle{float(x*TILE_SIZE_WIDTH),float(y * TILE_SIZE_HEIGHT),TILE_SIZE_WIDTH, TILE_SIZE_HEIGHT},
                            Vector2{float(x*TILE_SIZE_WIDTH),float(y * TILE_SIZE_HEIGHT)},
                            WHITE
                    );
                }
                if (A(y,x) == 2){
                    DrawRectangle(float(x*TILE_SIZE_WIDTH),float(y * TILE_SIZE_HEIGHT),TILE_SIZE_WIDTH, TILE_SIZE_HEIGHT,PINK);
                }
            }
        }
        //DrawRectangle(15*TILE_SIZE_WIDTH,15*TILE_SIZE_HEIGHT,TILE_SIZE_WIDTH,TILE_SIZE_HEIGHT,GREEN);
        //Alfa.movement(Alfa,A,{1,1});

        DrawTextureRec(
                finish,
                Rectangle{float(62*TILE_SIZE_WIDTH),float(61 * TILE_SIZE_HEIGHT),TILE_SIZE_WIDTH, TILE_SIZE_HEIGHT},
                Vector2{float(62*TILE_SIZE_WIDTH),float(61 * TILE_SIZE_HEIGHT)},
                WHITE
                );
        //DrawRectangle(Beta.getX()*TILE_SIZE_WIDTH,Beta.getY()*TILE_SIZE_HEIGHT,TILE_SIZE_WIDTH,TILE_SIZE_HEIGHT,BLUE);
        //Beta.DFS(A);
        //Beta.DFS2(A);
        Teta.BFS(A);

        auto window = !WindowShouldClose();
        int turno = 1;
        Alfa.DrawPlayer();
        Beta.DrawPlayer();
        if (turno == 1){
            pthread_key_t z;
            z = GetKeyPressed();
            pair<int,int> coords_ac {Alfa.getY(),Alfa.getX()};
            if (Alfa.tecla_val(z) and Alfa.no_salga() and Alfa.sig_cuadro(A) and Alfa.col_play(Beta))
            {
                Alfa.avanz_play(z);
                Alfa.DrawPlayer();
                Alfa.movement(Beta, A, coords_ac, turno);
                Alfa.DrawPlayer();
            }
        }
        if (Alfa.verf_gan()){
            EndDrawing();
            window = WindowShouldClose();
        }


        else if (turno == 2){
            pthread_key_t z2;
            z2 = GetKeyPressed();
            pair<int,int> coords_ac {Beta.getY(),Beta.getX()};
            if (Beta.tecla_val(z2) and Beta.no_salga() and Beta.sig_cuadro(A) and Beta.col_play(Alfa))
            {
                Beta.avanz_play(z2);
                Beta.DrawPlayer();
                Beta.movement(Alfa, A, coords_ac, turno);
                Beta.DrawPlayer();
            }
        }
        if (Beta.verf_gan()){
            EndDrawing();
            window = WindowShouldClose();
        }
        Alfa.DrawPlayer();
        Beta.DrawPlayer();
        GetFPS();
        EndDrawing();
    }
    UnloadMusicStream(soundtrack);   // Unload music stream buffers from RAM
    CloseAudioDevice();
    CloseWindow();
}
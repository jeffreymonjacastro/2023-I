//
// Created by Fabri on 4/02/2023.
//

#ifndef MAZE_NA_NO_HA_STRICKER_H
#define MAZE_NA_NO_HA_STRICKER_H
#include "Laberinto.h"
#include "queue"
#include "iomanip"
using I = int;
using Pi = std::pair<int,int>;
class Bot{


private:
    float x_{};
    float y_{};
   std::stack<std::pair<Pi,int>>Visited_coords_distance;
    std::queue<std::pair<int , int>> Frontier;
    std::stack<Pi> visited_cordinates_bot;
    std::vector<Pi> cordinates_bot_walks;
    Pi Target;      //META
    std::vector<Pi> Path;
    Rectangle bot;
public:

    Bot(float x , float y):x_(x),y_(y){
        visited_cordinates_bot.push({x,y}); // Stablishing first coordinate
        Visited_coords_distance.push({{x,y},0});
        bot = {x*TILE_SIZE_WIDTH,y*TILE_SIZE_HEIGHT,TILE_SIZE_WIDTH,TILE_SIZE_HEIGHT};
        Frontier.push({x,y});
        Target={62,61};
    }
    void draw();
    ~Bot()= default;
    [[nodiscard]] float getX() const {
        return x_;
    }
    [[nodiscard]] float getY() const {
        return y_;
    }
    Bot& operator+=(float act)
    {
        x_+=act;
        return *this;
    }
    Bot& operator-=(float act)
    {
        x_-=act;
        return *this;
    }
    Bot& operator+(float act)
    {
        y_+=act;

        return *this;
    }

    Bot & operator-(float act)
    {
        y_-=act;
        return *this;
    }

    int get_x_aprox() const{
        if (x_>int(x_)+0.15){
            return int(x_+1);
        }
        return int(x_);
    }
    int get_y_aprox() const{
        if (y_>int(y_)+0.15){
            return int(y_+1);
        }
        return int(y_);
    }

    void DFS(Laberinto& Maze);
    void DFS2(Laberinto& Maze);
    void BFS(Laberinto& Maze);

};

class Player{
private:
    int x_{};
    int y_{};
    Color color_;
public:
    Player(int x , int y, Color color):x_(x),y_(y), color_(color){
    }
    ~Player()= default;
    [[nodiscard]] int getX() const {
        return x_;
    }
    [[nodiscard]] int getY() const {
        return y_;
    }
    void DrawPlayer(){
        DrawRectangle(x_ * TILE_SIZE_WIDTH, y_ * TILE_SIZE_HEIGHT, TILE_SIZE_WIDTH, TILE_SIZE_HEIGHT, color_);
    }

    bool no_salga(){
        if (IsKeyDown(KEY_A)) {
            if (x_ <= 130 and x_ > 0)
                return true;
        }
        else if (IsKeyDown(KEY_D)) {
            if (x_ < 130 and x_ >= 0)
                return true;
        }
        else if (IsKeyDown(KEY_W)) {
            if (y_ <= 130 and y_ > 0)
                return true;
        }
        else if (IsKeyDown(KEY_S)) {
            if (y_ < 130 and y_ >= 0)
                return true;
        }
        return false;
    }

    bool sig_cuadro(Laberinto y){
        if (IsKeyDown(KEY_A)) {
            if (y(y_, x_ - 1) == 1)
                return true;
        }
        else if (IsKeyDown(KEY_D)) {
            if (y(y_, x_ + 1) == 1)
                return true;
        }
        else if (IsKeyDown(KEY_W)) {
            if (y(y_ - 1, x_) == 1)
                return true;
        }
        else if (IsKeyDown(KEY_S)) {
            if (y(y_ + 1, x_) == 1)
                return true;
        }
        return false;
    }

    bool col_play(Player y){
        if (IsKeyDown(KEY_A)) {
            if ((y_ != y.getY() or x_ - 1 != y.getX()) and (x_ - 1 != 10 or y_ != 10))
                return true;
        }
        else if (IsKeyDown(KEY_D)) {
            if ((y_ != y.getY() or x_ + 1 != y.getX()) and (x_ + 1 != 10 or y_ != 10))
                return true;
        }
        else if (IsKeyDown(KEY_W)) {
            if ((y_ - 1 != y.getY() or x_ != y.getX()) and (y_ - 1 != 10 or x_ != 10))
                return true;
        }
        else if (IsKeyDown(KEY_S)) {
            if ((y_ + 1 != y.getY() or x_ != y.getX()) and (y_ + 1 != 10 or x_ != 10))
                return true;
        }
        return false;
    }

    bool tecla_val(pthread_key_t a){
        if (a == KEY_A or a == KEY_W or a == KEY_D or a == KEY_S){
            return true;
        }
        return false;
    }

    void avanz_play(pthread_key_t y){
        if (y == KEY_A){
            x_ -= 1;
        }
        else if (y == KEY_D){
            x_ += 1;
        }
        else if (y == KEY_W){
            y_ -= 1;
        }
        else if (y == KEY_S){
            y_ += 1;
        }
    }

    int vecinos(Player z, Laberinto y){
        int total_vec = 0;
        if (y(y_, x_ + 1) == 1 and (z.getX() != x_ + 1 or z.getY() != y_) and (x_ + 1 != 10 or y_ != 10)){
            total_vec++;
        }
        if (y(y_, x_ - 1) == 1 and (z.getX() != x_ - 1 or z.getY() != y_) and (x_ - 1 != 10 or y_ != 10)){
            total_vec++;
        }
        if (y(y_ + 1, x_) == 1 and (z.getY() != y_ + 1 or z.getX() != x_) and (y_ + 1 != 10 or x_ != 10)){
            total_vec++;
        }
        if (y(y_ - 1, x_) == 1 and (z.getY() != y_ - 1 or z.getX() != x_) and (y_ - 1 != 10 or x_ != 10)){
            total_vec++;
        }
        return total_vec;
    }

    void movement(Player& t, Laberinto& y, Pi coords, int& trn){
        while (vecinos(t, y) == 2){
            if (y(y_ - 1, x_) == 1 and coords.first != y_ - 1 and col_play(t) and vecinos(t, y) < 3){
                coords.first = y_;
                coords.second = x_;
                y_ -= 1;
                this->DrawPlayer();
            }
            else if (y(y_, x_ + 1) == 1 and coords.second != x_ + 1 and col_play(t) and vecinos(t, y) < 3){
                coords.second = x_;
                coords.first = y_;
                x_ += 1;
                this->DrawPlayer();
            }
            else if (y(y_ + 1, x_) == 1 and coords.first != y_ + 1 and col_play(t) and vecinos(t, y) < 3){
                coords.first = y_;
                coords.second = x_;
                y_ += 1;
                this->DrawPlayer();
            }
            else if (y(y_, x_ - 1) == 1 and coords.second != x_ - 1 and col_play(t) and vecinos(t, y) < 3){
                coords.second = x_;
                coords.first = y_;
                x_ -= 1;
                this->DrawPlayer();
            }
            this->DrawPlayer();
        }
        if (trn == 1){
            trn = 2;
        }
        else if (trn == 2) {
            trn = 1;
        }
    }

    bool verf_gan(){
        if ((x_ == 9 and y_ == 10) or (x_ == 11 and y_ == 10) or (x_ == 10 and y_ == 9) or (x_ == 10 and y_ == 11))
            return true;
        return false;
    }
};
#endif //MAZE_NA_NO_HA_STRICKER_H


#include "Laberinto.h"
using namespace std;


I &Laberinto::operator()(int i_row, int i_col) {
    return maze2[MAZE_WIDTH*i_row+(MAZE_WIDTH-(MAZE_WIDTH-i_col))];
}

I Laberinto::operator()(int i_row, int i_col) const {
    return maze2[MAZE_WIDTH*i_row+(MAZE_WIDTH-(MAZE_WIDTH-i_col))];
}

void backtraking(Laberinto& Alfa) {  // Implementation of Recursive Backtraking

    if(!Alfa.Visited_Coordinates.empty())
    {
        I current_x=Alfa.Visited_Coordinates.top().first;
        I current_y=Alfa.Visited_Coordinates.top().second;
        std::vector<std::pair<std::pair<I,I>, I>> Neighbors;  // 1 represents a vertical and 2 represents an horizontal movement
        // The second pair indicates if movement is vertical or horizontal
        if(Alfa(current_x+2,current_y)!=1 and current_x+2<MAZE_HEIGHT) // Check South
        {
            Neighbors.push_back({{current_x+2,current_y},1});
        }
        if(Alfa(current_x,current_y+2)!=1 and current_y+2<MAZE_WIDTH) // Check East
        {
            Neighbors.push_back({{current_x,current_y+2},2});
        }
        if(Alfa(current_x,current_y-2)!=1 and current_y-2>=1 )       //Check West
        {
            Neighbors.push_back({{current_x,current_y-2},-2});

        }
        if(Alfa(current_x-2,current_y)!=1 and current_x-2>=1 )   //Check North
        {
            Neighbors.push_back({{current_x-2,current_y},-1});


        }

        if(!Neighbors.empty())
        {
            auto Next_coordinate=Neighbors[rand()%Neighbors.size()];// Choose an avaliable neighbor randomdly
            Alfa.Visited_Coordinates.push(Next_coordinate.first); // Push new coordinate in the stack
            Alfa(Next_coordinate.first.first,Next_coordinate.first.second)=1; // marked the new coordinate as visited
            if(abs(Next_coordinate.second)==1) // check if the movement was vertical or not
            {
                Alfa(current_x+Next_coordinate.second,current_y)=1;//marked middle as visited

            }else{
                auto add=(Next_coordinate.second>0)?1:-1;
                Alfa(current_x,current_y+add)=1;//marked middle as visited
            }
            backtraking(Alfa);

        }else {

            Alfa.Visited_Coordinates.pop();
            backtraking(Alfa);
        }


    }else{

        std::cout<<"MAZE SUCCESFULLY GENERATED !!!"<<std::endl;
    }

}


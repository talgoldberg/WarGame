#include "SniperCommander.hpp"
#include "Board.hpp"
#include <tgmath.h>

//namespace WarGame {


    void SniperCommander::attack(std::vector<std::vector<Soldier *>> &board, int first, int second){
        int strong=0;
        int temp;
        std::pair<int,int> saveLocation;
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[i].size();j++)
            {
                if(board[i][j]!= nullptr&&board[i][j]->teamNum!= this->teamNum)
                {
                    temp=board[i][j]->health;
                    if(temp>strong)
                    {
                        strong=temp;
                        saveLocation.first=i;
                        saveLocation.second=j;
                    }

                }
                if(board[i][j]!= nullptr&&board[i][j]->teamNum== this->teamNum&&board[i][j]->damage==50){
                    board[i][j]->attack(board,i,j);
                }
            }
        }
        if(board[saveLocation.first][saveLocation.second]->health<=100)
            board[saveLocation.first][saveLocation.second]= nullptr;
        else{
            board[saveLocation.first][saveLocation.second]->health-=100;
        }
    }
//};
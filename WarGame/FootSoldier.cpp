//
// Created by tal goldberg.
//
#include "Board.hpp"
#include <tgmath.h>

#include "FootSoldier.hpp"
//namespace WarGame {


    void FootSoldier::attack(std::vector<std::vector<Soldier *>> &board, int first, int second){
        int minimum=board.size()*board[0].size();
        int temp;
        std::pair<int,int> saveLocation;
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[i].size();j++)
            {
                if(board[i][j]!= nullptr&&board[i][j]->teamNum!= this->teamNum)
                {
                    temp=pow(first-i,2)+pow(second-j,2);
                    if(temp<minimum)
                    {
                        minimum=temp;
                        saveLocation.first=i;
                        saveLocation.second=j;
                    }

                }
            }
        }
        if(board[saveLocation.first][saveLocation.second]== nullptr||board[saveLocation.first][saveLocation.second]->health<=10)
            board[saveLocation.first][saveLocation.second]= nullptr;
        else{
            board[saveLocation.first][saveLocation.second]->health-=10;
        }

    }
//};

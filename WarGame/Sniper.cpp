#include "Sniper.hpp"
#include "Board.hpp"
//namespace WarGame {


    void Sniper::attack(std::vector<std::vector<Soldier *>> &board, int first, int second){
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
            }
        }
        if(board[saveLocation.first][saveLocation.second]== nullptr||board[saveLocation.first][saveLocation.second]->health<=50)
            board[saveLocation.first][saveLocation.second]= nullptr;
        else{
            board[saveLocation.first][saveLocation.second]->health-=50;
        }

    }
//};
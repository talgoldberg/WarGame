#include "Paramedic.hpp"
#include "Board.hpp"

//namespace WarGame {


    void Paramedic::attack(std::vector<std::vector<Soldier *>> &board, int first, int second){
       if(first!=0&&board[first-1][second]!= nullptr&&board[first-1][second]->teamNum== this->teamNum)
       {
           if (board[first-1][second]->damage==0||board[first-1][second]->damage==50||board[first-1][second]->damage==10) {
               board[first - 1][second]->health = 100;
           }
           else if(board[first-1][second]->damage==-1){ //PramedicCommander
               board[first-1][second]->health=200;
           }
           else if(board[first-1][second]->damage==20) //FootCommander
               board[first-1][second]->health=150;
           else{ //SniperCommander
               board[first-1][second]->health=120;

           }

       }
        if(first<board.size()-2&&board[first+1][second]!= nullptr&&board[first+1][second]->teamNum== this->teamNum)
        {
            if (board[first+1][second]->damage==0||board[first+1][second]->damage==50||board[first+1][second]->damage==10)
                board[first+1][second]->health=100;
            else if(board[first+1][second]->damage==-1){ //PramedicCommander
                board[first+1][second]->health=200;
            }
            else if(board[first+1][second]->damage==20) //FootCommander
                board[first+1][second]->health=150;
            else{ //SniperCommander
                board[first+1][second]->health=120;

            }
        }
        if(second!=0&&board[first][second-1]!= nullptr&&board[first][second-1]->teamNum== this->teamNum)
        {
            if (board[first][second-1]->damage==0||board[first][second-1]->damage==50||board[first][second-1]->damage==10) {
                board[first][second-1]->health = 100;
            }
            else if(board[first][second-1]->damage==-1){ //PramedicCommander
                board[first][second-1]->health=200;
            }
            else if(board[first][second-1]->damage==20) //FootCommander
                board[first][second-1]->health=150;
            else{ //SniperCommander
                board[first][second-1]->health=120;

            }

        }
        if(second<board[0].size()-2&&board[first][second+1]!= nullptr&&board[first][second+1]->teamNum== this->teamNum)
        {
            if (board[first][second+1]->damage==0||board[first][second+1]->damage==50||board[first][second+1]->damage==100) {
                board[first][second+1]->health = 100;
            }
            else if(board[first][second+1]->damage==-1){ //PramedicCommander
                board[first][second+1]->health=200;
            }
            else if(board[first][second+1]->damage==20) //FootCommander
                board[first][second+1]->health=150;
            else{ //SniperCommander
                board[first][second+1]->health=120;

            }

        }


    }
//};

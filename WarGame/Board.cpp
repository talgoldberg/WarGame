//
// Created by tal goldberg.
//

#include <iostream>
#include <stdexcept>
#include "Board.hpp"

namespace WarGame {
    void  Board :: print(){
        for(int i= 0; i< board.size(); i++){
            for(int j=0; j< board[i].size(); ++j) {
                Soldier* s = (*this)[{i, j}];
                if (s != nullptr){
                    std::cout <<s->teamNum <<"+"<<s->health<<"	";
                }
                else{
                    std::cout<<"--"<<"	";
                }

            }
            std::cout<<std::endl;
        }

    }

    Soldier* &Board::operator[](std::pair<int, int> location)
    {
     /*   if(board[location.first][location.second] != nullptr)
            throw std::invalid_argument("This place is busy");*/

        return board[location.first][location.second];
    }

    Soldier* Board::operator[](std::pair<int, int> location) const
    {
        return board[location.first][location.second];

    }

    void Board::move(uint player_number, std::pair<int, int> source, WarGame::Board::MoveDIR direction) {
        if(source.first<0||source.first>=board.size()||source.second<0||source.second>=board[0].size())
            throw std::invalid_argument("you out from board");
        if (board[source.first][source.second] == nullptr ||
            board[source.first][source.second]->teamNum != player_number)
            throw std::invalid_argument("we do not have a solider in this place OR this player is not yours");


        switch (direction) {
            case MoveDIR::Down:

                    if (source.first - 1 < 0 || board[source.first - 1][source.second] != nullptr)
                        throw std::invalid_argument("you can not go there");
                    else {
                        board[source.first - 1][source.second] = board[source.first][source.second];
                        board[source.first][source.second] = nullptr;
                        board[source.first-1][source.second]->attack(board,source.first-1,source.second);
                    }
                break;

                  case MoveDIR::Up:

                      if (source.first + 1 >= board.size() || board[source.first + 1][source.second] != nullptr)
                          throw std::invalid_argument("you can not go there");
                      else {
                          board[source.first + 1][source.second] = board[source.first][source.second];
                          board[source.first][source.second] = nullptr;
                          board[source.first+1][source.second]->attack(board,source.first+1,source.second);

                      }
                break;

            case MoveDIR::Left:

                     if (source.second - 1 < 0 || board[source.first][source.second-1] != nullptr)
                         throw std::invalid_argument("you can not go there");
                   else {
                   // std::cout<<"jjjjjj"<<board[source.first][source.second]->health<<std::endl;
                    board[source.first][source.second-1] = board[source.first][source.second];
                    board[source.first][source.second] = nullptr;
                   board[source.first][source.second-1]->attack(board,source.first,source.second-1);
                }
                break;

            case MoveDIR::Right :

                if (source.second + 1 >= board.size() || board[source.first][source.second+1] != nullptr)
                    throw std::invalid_argument("you can not go there");
                else {
                    board[source.first][source.second+1] = board[source.first][source.second];
                    board[source.first][source.second] = nullptr;
                    board[source.first][source.second+1]->attack(board,source.first,source.second+1);

                }
                break;
            default:
                break;
        }


    }
    bool Board::has_soldiers(uint player_number) const
    {
        for(int i=0;i<board.size();i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] != nullptr && board[i][j]->teamNum == player_number)
                    return true;
            }
        }
        return false;

    }

};

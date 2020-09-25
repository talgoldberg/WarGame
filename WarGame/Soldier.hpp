//
// Created by tal goldberg on 5/18/20.
//
#pragma once
#include <vector>

class Soldier {
public:
    int health;
    int damage;
    int teamNum;



    Soldier(int health, int damage, int teamNum)
{
this->health=health;
this->damage=damage;
this->teamNum=teamNum;
}


    virtual void attack (std::vector<std::vector<Soldier*>> &board, int first, int second) = 0;


};

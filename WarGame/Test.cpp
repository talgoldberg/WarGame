#include "doctest.h"
#include <iostream>
#include <stdexcept>

#include "DemoGame.hpp"
#include "FootSoldier.hpp"
#include "FootCommander.hpp"
#include "Sniper.hpp"
#include "SniperCommander.hpp"
#include "Paramedic.hpp"
#include "ParamedicCommander.hpp"
#include <cassert>





TEST_CASE("place the players on board and check errors"){

    WarGame:: Board board (4, 4);

    board[{0,0}] = new ::FootSoldier(1);
    board[{0,1}] = new ::FootCommander(1);
    board[{0,2}] = new ::ParamedicCommander(1);
    board[{0,3}] = new ::Sniper(1);

    board[{3,0}] = new ::Paramedic(2);
    board[{3,1}] = new ::FootCommander(2);
    board[{3,2}] = new ::SniperCommander(2);
    board[{3,3}] = new ::FootSoldier(2);

    //  * There is no soldier in the source location.
    //  * The soldier in the source location belongs to the other player.
    //  * Out from Board.


            CHECK_THROWS( board.move(1, {1,0}, WarGame::Board::MoveDIR::Down));
            CHECK_THROWS( board.move(1, {2,0}, WarGame::Board::MoveDIR::Up));
            CHECK_THROWS( board.move(1, {3,0}, WarGame::Board::MoveDIR::Down));
            CHECK_THROWS( board.move(1, {4,0}, WarGame::Board::MoveDIR::Up));
            CHECK_THROWS( board.move(1, {5,3}, WarGame::Board::MoveDIR::Down));
            CHECK_THROWS( board.move(2, {0,0}, WarGame::Board::MoveDIR::Left));
            CHECK_THROWS( board.move(2, {0,3}, WarGame::Board::MoveDIR::Down));
            CHECK_THROWS( board.move(2, {3,0}, WarGame::Board::MoveDIR::Right));
            CHECK_THROWS( board.move(2, {4,0}, WarGame::Board::MoveDIR::Up));
            CHECK_THROWS( board.move(2, {5,7}, WarGame::Board::MoveDIR::Down));
            CHECK_THROWS( board.move(2, {2,2}, WarGame::Board::MoveDIR::Left));
            CHECK_THROWS( board.move(2, {0,2}, WarGame::Board::MoveDIR::Down));
            CHECK_THROWS( board.move(1, {3,3}, WarGame::Board::MoveDIR::Up));
            CHECK_THROWS( board.move(1, {4,2}, WarGame::Board::MoveDIR::Down));
            CHECK_THROWS( board.move(2, {-2,-2}, WarGame::Board::MoveDIR::Left));

    //  * There is already another soldier in the target location.
    //  * target location is out from Board.
            CHECK_THROWS( board.move(2, {3,1}, WarGame::Board::MoveDIR::Left));
            CHECK_THROWS( board.move(2, {3,2}, WarGame::Board::MoveDIR::Left));
            CHECK_THROWS( board.move(2, {3,3}, WarGame::Board::MoveDIR::Left));
            CHECK_THROWS( board.move(1, {0,1}, WarGame::Board::MoveDIR::Left));
            CHECK_THROWS( board.move(1, {0,2}, WarGame::Board::MoveDIR::Left));
            CHECK_THROWS( board.move(1, {0,3}, WarGame::Board::MoveDIR::Left));
            CHECK_THROWS( board.move(2, {3,1}, WarGame::Board::MoveDIR::Right));
            CHECK_THROWS( board.move(2, {3,2}, WarGame::Board::MoveDIR::Right));
            CHECK_THROWS( board.move(2, {3,0}, WarGame::Board::MoveDIR::Right));
            CHECK_THROWS( board.move(1, {0,1}, WarGame::Board::MoveDIR::Right));
            CHECK_THROWS( board.move(1, {0,2}, WarGame::Board::MoveDIR::Right));
            CHECK_THROWS( board.move(1, {0,0}, WarGame::Board::MoveDIR::Right));
            CHECK_THROWS( board.move(2, {3,1}, WarGame::Board::MoveDIR::Up));
            CHECK_THROWS( board.move(2, {3,2}, WarGame::Board::MoveDIR::Up));
            CHECK_THROWS( board.move(2, {3,0}, WarGame::Board::MoveDIR::Up));
            CHECK_THROWS( board.move(1, {0,1}, WarGame::Board::MoveDIR::Down));
            CHECK_THROWS( board.move(1, {0,2}, WarGame::Board::MoveDIR::Down));
            CHECK_THROWS( board.move(1, {0,0}, WarGame::Board::MoveDIR::Down));

    board.move(1, {0,1}, WarGame::Board::MoveDIR::Up);
    board.move(1, {0,2}, WarGame::Board::MoveDIR::Up);
    board.move(1, {0,0}, WarGame::Board::MoveDIR::Up);
    board.move(2, {3,1}, WarGame::Board::MoveDIR::Down);
    board.move(2, {3,2}, WarGame::Board::MoveDIR::Down);
    board.move(2, {3,0}, WarGame::Board::MoveDIR::Down);

            CHECK_THROWS( board.move(1, {1,0}, WarGame::Board::MoveDIR::Up));
            CHECK_THROWS( board.move(1, {1,1}, WarGame::Board::MoveDIR::Up));
            CHECK_THROWS( board.move(1, {1,2}, WarGame::Board::MoveDIR::Up));
            CHECK_THROWS( board.move(2, {2,0}, WarGame::Board::MoveDIR::Down));
            CHECK_THROWS( board.move(2, {2,1}, WarGame::Board::MoveDIR::Down));
            CHECK_THROWS( board.move(2, {2,2}, WarGame::Board::MoveDIR::Down));

    //  *  Check if a legal sliding was successful.
            CHECK(board[{0,0}] == nullptr);
            CHECK(board[{0,0}] == nullptr);
            CHECK(board[{0,1}] == nullptr);
            CHECK(board[{0,2}] == nullptr);
            CHECK(board[{3,0}] == nullptr);
            CHECK(board[{3,1}] == nullptr);
            CHECK(board[{3,2}] == nullptr);
            CHECK(board[{1,0}] != nullptr);
            CHECK(board[{1,1}] != nullptr);
            CHECK(board[{1,2}] != nullptr);
            CHECK(board[{2,0}] != nullptr);
            CHECK(board[{2,1}] != nullptr);
    // board.print();
}




TEST_CASE(" check FootSoldier and FootCommander attack") {
    WarGame:: Board board (5, 5);

    board[{0,0}] = new ::FootSoldier(1);
    board[{0,2}] = new ::FootCommander(1);
    board[{1,3}] = new ::FootSoldier(1);
    board[{1,1}] = new ::FootSoldier(2);
    board[{3,0}] = new ::FootSoldier(2);
    board[{0,4}] = new ::Paramedic(1);
    board[{1,4}] = new ::SniperCommander(1);

            CHECK(board[{0,0}]->health == 100);
            CHECK(board[{0,2}]->health == 150);
            CHECK(board[{1,3}]->health == 100);
            CHECK(board[{1,1}]->health == 100);
            CHECK(board[{3,0}]->health == 100);
            CHECK(board[{0,4}]->health == 100);
            CHECK(board[{1,4}]->health == 120);
    board.move(1, {0,0}, WarGame::Board::MoveDIR::Up);
            CHECK(board[{1,1}]->health == 90);
    board.move(1, {1,3}, WarGame::Board::MoveDIR::Left);
            CHECK(board[{1,1}]->health == 80);
    board.move(1, {0,2}, WarGame::Board::MoveDIR::Left);
            CHECK(board[{1,1}]->health == 40);
            CHECK(board[{1,0}]->health == 100);
            CHECK(board[{0,1}]->health == 150);
            CHECK(board[{1,2}]->health == 100);
            CHECK(board[{3,0}]->health == 100);
    board.move(1, {0,1}, WarGame::Board::MoveDIR::Right);
            CHECK(board[{1,1}]== nullptr);
    board.move(2, {3,0}, WarGame::Board::MoveDIR::Down);
            CHECK(board[{1,0}]->health == 90);
    board.move(1, {0,2}, WarGame::Board::MoveDIR::Right);
            CHECK(board[{2,0}]->health == 60);

    // board.print();
}
TEST_CASE(" check Sniper and SniperCommander attack") {
    WarGame::Board board(5, 5);

    board[{0, 2}] = new SniperCommander(1);
    board[{1, 3}] = new Sniper(1);
    board[{0, 4}] = new Paramedic(1);
    board[{1, 4}] = new FootSoldier(1);
    board[{1, 1}] = new Sniper(2);
    board[{3, 0}] = new Sniper(2);
    board[{4, 0}] = new Paramedic(2);

            CHECK(board[{0,2}]->health == 120);
            CHECK(board[{1,3}]->health == 100);
            CHECK(board[{1,1}]->health == 100);
            CHECK(board[{3,0}]->health == 100);
            CHECK(board[{0,4}]->health == 100);
            CHECK(board[{1,4}]->health == 100);
            CHECK(board[{4,0}]->health == 100);
    board.move(1, {1,3}, WarGame::Board::MoveDIR::Down);
            CHECK(board[{1,1}]->health == 50);
    board.move(1, {0,2}, WarGame::Board::MoveDIR::Left);
            CHECK(board[{1,1}]->health == 50);
            CHECK(board[{3,0}]->health == 50);
            CHECK(board[{4,0}] == nullptr);
    board.move(1, {0,3}, WarGame::Board::MoveDIR::Left);
            CHECK(board[{1,1}]== nullptr);
            CHECK(board[{0,1}]->health == 120);
            CHECK(board[{0,2}]->health == 100);
            CHECK(board[{0,4}]->health == 100);
            CHECK(board[{1,4}]->health == 100);
            CHECK(board[{3,0}]->health == 50);

    board.move(1, {0,1}, WarGame::Board::MoveDIR::Left);
            CHECK(board[{3,0}]== nullptr);





    //  board.print();
}

TEST_CASE(" check Paramedic and ParamedicCommander attack") {
    WarGame::Board board(5, 5);

    board[{0, 0}] = new ::SniperCommander(1);
    board[{0, 1}] = new ::Sniper(1);
    board[{1, 4}] = new ::Sniper(2);
    board[{3, 3}] = new ::Paramedic(2);
    board[{3, 4}] = new::Paramedic(2);
    board[{4, 2}] = new ::FootSoldier(2);
    board[{4, 0}] = new ::ParamedicCommander(2);

            CHECK(board[{0,0}]->health == 120);
            CHECK(board[{0,1}]->health == 100);
            CHECK(board[{1,4}]->health == 100);
            CHECK(board[{3,3}]->health == 100);
            CHECK(board[{3,4}]->health == 100);
            CHECK(board[{4,2}]->health == 100);
            CHECK(board[{4,0}]->health == 200);

    board.move(1, {0,0}, WarGame::Board::MoveDIR::Up);
    board.move(2, {1,4}, WarGame::Board::MoveDIR::Down);
    board.move(2, {3,4}, WarGame::Board::MoveDIR::Down);
    board[{0, 2}] = new ::Sniper(1);
    board[{2, 2}] = new ::Sniper(1);
    board.move(1, {0,2}, WarGame::Board::MoveDIR::Right);
    board.move(1, {2,2}, WarGame::Board::MoveDIR::Right);
    //board.move(2, {4,4}, WarGame::Board::MoveDIR::Left);
    //
            CHECK(board[{0,4}]->health == 50);
            CHECK(board[{2,4}]->health == 50);
    board[{1, 4}] = new ::Paramedic(2);
    board.move(2, {4,0}, WarGame::Board::MoveDIR::Right);
            CHECK(board[{0,4}]->health == 100);
            CHECK(board[{2,4}]->health == 100);
            CHECK(board[{4,2}]->health == 120);
            CHECK(board[{3,3}]->health == 100);
            CHECK(board[{4,1}]->health == 50);

    // board.print();
}

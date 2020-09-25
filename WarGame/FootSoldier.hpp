#include "Soldier.hpp"


//namespace WarGame {



    class FootSoldier : public Soldier {
    public:

        explicit FootSoldier(int teamNum): Soldier(100, 10, teamNum) {}


        void attack (std::vector<std::vector<Soldier*>> &board, int first, int second) override ;

    };



//};
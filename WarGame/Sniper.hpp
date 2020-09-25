#include "Soldier.hpp"


//namespace WarGame {



    class Sniper : public Soldier {
    public:

        explicit Sniper(int teamNum): Soldier(100, 50, teamNum) {}


        void attack (std::vector<std::vector<Soldier*>> &board, int first, int second) override ;

    };



//};
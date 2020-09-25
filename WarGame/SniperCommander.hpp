#include "Soldier.hpp"


//namespace WarGame {



    class SniperCommander : public Soldier {
    public:

        explicit SniperCommander(int teamNum): Soldier(120, 100, teamNum) {}


        void attack (std::vector<std::vector<Soldier*>> &board, int first, int second) override ;

    };



//};
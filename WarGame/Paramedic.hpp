#include "Soldier.hpp"


//namespace WarGame {



    class Paramedic : public Soldier {
    public:

        explicit Paramedic(int teamNum): Soldier(100, 0, teamNum) {}


        void attack (std::vector<std::vector<Soldier*>> &board, int first, int second) override ;

    };



//};
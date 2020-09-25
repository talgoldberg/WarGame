#include "Soldier.hpp"


//namespace WarGame {



    class ParamedicCommander : public Soldier {
    public:

        explicit ParamedicCommander(int teamNum): Soldier(200, -1, teamNum) {}


        void attack (std::vector<std::vector<Soldier*>> &board, int first, int second) override ;

    };



//};
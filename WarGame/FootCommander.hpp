#include "Soldier.hpp"
//#include "Board.hpp"
#include <vector>


  //  namespace WarGame {



        class FootCommander : public Soldier {
        public:

            explicit FootCommander(int teamNum): Soldier(150, 20, teamNum) {}



            void attack (std::vector<std::vector<Soldier*>> &board, int first, int second) override ;
        };



  //  };

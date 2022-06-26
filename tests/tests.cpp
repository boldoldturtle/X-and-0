#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../objects/game1.h"


TEST_CASE("Starting the game") {                   // the game is running - 0
    Game G;                                        // if the error - not started
    CHECK(G.run() ==0);
}


TEST_CASE("in which column did you make a move") { // 1 - first column
    Game G;                                        // 2 - second column
    CHECK(G.pollEvents() == 1);                    // 3 - third column
    CHECK(G.pollEvents() == 2);
    CHECK(G.pollEvents() == 3);
}



TEST_CASE("testing window initialization") {       // the window starts successfully
    Game G;
    CHECK(G.initWindow() == 0);
}



TEST_CASE("have you made a move to this cage") {
    Game G;
    CHECK(G.changeState(0) == 0);       // if 1 then the cell is occupied
    CHECK(G.changeState(1) == 0);       // if 0 then it is free
    CHECK(G.changeState(2) == 0);       // 0-8 range of cells
    CHECK(G.changeState(3) == 0);
    CHECK(G.changeState(4) == 0);
    CHECK(G.changeState(5) == 0);
    CHECK(G.changeState(6) == 0);
    CHECK(G.changeState(7) == 0);
    CHECK(G.changeState(8) == 0);
    CHECK(G.changeState(0) == 1);
    CHECK(G.changeState(1) == 1);
    CHECK(G.changeState(2) == 1);
    CHECK(G.changeState(3) == 1);
    CHECK(G.changeState(4) == 1);
    CHECK(G.changeState(5) == 1);
    CHECK(G.changeState(6) == 1);
    CHECK(G.changeState(7) == 1);
    CHECK(G.changeState(8) == 1);
}
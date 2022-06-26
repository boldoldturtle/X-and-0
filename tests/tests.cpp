#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../objects/game1.h"
int fact(int n) {
    return n <= 1 ? n : fact(n - 1) * n;
}
class Tgame : public Game {
public:
    int initWindow(){}
};


TEST_CASE("testing the factorial function") {
    CHECK(fact(1) == 1);
    CHECK(fact(2) == 2);
    CHECK(fact(3) == 6);
    CHECK(fact(10) == 3628800);
    CHECK(Tgame.initWindow()==0);
}


TEST_CASE("testing the start of the game") {

}



TEST_CASE("testing window initialization") {

}



TEST_CASE("checking whether there is X or 0 in square") {

}
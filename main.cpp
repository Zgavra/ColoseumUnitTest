#include <iostream>
#include "UnitTest++.h"
#include <Coloseum.h>
#include "Bow.h"
#include "Gladiator.h"

using namespace std;

int main()
{
    return UnitTest::RunAllTests();
}

TEST(MakeAFight_ResultDraw) {
    Coloseum coloseum;
    CHECK(coloseum.MakeAFight(1, 1) == 0);
    CHECK(coloseum.MakeAFight(2, 2) == 0);
    CHECK(coloseum.MakeAFight(3, 3) == 0);
}

TEST(MakeAFight_Gladiator1Wins)
{
    Coloseum coloseum;
    CHECK(coloseum.MakeAFight(1, 2) == 1);
    CHECK(coloseum.MakeAFight(2, 3) == 1);
    CHECK(coloseum.MakeAFight(3, 1) == 1);
}

TEST(MakeAFight_Gladiator2Wins)
{
    Coloseum coloseum;
    CHECK(coloseum.MakeAFight(2, 1) == 2);
    CHECK(coloseum.MakeAFight(3, 2) == 2);
    CHECK(coloseum.MakeAFight(1, 3) == 2);
}

TEST(MakeAFight_InvlaidWeapons)
{
    Coloseum coloseum;
    CHECK(coloseum.MakeAFight(23213, -123) == -1);
    CHECK(coloseum.MakeAFight(3, 265464) == -1);
    CHECK(coloseum.MakeAFight(-1542342, 3) == -1);
}

TEST(AddGladiator_Successful)
{
    Coloseum coloseum;
    Bow bow;
    Gladiator gladiator("Test gladiator", &bow);
    coloseum.AddGladiator(gladiator);
    CHECK(coloseum.GetAllGladiators().size() == 1);
}

TEST(RemoveGladiator_Successful)
{
    Coloseum coloseum;
    Bow bow;
    Gladiator gladiator("Test gladiator", &bow);
    coloseum.AddGladiator(gladiator);
    CHECK(coloseum.GetAllGladiators().size() == 1);
    coloseum.RemoveGladiator("Test gladiator");
    CHECK(coloseum.GetAllGladiators().size() == 0);
}

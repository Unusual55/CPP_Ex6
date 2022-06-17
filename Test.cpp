#include <iostream>
#include "doctest.h"
#include "sources/League.h"

TEST_CASE("Base cases"){
    League nba;
    CHECK_NOTHROW(nba.create_table());
    CHECK_NOTHROW(nba.forMoreThanAgainst());
    CHECK_NOTHROW(nba.longest_lose_streak());
    CHECK_NOTHROW(nba.longest_win_streak_first_round());
    CHECK_NOTHROW(nba.longest_win_streak_second_round());
    CHECK_NOTHROW(nba.topN(5));
    CHECK_THROWS(nba.topN(-1));
    CHECK_THROWS(nba.topN(21));
    CHECK_THROWS(Team("hello world FC", -1));
    CHECK_NOTHROW(Team("hello world CF", 1));
}
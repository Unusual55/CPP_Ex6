#include "Game.hpp"
#include "Schedule.hpp"
#include <unordered_set>
#include <string>
#include <memory>
using std::string;
const vector<string> teams_names{"Boston Celtics", "Chicago Bulls", "Atlanta Hawks", "Brooklyn Nets", "Cleveland Cavaliers",
                            "Charlotte Horents", "New York Knicks", "Detroit Pistons", "Miami Heat", "Philadelphia 76ers",
                            "Indiana Pacers", "Orlando Magic", "Toronto Raptors", "Milwaukee Bucks", "Washington Wizards",
                            "Los Angeles Lakers", "LA Clippers"};

bool teamComparator(shared_ptr<Team> &t1, shared_ptr<Team> &t2);

class League{
    vector<shared_ptr<Team>> teams;
    Schedule schedule;


public:
    League();


    void create_table();

    void topN(uint n);

    int longest_win_streak();

    int longest_lose_streak();

    int forMoreThanAgainst();

    int longest_win_streak_first_round();

    int longest_win_streak_second_round();

};
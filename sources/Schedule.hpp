#include "Team.hpp"
#include "Game.hpp"
#include <vector>
#include <exception>
#include <iostream>

using std::vector;
const uint round_robin = 19;
const uint end = 20;


struct Fixture {
    vector<Game> fix;
    uint fix_id;

    bool operator<(const Fixture &other) {
        return this->fix_id < other.fix_id;
    }
};

class Schedule {
    vector<shared_ptr<Team>> teams;
    vector<Fixture> fixtures;

    void create_schedule();

    void fix_match_order();

public:

    Schedule(vector<shared_ptr<Team>> &teams);

    Schedule(){}
};
#include "Team.hpp"
#include <random>
#include <cmath>
#include <memory>
using std::shared_ptr;

class Game{
    shared_ptr<Team> home_team;
    shared_ptr<Team> away_team;
    int home_score;
    int away_score;
    uint match_id;

public:

    Game(const shared_ptr<Team> &home, const shared_ptr<Team> &away, uint match_id);

    void play();

    void settle();



};
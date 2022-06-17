#include "Schedule.hpp"

Schedule::Schedule(vector<shared_ptr<Team>> &teams) {
    this->teams = teams;
    if (teams.size() != 20) {
        throw std::logic_error("You have to enter 20 teams to create a schedule");
    }
    create_schedule();
    fix_match_order();
}

void Schedule::create_schedule() {
    vector<shared_ptr<Team>> home_teams;
    vector<shared_ptr<Team>> away_teams;
    uint i = 0, j = 10;
    for (i = 0, j = 10; i < 10 && j < 20; i++, j++) {
        home_teams.emplace_back(this->teams[i]);
        away_teams.emplace_back(this->teams[j]);
    }
    uint fix = 1;
    for (fix = 1; fix < end; fix++) {
        Fixture fixture;
        Fixture next_round_fixture;
        fixture.fix_id = fix;
        next_round_fixture.fix_id = fix + round_robin;
        for (i = 0; i < 10; i++) {
            fixture.fix.emplace_back(Game(home_teams[i], away_teams[i], fix));
            next_round_fixture.fix.emplace_back(Game(away_teams[i], home_teams[i], fix+round_robin));
        }
        fixtures.emplace_back(fixture);
        fixtures.emplace_back(next_round_fixture);
        shared_ptr<Team> to_home = away_teams.front();
        shared_ptr<Team> to_away = home_teams.back();
        away_teams.erase(away_teams.begin());
        home_teams.pop_back();
        away_teams.emplace_back(to_away);
        home_teams.emplace(home_teams.cbegin() + 1, to_home);
    }
    std::sort(fixtures.begin(), fixtures.end());
}

void Schedule::fix_match_order(){
    uint i = 0;
    for(i=0;i<20;i++){
        teams[i]->sort_matches();
    }
}
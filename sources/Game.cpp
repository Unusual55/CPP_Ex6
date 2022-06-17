#include "Game.hpp"

Game::Game(const shared_ptr<Team> &home, const shared_ptr<Team> &away, uint match_id) :
        home_team(home), away_team(away), match_id(match_id) {
    play();
    settle();
}

void Game::play() {
    std::random_device rd{};
    std::mt19937 gen{rd()};
    std::normal_distribution<double> d{0.0, 1.0};
    double home_base = d(gen);
    home_base += 55;
    home_base += (home_team->getTalent() * 10);
    double away_base = d(gen);
    away_base += 50;
    away_base += (away_team->getTalent() * 10);
    home_score = home_base;
    away_score = away_base;
}

void Game::settle() {
    home_team->addMatch(match_id, home_score, away_score);
    away_team->addMatch(match_id, away_score, home_score);
}

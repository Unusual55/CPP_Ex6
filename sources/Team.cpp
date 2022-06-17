#include "Team.hpp"


Team::Team(string name, uint id): name(name), id(id){
    std::default_random_engine generator;
    std::uniform_real_distribution<double> distribution(0.0, 1.0);
    this->talent = distribution(generator);
}

Team::Team(const Team &other){
    this->name = other.name;
    this->talent = other.talent;
    this->id = other.id;
}

Team& Team::operator=(const Team &other){
    this->name = other.name;
    this->talent = other.talent;
    this->id = other.id;
    return *this;
}

bool Team::operator<(Team &other){
    return this->id<other.id;
}

string Team::getName(){
    return this->name;
}

double Team::getTalent(){
    return this->talent;
}

void Team::addMatch(int id, uint score_for, uint score_against){
    this->score_for += score_for;
    this->score_against += score_against;
    Match match;
    match.match_id=id;
    int result = 0;
    if(score_for<score_against){
        loses+=1;
        result=-1;
    }
    else if(score_for==score_against){
        result=0;
        this->points+=1;
    }
    else{
        result=1;
        this->points+=3;
        wins+=1;
    }
    match.result=result;
    this->matches.push_back(match);
    this->matches.shrink_to_fit();
}

void Team::sort_matches(){
    std::sort(matches.begin(), matches.end());
}

uint Team::get_for(){
    return score_for;
}

uint Team::get_against(){
    return score_against;
}

double Team::get_win_lose(){
    if(loses==0){
        return 38;
    }
    else{
        return wins/loses;
    }
}

int Team::get_score_diff(){
    return score_for-score_against;
}

vector<Match> Team::get_matches(){
    return this->matches;
}

double Team::for_against_rate(){
    return score_against/score_for;
}
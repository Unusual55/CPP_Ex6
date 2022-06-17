#include "League.h"
#include <cmath>
#include <iostream>
using std::cout;
using std::endl;
using std::abs;

League::League() {
    uint i = 0;
    for (i = 0; i < 20; i++) {
        Team t(teams_names[i], i);
        shared_ptr<Team> ptr = std::make_shared<Team>(t);
        teams.emplace_back(ptr);
    }
    schedule = Schedule(teams);
}

void League::create_table() {
    auto cmp = [](shared_ptr<Team> &t, shared_ptr<Team> &t2)
            { return teamComparator(t,t2);};
    std::sort(teams.begin(), teams.end(), cmp);
}

bool teamComparator(shared_ptr<Team> t1, shared_ptr<Team> t2) {
    uint win_lose1, win_lose2;
    win_lose1 = t1->get_win_lose();
    win_lose2 = t2->get_win_lose();
    if (win_lose1 > win_lose2) {
        return true;
    } else if (win_lose1 < win_lose2) {
        return false;
    }
    return t1->get_score_diff() > t2->get_score_diff();
}

void League::topN(uint n){
    if(n<0 || n>20){
        throw std::invalid_argument("bad input");
    }
    uint i=0;
    for(i=0;i<n;i++){
        cout<<i+1<<":\t"<<teams[i]->getName()<<endl;
    }
}

int League::longest_win_streak(){
    int total_max = 0;
    uint i = 0;
    for(i=0;i<teams.size();i++){
        int global_max = INT32_MIN, max_end = 0;
        uint j = 0;
        vector<Match> matches = teams[i]->get_matches();
        vector<int> results;
        for(j=0;j<matches.size();j++){
            results.push_back(matches[i].result);
        }
        for(j=0;j<38;j++){
            int score = matches[j].result;
            max_end = max_end + score;
            if(global_max< max_end){
                global_max = max_end;
            }
            if(max_end<0){
                max_end=0;
            }
        }
        if(total_max < global_max){
            total_max = global_max;
        }
    }
    return total_max;
}

int League::longest_lose_streak(){
    int total_min = 0;
    uint i = 0;
    for(i=0;i<teams.size();i++){
        int global_min = INT32_MAX, min_end = 0;
        uint j = 0;
        vector<Match> matches = teams[i]->get_matches();
        vector<int> results;
        for(j=0;j<matches.size();j++){
            results.push_back(matches[i].result);
        }
        for(j=0;j<38;j++){
            int score = matches[j].result;
            min_end = min_end + score;
            if(global_min> min_end){
                global_min = min_end;
            }
            if(min_end>0){
                min_end=0;
            }
        }
        if(total_min > global_min){
            total_min = global_min;
        }
    }
    return total_min*(-1);
}


int League::forMoreThanAgainst(){
    uint count = 0;
    uint i = 0;
    for(i=0;i<teams.size();i++){
        double rate = teams[i]->for_against_rate();
        if(rate<1){
            count++;
        }
    }
    return count;
}

int League::longest_win_streak_first_round(){
    int total_max = 0;
    uint i = 0;
    for(i=0;i<teams.size();i++){
        int global_max = INT32_MIN, max_end = 0;
        uint j = 0;
        vector<Match> matches = teams[i]->get_matches();
        vector<int> results;
        for(j=0;j<matches.size();j++){
            results.push_back(matches[i].result);
        }
        for(j=18;j<38;j++){
            int score = matches[j].result;
            max_end = max_end + score;
            if(global_max< max_end){
                global_max = max_end;
            }
            if(max_end<0){
                max_end=0;
            }
        }
        if(total_max < global_max){
            total_max = global_max;
        }
    }
    return total_max;
}

int League::longest_win_streak_second_round(){
    int total_max = 0;
    uint i = 0;
    for(i=0;i<teams.size();i++){
        int global_max = INT32_MIN, max_end = 0;
        uint j = 0;
        vector<Match> matches = teams[i]->get_matches();
        vector<int> results;
        for(j=0;j<matches.size();j++){
            results.push_back(matches[i].result);
        }
        for(j=19;j<38;j++){
            int score = matches[j].result;
            max_end = max_end + score;
            if(global_max< max_end){
                global_max = max_end;
            }
            if(max_end<0){
                max_end=0;
            }
        }
        if(total_max < global_max){
            total_max = global_max;
        }
    }
    return total_max;
}
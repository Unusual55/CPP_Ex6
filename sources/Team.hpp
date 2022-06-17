#include <string>
#include <random>
#include <vector>
using std::vector;
using std::string;

const int LOSS = -1;
const int DRAW = 0;
const int WIN = 1;

struct Match{
    uint match_id;
    int result;

    bool operator<(const Match &other){
        return this->match_id<other.match_id;
    }
};

class Team{
    string name;
    double talent;
    uint id;
    uint score_for=0;
    uint score_against=0;
    uint points=0;
    uint wins=0;
    uint loses=0;
    vector<Match> matches;

public:
    Team()=default;

    Team(string name, uint id);

    Team(const Team &other);

    Team& operator=(const Team &other);

    bool operator<(Team &other);

    string getName();

    double getTalent();

    void addMatch(int id, uint score_for, uint score_against);

    void sort_matches();

    uint get_for();

    uint get_against();

    uint get_wins();

    uint get_loses();

    double get_win_lose();

    int get_score_diff();

    vector<Match> get_matches();

    double for_against_rate();
};
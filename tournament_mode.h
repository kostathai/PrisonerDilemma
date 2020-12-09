#pragma once
#include "mode.h"
#include <map>
#include <set>
#include <string>
#include <vector>
typedef std::map<std::vector<char>, std::vector<int>> MATRIX_;


class Tournament : public PlayMode {
    void play(MATRIX_ &M, std::set<std::string> &names, int N) override;
    void PrintTournamentRes();
    void tour(std::set<std::string> &names, int N);
    std::map<std::string, int> score;
    void UpdateScore();
};

PlayMode *createTournamentMode();
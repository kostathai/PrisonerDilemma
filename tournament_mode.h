#pragma once
#include "mode.h"
#include <map>
#include <set>
#include <string>
#include <vector>
typedef std::map<std::vector<char>, std::vector<int>> MATRIX_;


class Tournament : public PlayMode {
    void play(Gamer gamer = {}) override;
    void PrintTournamentRes();
    void tour(std::set<std::string> &names);
    std::map<std::string, int> tournament_score;
    void UpdateScore();
};

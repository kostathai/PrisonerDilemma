#pragma once
#include "mode.h"
#include <map>
#include <set>
#include <string>
#include <vector>
typedef std::map<std::vector<char>, std::vector<int>> MATRIX_;


class Fast : public PlayMode {
    void play(MATRIX_ &M, std::set<std::string> &names, int N) override;
};

PlayMode *createFastMode();
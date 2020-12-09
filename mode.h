#pragma once
#include "strategy.h"
#include <iostream>
#include <map>
#include <memory>
#include <set>
#include <string>
#include <vector>

typedef std::map<std::vector<char>, std::vector<int>> MATRIX_;
typedef std::shared_ptr<Strategy> StrategyPtr;


class PlayMode {
public:
    virtual void play(MATRIX_ &M, std::set<std::string> &names, int N) = 0;
    std::vector<std::vector<char>> history = {{'C', 'C', 'C'}};
    void Initial(std::set<std::string> &names);
    void OneGame(bool detailed = false);
    virtual void PrintRes(const std::vector<char> &choice = {}, const std::vector<int> &res = {});
    MATRIX_ T;
    std::vector<StrategyPtr> str;
};

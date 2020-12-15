#pragma once
#include "strategy.h"
#include <iostream>
#include <map>
#include <memory>
#include <set>
#include <string>
#include <vector>
#include "gamer.h"

typedef std::map<std::vector<char>, std::vector<int>> MATRIX_;
typedef std::shared_ptr<Strategy> StrategyPtr;


class PlayMode {
public:
    virtual void play( Gamer gamer = {}) = 0;
    void InitialGame(const std::string& matr_conf, const int& steps, const std::set<std::string> &names, const std::string& str_conf);
    protected:
    std::vector<int> score;
    std::set<std::string> names_;
    std::string configs;
    int steps = 1000;
    std::vector<std::vector<char>> history = {{'C', 'C', 'C'}};
    void Initial(const std::set<std::string> &names,const std::string &configs);
    void OneGame(bool detailed = false);
    virtual void PrintRes(const std::vector<char> &choice = {}, const std::vector<int> &res = {});
    MATRIX_ matrix;
    std::vector<StrategyPtr> str;


};
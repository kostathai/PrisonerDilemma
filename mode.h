#pragma once
#include "strategy.h"
#include <map>
#include <memory>
#include <set>
#include <string>
typedef std::shared_ptr<Strategy> StrategyPtr;

std::vector<StrategyPtr> Initial(std::set<std::string> &names);

void UpdateScore(const std::vector<StrategyPtr>& str, std::map<std::string, int> &score );

void PrintResOneGame(const std::vector<char>& choice, const std::vector<int>& res,
                     const std::vector<StrategyPtr>& str);

void OneGame(std::vector<StrategyPtr> str,
             std::vector<std::vector<char>> &history, bool detailed);

void PrintGameRes(std::vector<StrategyPtr>& str);

void fast(std::set<std::string> &names, int N);

void detailed(std::set<std::string> &names);

void tour(std::set<std::string> &names, std::map<std::string, int> &score);

void PrintResTour(const std::map<std::string, int>& score);

void tournament(std::set<std::string> &names);
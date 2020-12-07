#pragma once
#include "strategy.h"
#include <map>
#include <memory>
#include <set>
#include <string>
typedef  std::map<std::vector<char>, std::vector<int>> MATRIX_;
typedef std::shared_ptr<Strategy> StrategyPtr;


std::vector<StrategyPtr> Initial(std::set<std::string> &names);

void UpdateScore(const std::vector<StrategyPtr>& str, std::map<std::string, int> &score );

void PrintResOneGame(const std::vector<char>& choice, const std::vector<int>& res,
                     const std::vector<StrategyPtr>& str);

void OneGame(const MATRIX_ &T, std::vector<StrategyPtr> str,
             std::vector<std::vector<char>> &history, bool detailed = false);

void PrintGameRes(std::vector<StrategyPtr>& str);

void PrintResTour(const std::map<std::string, int>& score);


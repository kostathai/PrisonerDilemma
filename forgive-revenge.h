#pragma once
#include "strategy.h"
#include <iostream>
#include <vector>

class FR : public Strategy {
public:
    char choice(int, std::vector<std::vector<char>> &) override;
    std::string name() override;
};

Strategy *createFR();
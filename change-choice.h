#pragma once
#include "strategy.h"
#include <iostream>
#include <vector>

class CChoice : public Strategy {
public:
    char choice (int, std::vector<std::vector<char>>&) override;
    std::string name() override;
};

Strategy *createCChoice ();
#pragma once
#include "strategy.h"
#include <iostream>
#include <vector>

class CChoice : public Strategy {
public:
    char choice (std::vector<std::vector<char>>&) override;
    std::string name() override;
    int cchoice_number = 10;
    void GetInformation(const std::string&) override;
};

Strategy *createCChoice ();
#pragma once
#include <vector>
#include <string>



class Strategy {
public:
    virtual char choice(int, std::vector<std::vector<char>>&) = 0;
    int score = 0;
    virtual std::string name() = 0;
};
typedef Strategy* (*creator_t)();
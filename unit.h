#pragma once
#include <vector>




class Unit {
public:
    virtual char choice(int, std::vector<std::vector<char>>&) = 0;
    virtual  ~Unit() {};
    int score = 0;
};
typedef Unit* (*creator_t)();
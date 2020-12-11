#pragma once
#include <string>
#include <vector>


class Strategy {
public:
    virtual char choice(int, std::vector<std::vector<char>> &) = 0;
    int score = 0;
    virtual std::string name() = 0;
    virtual void GetInformation(std::string &) {}
};
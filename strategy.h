#pragma once
#include <string>
#include <vector>


class Strategy {
public:
    virtual char choice( std::vector<std::vector<char>> &) = 0;
    int number_in_history = 0;
    virtual std::string name() = 0;
    virtual void GetInformation(const std::string &) {}
};
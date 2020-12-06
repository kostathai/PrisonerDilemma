#include "strategy.h"
#include <vector>
#include <iostream>

class AllD : public Strategy {
public:
    char choice (int,std::vector<std::vector<char>>&) override;
    std::string name() override;
};

Strategy *createAllD ();
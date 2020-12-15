#include "strategy.h"
#include <vector>
#include <iostream>

class AllD : public Strategy {
public:
    char choice (std::vector<std::vector<char>>&) override;
    std::string name() override;
};

Strategy *createAllD ();
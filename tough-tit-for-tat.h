#include "strategy.h"
#include <iostream>
#include <vector>

class TTFT : public Strategy {
public:
    char choice(std::vector<std::vector<char>> &) override;
    std::string name() override;
};

Strategy *createTTFT();
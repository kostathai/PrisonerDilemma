#include "unit.h"
#include <vector>
#include <iostream>

class Rand : public Unit {
public:
    char choice (int, std::vector<std::vector<char>>&) override;
};

Unit *createRand ();
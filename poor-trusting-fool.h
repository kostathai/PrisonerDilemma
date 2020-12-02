#include "unit.h"
#include <vector>
#include <iostream>

class PTF : public Unit {
public:
    char choice (int, std::vector<std::vector<char>>&) override;
};

Unit *createPTF ();
#include "unit.h"
#include <vector>
#include <iostream>

class AllD : public Unit {
public:
    char choice (int,std::vector<std::vector<char>>&) override;
};

Unit *createAllD ();
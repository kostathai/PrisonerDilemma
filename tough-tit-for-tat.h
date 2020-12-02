#include "unit.h"
#include <vector>
#include <iostream>

class TTTT : public Unit {
public:
    char choice (int,std::vector<std::vector<char>>&) override;
};

Unit *createTTTT ();
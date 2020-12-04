#include "unit.h"
#include <vector>
#include <iostream>

class STTT : public Unit {
public:
    char choice (int,std::vector<std::vector<char>>&) override;
};

Unit *createSTTT ();
#include "all-defect.h"
#include "factory.h"
#include <iostream>

namespace {
    bool g(){
        Factory<Unit, std::string, Unit*(*)()>::getInstance()->addCreator("all-defect", createAllD);
        return true;
    }
    static bool b = g();
}

Unit* createAllD(){
    return new AllD;
}

char AllD::choice(int, std::vector<std::vector<char>>&){
    return 'D';
}

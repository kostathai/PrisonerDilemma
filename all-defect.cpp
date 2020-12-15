#include "all-defect.h"
#include "factory.h"
#include <iostream>

namespace {
    bool g(){
        Factory<Strategy, std::string, Strategy*(*)()>::getInstance()->addCreator("all-defect", createAllD);
        return true;
    }
    static bool b = g();
}

Strategy* createAllD(){
    return new AllD;
}

char AllD::choice(std::vector<std::vector<char>>&){
    return 'D';
}

std::string AllD::name(){
    return "all-defect";
}
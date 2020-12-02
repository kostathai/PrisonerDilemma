#include "poor-trusting-fool.h"
#include "factory.h"
#include <iostream>



namespace {
    bool g(){
        Factory<Unit, std::string, Unit*(*)()>::getInstance()->addCreator("poor-trusting-fool", createPTF);
        return true;
    }
    static bool b = g();
}

Unit* createPTF(){
    return new PTF;
}

char PTF::choice(int, std::vector<std::vector<char>>&){
    return 'C';
}
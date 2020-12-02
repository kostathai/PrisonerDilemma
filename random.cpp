#include "random.h"
#include "factory.h"
#include <iostream>



namespace {
    bool g(){
        Factory<Unit, std::string, Unit*(*)()>::getInstance()->addCreator("random", createRand);
        return true;
    }
    static bool b = g();
}

Unit* createRand(){
    return new Rand;
}

char Rand::choice( int, std::vector<std::vector<char>>&){
    if(rand()% 2 == 1)
        return 'D';
    return 'C';
}
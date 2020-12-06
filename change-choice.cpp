#include "change-choice.h"
#include "factory.h"
#include <iostream>



namespace {
    bool g(){
        Factory<Strategy, std::string, Strategy*(*)()>::getInstance()->addCreator("change-choice", createCChoice);
        return true;
    }
    static bool b = g();
}

Strategy* createCChoice(){
    return new CChoice;
}

char CChoice::choice(int str_num, std::vector<std::vector<char>>& history){
    if((history.size() / 10) % 2 != 0)
        return 'D';
    return 'C';
}

std::string CChoice::name(){
    return "change-choice";
}
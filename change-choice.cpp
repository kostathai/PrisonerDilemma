#include "change-choice.h"
#include "factory.h"
#include <iostream>
#include <fstream>


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

char CChoice::choice( std::vector<std::vector<char>>& history){
    if (((history.size() - 1 )/ cchoice_number) % 2 != 0)
        return 'D';
    return 'C';
}

std::string CChoice::name(){
    return "change-choice";
}
void CChoice::GetInformation(const std::string & dir) {
    std::ifstream in(dir+"change-choice.txt");
    if(in.is_open()) {
        in >> cchoice_number;
    }
    else throw std::runtime_error("FILE change-choice.txt NOT FOUND IN DIRECTORY "+ dir);
}

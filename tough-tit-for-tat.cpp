#include "tough-tit-for-tat.h"
#include "factory.h"
#include <iostream>

namespace {
    bool g(){
        Factory<Strategy, std::string, Strategy*(*)()>::getInstance()->addCreator("tough-tit-for-tat", createTTFT);
        return true;
    }
    static bool b = g();
}

Strategy* createTTFT(){
    return new TTFT;
}

char TTFT::choice(int str_num, std::vector<std::vector<char>>& history){
    int s = history.size();
    if((history[s-1][0] == 'C' or str_num == 0) and (history[s-1][1] == 'C' or str_num == 1) and (history[s-1][2] == 'C' or str_num == 2))
        return 'C';
    return 'D';
}

std::string TTFT::name(){
    return "tough-tit-for-tat";
}
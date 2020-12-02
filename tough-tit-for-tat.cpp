#include "tough-tit-for-tat.h"
#include "factory.h"
#include <iostream>

namespace {
    bool g(){
        Factory<Unit, std::string, Unit*(*)()>::getInstance()->addCreator("tough-tit-for-tat", createTTTT);
        return true;
    }
    static bool b = g();
}

Unit* createTTTT(){
    return new TTTT;
}

char TTTT::choice(int i, std::vector<std::vector<char>>& h){
    int s = h.size();
    if((h[s-1][0] == 'C' or i == 0) and (h[s-1][1] == 'C' or i == 1) and (h[s-1][2] == 'C' or i == 2))
        return 'C';
    return 'D';
}

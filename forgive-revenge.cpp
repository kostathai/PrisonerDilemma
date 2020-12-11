#include "forgive-revenge.h"
#include "factory.h"
#include <iostream>

namespace {
    bool g() {
        Factory<Strategy, std::string, Strategy *(*) ()>::getInstance()->addCreator("forgive-revenge", createFR);
        return true;
    }
    static bool b = g();
}// namespace

Strategy *createFR() {
    return new FR;
}

char FR::choice(int i, std::vector<std::vector<char>> &h) {
    int s = h.size();
    if ((h[s - 1][0] == 'D' or i == 0) and (h[s - 1][1] == 'D' or i == 1) and (h[s - 1][2] == 'D' or i == 2))
        return 'D';
    if ((h[s - 1][0] == 'C' or i == 0) and (h[s - 1][1] == 'C' or i == 1) and (h[s - 1][2] == 'C' or i == 2))
        return 'C';
    return h[s - 1][i];
}

std::string FR::name() {
    return "forgive-revenge";
}
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

char FR::choice(std::vector<std::vector<char>> &h) {
    int s = h.size();
    if ((h[s - 1][0] == 'D' or number_in_history == 0) and (h[s - 1][1] == 'D' or number_in_history == 1) and (h[s - 1][2] == 'D' or number_in_history == 2))
        return 'D';
    if ((h[s - 1][0] == 'C' or number_in_history == 0) and (h[s - 1][1] == 'C' or number_in_history == 1) and (h[s - 1][2] == 'C' or number_in_history == 2))
        return 'C';
    return h[s - 1][number_in_history];
}

std::string FR::name() {
    return "forgive-revenge";
}
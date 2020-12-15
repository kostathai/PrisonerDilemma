#include "soft-tit-for-tat.h"
#include "factory.h"
#include <iostream>

namespace {
    bool g() {
        Factory<Strategy, std::string, Strategy *(*) ()>::getInstance()->addCreator("soft-tit-for-tat", createSTFT);
        return true;
    }
    static bool b = g();
}// namespace

Strategy *createSTFT() {
    return new STFT;
}

char STFT::choice(std::vector<std::vector<char>> &h) {
    int s = h.size();
    if ((h[s - 1][0] == 'D' or number_in_history == 0) and (h[s - 1][1] == 'D' or number_in_history == 1) and (h[s - 1][2] == 'D' or number_in_history == 2))
        return 'D';
    return 'C';
}

std::string STFT::name() {
    return "soft-tit-for-tat";
}
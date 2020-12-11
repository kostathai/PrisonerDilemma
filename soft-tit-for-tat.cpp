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

char STFT::choice(int i, std::vector<std::vector<char>> &h) {
    int s = h.size();
    if ((h[s - 1][0] == 'D' or i == 0) and (h[s - 1][1] == 'D' or i == 1) and (h[s - 1][2] == 'D' or i == 2))
        return 'D';
    return 'C';
}

std::string STFT::name() {
    return "soft-tit-for-tat";
}
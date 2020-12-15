#include "poor-trusting-fool.h"
#include "factory.h"
#include <iostream>


namespace {
    bool g() {
        Factory<Strategy, std::string, Strategy *(*) ()>::getInstance()->addCreator("poor-trusting-fool", createPTF);
        return true;
    }
    static bool b = g();
}// namespace

Strategy *createPTF() {
    return new PTF;
}

char PTF::choice(std::vector<std::vector<char>> &) {
    return 'C';
}

std::string PTF::name() {
    return "poor-trusting-fool";
}
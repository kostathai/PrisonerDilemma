#include "random.h"
#include "factory.h"
#include <iostream>


namespace {
    bool g() {
        Factory<Strategy, std::string, Strategy *(*) ()>::getInstance()->addCreator("random", createRand);
        return true;
    }
    static bool b = g();
}// namespace

Strategy *createRand() {
    return new Rand;
}

char Rand::choice(std::vector<std::vector<char>> &) {
    if (rand() % 2 == 1)
        return 'D';
    return 'C';
}

std::string Rand::name() {
    return "random";
}
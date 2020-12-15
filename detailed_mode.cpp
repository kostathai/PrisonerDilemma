#include "detailed_mode.h"
#include "factory.h"
#include <iomanip>

namespace {
    PlayMode *createDetailedMode() {
        return new Detailed;
    }
    bool gen() {
        Factory<PlayMode, std::string, PlayMode *(*) ()>::getInstance()->addCreator("detailed", createDetailedMode);
        return true;
    }
    static bool d = gen();
}// namespace



void Detailed::play( Gamer gamer) {
    Initial(names_, configs);
    while (!gamer.Exit()) {
        OneGame(true);
    }
}
void Detailed::PrintRes(const std::vector<char> &choice, const std::vector<int> &res) {
    std::cout.setf(std::ios::fixed);
    std::cout << std::setw(20) << std::left << "Strategy's name" << std::setw(8) << "choice" << std::setw(8) << "points" << std::setw(10) << "score" << std::endl;
    for (int i = 0; i < 3; ++i)
        std::cout << std::setw(20) << std::left << str[i]->name() << std::setw(8)
                  << choice[i] << std::setw(8) << res[i] << std::setw(10) << score[i] << std::endl;
    std::cout << "Press any key to continue or 'q' to exit:" << std::endl;
}


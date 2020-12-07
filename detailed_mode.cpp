#include "detailed_mode.h"
#include "mode.h"
#include <conio.h>

void detailed(const MATRIX_ &T, std::set<std::string> &names) {
    std::vector<StrategyPtr> str = Initial(names);
    std::vector<std::vector<char>> history;
    history.push_back({'C', 'C', 'C'});
    while (true) {
        OneGame(T, str, history, true);
        char c = getch();
        if (c == 'q')
            return;
    }
}
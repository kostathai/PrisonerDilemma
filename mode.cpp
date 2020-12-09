#include "mode.h"
#include "factory.h"
#include "table.h"
#include <iomanip>
#include <iostream>
typedef std::shared_ptr<Strategy> StrategyPtr;

//один шаг от каждой стратегии, запись в исторю, вывод результатов для детализированной игры
void PlayMode::OneGame(bool detailed) {
    std::vector<char> choice = {str[0]->choice(0, history), str[1]->choice(1, history), str[2]->choice(2, history)};
    history.push_back(choice);
    std::vector<int> res = T.at(choice);
    str[0]->score += res[0];
    str[1]->score += res[1];
    str[2]->score += res[2];
    if (detailed)
        PrintRes(choice, res);
}
void PlayMode::Initial(std::set<std::string> &names) {
    std::string n1, n2, n3;
    auto n = names.begin();
    n1 = *n;
    n2 = *(++n);
    n3 = *(++n);
    StrategyPtr str1(Factory<Strategy, std::string, Strategy *(*) ()>::getInstance()->makeObject(n1));
    StrategyPtr str2(Factory<Strategy, std::string, Strategy *(*) ()>::getInstance()->makeObject(n2));
    StrategyPtr str3(Factory<Strategy, std::string, Strategy *(*) ()>::getInstance()->makeObject(n3));
    str = {str1, str2, str3};
}

void PlayMode::PrintRes(const std::vector<char> &choice, const std::vector<int> &res) {
    std::cout.setf(std::ios::fixed);
    std::cout << std::setw(20) << std::left << "Strategy's name" << std::setw(10) << "score" << std::endl;
    for (const auto &i : str)
        std::cout << std::setw(20) << std::left << i->name() << std::setw(10) << i->score << std::endl;
    int best = str[0]->score > str[1]->score ? str[0]->score : str[1]->score;
    best = best > str[2]->score ? best : str[2]->score;
    for (const auto &i : str) {
        if (i->score == best)
            std::cout << i->name() << " ";
    }

    std::cout << "WIN with score " << best << std::endl
              << std::endl;
}

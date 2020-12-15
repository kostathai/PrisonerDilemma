#include "mode.h"
#include "factory.h"
#include "table.h"
#include <iomanip>
#include <iostream>
#include <algorithm>

typedef std::shared_ptr<Strategy> StrategyPtr;

void PlayMode::InitialGame(const std::string& matr_conf, const int& steps_, const std::set<std::string> &names, const std::string& str_conf){
    matrix = CreateMatrix(matr_conf);
    steps = steps_;
    names_ = names;
    configs = str_conf;
}


//один шаг от каждой стратегии, запись в исторю, вывод результатов для детализированной игры
void PlayMode::OneGame(bool detailed) {
    std::vector<char> choice = {str[0]->choice( history), str[1]->choice(history), str[2]->choice(history)};
    history.push_back(choice);
    std::vector<int> res = matrix.at(choice);
    for(int i = 0; i < 3; ++i){
        score[i] +=res[i];
    }
    if (detailed) {
        PrintRes(choice, res);
    }
}
void PlayMode::Initial(const std::set<std::string> &names,const std::string &configs) {
    std::string n1, n2, n3;
    auto n = names.begin();
    n1 = *n;
    n2 = *(++n);
    n3 = *(++n);
    StrategyPtr str1(Factory<Strategy, std::string, Strategy *(*) ()>::getInstance()->makeObject(n1));
    StrategyPtr str2(Factory<Strategy, std::string, Strategy *(*) ()>::getInstance()->makeObject(n2));
    StrategyPtr str3(Factory<Strategy, std::string, Strategy *(*) ()>::getInstance()->makeObject(n3));
    str = {str1, str2, str3};
    for (int i = 0; i < str.size(); ++i) {
        str[i]->number_in_history = i;
        str[i]->GetInformation(configs);
    }
    score = {0, 0, 0};
}

void PlayMode::PrintRes(const std::vector<char> &choice, const std::vector<int> &res) {
    std::cout.setf(std::ios::fixed);
    std::cout << std::setw(20) << std::left << "Strategy's name"
              << std::setw(10) << "score" << std::endl;
    for (int i = 0; i < str.size(); ++i) {
        std::cout << std::setw(20) << std::left << str[i]->name()
                  << std::setw(10) << score[i] << std::endl;
    }
    int best = *std::max_element(score.begin(), score.end());
    for (int i = 0; i < str.size(); ++i) {
        if (score[i] == best) {
            std::cout << str[i]->name() << " ";
        }
    }
    std::cout << "WIN with score " << best << std::endl
              << std::endl;
}
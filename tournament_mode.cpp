#include "tournament_mode.h"
#include "mode.h"
#include <iostream>

void tournament(const MATRIX_ &T,std::set<std::string> &names, int N) {
    std::map<std::string, int> score;
    for (const auto &i : names)
        score[i] = 0;


    auto i_n1 = names.begin();
    int tour_count = 0;
    for (int i = 0; i < names.size(); ++i, ++i_n1) {//собираю тройку
        auto j_n2 = i_n1;
        j_n2++;
        for (int j = i + 1; j < names.size(); ++j, ++j_n2) {
            auto k_n3 = j_n2;
            k_n3++;
            for (int k = j + 1; k < names.size(); ++k, ++k_n3) {
                std::cout << "         TOUR #" << ++tour_count << std::endl;
                std::set<std::string> tour_names({*i_n1, *j_n2, *k_n3});
                tour(T, tour_names, score, N);
            }
        }
    }

    PrintResTour(score);
}

void tour(const MATRIX_ &T,std::set<std::string> &names, std::map<std::string, int> &score, int N) {
    std::vector<StrategyPtr> str = Initial(names);
    std::vector<std::vector<char>> history;
    history.push_back({'C', 'C', 'C'});
    for (int i = 0; i < N; ++i)
        OneGame(T, str, history);
    UpdateScore(str, score);
    PrintGameRes(str);
}

#include "tournament_mode.h"
#include "factory.h"
#include <iomanip>

namespace {
    bool gen() {
        Factory<PlayMode, std::string, PlayMode *(*) ()>::getInstance()->addCreator("tournament", createTournamentMode);
        return true;
    }
    static bool d = gen();
}

PlayMode *createTournamentMode() {
    return new Tournament;
}

void Tournament::play(MATRIX_ &M, std::set<std::string> &names, int N, std::string configs, Gamer gamer) {
    T = M;
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
                tour(tour_names, N, configs);
            }
        }
    }
    PrintTournamentRes();
}
void Tournament::tour(std::set<std::string> &names, int N, std::string configs) {
    Initial(names, configs);
    std::vector<std::vector<char>> history;
    history.push_back({'C', 'C', 'C'});
    for (int i = 0; i < N; ++i)
        OneGame();
    UpdateScore();
    PrintRes();
}

void Tournament::UpdateScore() {
    score[str[0]->name()] += str[0]->score;
    score[str[1]->name()] += str[1]->score;
    score[str[2]->name()] += str[2]->score;
}


void Tournament::PrintTournamentRes() {
    std::string n;
    int max = 0;
    std::cout.setf(std::ios::fixed);
    std::cout << std::setw(20) << "         RESULTS" << std::endl;
    std::cout << std::setw(20) << std::left << "Strategy's name" << std::setw(10) << "score" << std::endl;
    for (const auto &i : score) {
        std::cout << std::setw(20) << std::left << i.first << std::setw(10) << i.second << std::endl;
        if (i.second > max) {
            max = i.second;
            n = i.first;
        }
    }
    std::cout << std::endl
              << n << " TOTAL WIN" << std::endl;
}

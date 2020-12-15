#include "tournament_mode.h"
#include "factory.h"
#include <iomanip>

namespace {
    PlayMode *createTournamentMode() {
        return new Tournament;
    }

    bool gen() {
        Factory<PlayMode, std::string, PlayMode *(*) ()>::getInstance()->addCreator("tournament", createTournamentMode);
        return true;
    }
    static bool d = gen();
}



void Tournament::play( Gamer gamer) {
    for (const auto &i : names_)
        tournament_score[i] = 0;
    auto i_n1 = names_.begin();
    int tour_count = 0;
    for (int i = 0; i < names_.size(); ++i, ++i_n1) {//собираю тройку
        auto j_n2 = i_n1;
        j_n2++;
        for (int j = i + 1; j < names_.size(); ++j, ++j_n2) {
            auto k_n3 = j_n2;
            k_n3++;
            for (int k = j + 1; k < names_.size(); ++k, ++k_n3) {
                std::cout << "         TOUR #" << ++tour_count << std::endl;
                std::set<std::string> tour_names({*i_n1, *j_n2, *k_n3});
                tour(tour_names);
            }
        }
    }
    PrintTournamentRes();
}

void Tournament::tour(std::set<std::string> &names) {
    Initial(names, configs);
    std::vector<std::vector<char>> history;
    history.push_back({'C', 'C', 'C'});
    for (int i = 0; i < steps; ++i)
        OneGame();
    UpdateScore();
    PrintRes();
}

void Tournament::UpdateScore() {
    tournament_score[str[0]->name()] += score[0];
    tournament_score[str[1]->name()] += score[1];
    tournament_score[str[2]->name()] += score[2];
}


void Tournament::PrintTournamentRes() {
    std::string n;
    int max = 0;
    std::cout.setf(std::ios::fixed);
    std::cout << std::setw(20) << "         RESULTS" << std::endl;
    std::cout << std::setw(20) << std::left << "Strategy's name" << std::setw(10) << "score" << std::endl;
    for (const auto &i : tournament_score) {
        std::cout << std::setw(20) << std::left << i.first << std::setw(10) << i.second << std::endl;
        if (i.second > max) {
            max = i.second;
            n = i.first;
        }
    }
    std::cout << std::endl
              << n << " TOTAL WIN" << std::endl;
}

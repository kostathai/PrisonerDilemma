#include "mode.h"
#include "factory.h"
#include "table.h"
#include <conio.h>
#include <iomanip>
#include <iostream>
typedef std::shared_ptr<Strategy> StrategyPtr;

std::vector<StrategyPtr> Initial(std::set<std::string> &names){
    std::string n1, n2, n3;
    auto n = names.begin();
    n1 = *n;
    n2 = *(++n);
    n3 = *(++n);
    StrategyPtr str1(Factory<Strategy, std::string, Strategy *(*) ()>::getInstance()->makeStrategy(n1));
    StrategyPtr str2(Factory<Strategy, std::string, Strategy *(*) ()>::getInstance()->makeStrategy(n2));
    StrategyPtr str3(Factory<Strategy, std::string, Strategy *(*) ()>::getInstance()->makeStrategy(n3));
    std::vector<StrategyPtr> str = {str1, str2, str3};
    return str;
}



void UpdateScore(const std::vector<StrategyPtr>& str, std::map<std::string, int> &score ){
    score[str[0]->name()] += str[0]->score;
    score[str[1]->name()] += str[1]->score;
    score[str[2]->name()] += str[2]->score;

}

void PrintResOneGame(const std::vector<char>& choice, const std::vector<int>& res,
                     const std::vector<StrategyPtr>& str){
    std::cout.setf(std::ios::fixed);
    std::cout << std::setw(20) << std::left << "Strategy's name" << std::setw(8) << "choice" << std::setw(8) << "points" << std::setw(10) << "score" << std::endl;
    std::cout << std::setw(20) << std::left << str[0]->name() << std::setw(8)
              << choice[0] << std::setw(8) << res[0] << std::setw(10) << str[0]->score << std::endl;
    std::cout << std::setw(20) << std::left << str[1]->name() << std::setw(8)
              << choice[1] << std::setw(8) << res[1] << std::setw(10) << str[1]->score << std::endl;
    std::cout << std::setw(20) << std::left << str[2]->name() << std::setw(8)
              << choice[2] << std::setw(8) << res[2] << std::setw(10) << str[2]->score << std::endl;
    std::cout << "Press any key to continue or 'q' to exit:" << std::endl;
}

//один шаг от каждой стратегии, запись в исторю, вывод результатов для детализированной игры
void OneGame(std::vector<StrategyPtr> str,
             std::vector<std::vector<char>> &history, bool detailed = false) {
    // char -> enum
    std::vector<char> choice = {str[0]->choice(0, history), str[1]->choice(1, history), str[2]->choice(2, history)};
    history.push_back(choice);
    std::vector<int> res = T.at(choice);
    str[0]->score += res[0];
    str[1]->score += res[1];
    str[2]->score += res[2];
    if (detailed)
        PrintResOneGame(choice, res, str);
}

void PrintGameRes(std::vector<StrategyPtr>& str){
    std::cout.setf(std::ios::fixed);
    std::cout << std::setw(20) << std::left << "Strategy's name" << std::setw(10) << "score" << std::endl;
    for (const auto& i : str)
        std::cout << std::setw(20) << std::left << i->name() << std::setw(10) << i->score << std::endl;
    int best = str[0]->score > str[1]->score ? str[0]->score : str[1]->score;
    best = best > str[2]->score ? best : str[2]->score;
    for (const auto& i : str) {
        if (i->score == best)
            std::cout << i->name() << " ";
    }

    std::cout << "WIN with score " << best << std::endl;
}

void fast(std::set<std::string> &names, int N) {
    std::vector<StrategyPtr> str = Initial(names);
    std::vector<std::vector<char>> history;
    history.push_back({'C', 'C', 'C'});
    for (int i = 0; i < N; ++i)
        OneGame(str, history);
    PrintGameRes(str);
}

void detailed(std::set<std::string> &names) {
    std::vector<StrategyPtr> str = Initial(names);
    std::vector<std::vector<char>> history;
    history.push_back({'C', 'C', 'C'});
    while (true) {
        OneGame(str, history, true);
        char c = getch();
        if (c == 'q')
            return;
    }
}

void tour(std::set<std::string> &names, std::map<std::string, int> &score) {
    int N = 100;
    std::vector<StrategyPtr> str = Initial(names);
    std::vector<std::vector<char>> history;
    history.push_back({'C', 'C', 'C'});
    for (int i = 0; i < N; ++i)
        OneGame(str, history);
    UpdateScore(str, score);
    PrintGameRes(str);
}

void PrintResTour(const std::map<std::string, int>& score){
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
void tournament(std::set<std::string> &names) {
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
                tour(tour_names, score);
            }
        }
    }

    PrintResTour(score);
}
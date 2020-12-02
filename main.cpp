#include "factory.h"
#include "table.h"
#include <conio.h>
#include <iomanip>
#include <iostream>
#include <string>
#include <set>
#include <memory>

void OneGame(std::unique_ptr<Unit>& str1, std::unique_ptr<Unit>& str2, std::unique_ptr<Unit>& str3,
             std::vector<std::vector<char>>& history, bool B = false , char* n1 = 0, char* n2 = 0, char* n3 = 0){
    std::vector<char> choice = {str1->choice(0, history), str2->choice(1, history), str3->choice(2, history)};
    history.push_back(choice);
    std::vector<int> res = T[choice];
    str1->score += res[0];
    str2->score += res[1];
    str3->score += res[2];
    if(B){
        std::cout.setf(std::ios::fixed);
        std::cout << std::setw(20)<<std::left<<"strategy's name"<< std::setw(8)<<"choice"<< std::setw(8)<<"points"<< std::setw(10)<<"score"<<std::endl;
        std::cout << std::setw(20)<<std::left<<n1<< std::setw(8)<<choice[0]<< std::setw(8)<<res[0]<< std::setw(10)<< str1->score <<std::endl;
        std::cout << std::setw(20)<<std::left<<n2<< std::setw(8)<<choice[1]<< std::setw(8)<<res[1]<< std::setw(10)<< str2->score <<std::endl;
        std::cout << std::setw(20)<<std::left<<n3<< std::setw(8)<<choice[2]<< std::setw(8)<<res[2]<< std::setw(10)<< str3->score <<std::endl;
        std::cout << "Press any key to continue or 'q' to exit:"<<std::endl;
    }
}


void fast(char* n1, char* n2, char* n3, int N){
    std::unique_ptr<Unit> str1(Factory<Unit, std::string, Unit *(*) ()>::getInstance()->
            makeUnit(n1));
    std::unique_ptr<Unit> str2(Factory<Unit, std::string, Unit *(*) ()>::getInstance()->
            makeUnit(n2));
    std::unique_ptr<Unit> str3(Factory<Unit, std::string, Unit *(*) ()>::getInstance()->
            makeUnit(n3));
    std::vector<std::vector<char>> history;
    history.push_back({'C', 'C', 'C'});
    for(int i = 0; i < N; ++i)
        OneGame(str1, str2, str3, history);

    std::cout << std::setw(20)<<std::left<<"strategy's name"<< std::setw(10)<<"score"<<std::endl;
    std::cout << std::setw(20)<<std::left<<n1<< std::setw(10)<< str1->score <<std::endl;
    std::cout << std::setw(20)<<std::left<<n2<< std::setw(10)<< str2->score <<std::endl;
    std::cout << std::setw(20)<<std::left<<n3<< std::setw(10)<< str3->score <<std::endl;
    int best = str1->score > str2->score?str1->score:str2->score;
    best = best > str3->score? best:str3->score;
    if(str1->score == best)
        std::cout << n1 << " ";
    if(str2->score == best)
        std::cout << n2 << " ";
    if(str3->score == best)
        std::cout << n3 << " ";
    std::cout << "WIN with score "<<best<< std::endl;

}

void detailed(char* n1, char* n2, char* n3 ){
    std::unique_ptr<Unit> str1(Factory<Unit, std::string, Unit *(*) ()>::getInstance()->
            makeUnit(n1));
    std::unique_ptr<Unit> str2(Factory<Unit, std::string, Unit *(*) ()>::getInstance()->
            makeUnit(n2));
    std::unique_ptr<Unit> str3(Factory<Unit, std::string, Unit *(*) ()>::getInstance()->
            makeUnit(n3));
    std::vector<std::vector<char>> history;
    history.push_back({'C', 'C', 'C'});
    while(true){
        OneGame(str1, str2, str3, history, true, n1, n2, n3);
        char c = getch();
        if (c == 'q')
            return;
    }
}

void tour(const std::string& n1,const std::string& n2,const std::string& n3, std::map<std::string, int>& score){
    int N = 100;
    std::unique_ptr<Unit> str1(Factory<Unit, std::string, Unit *(*) ()>::getInstance()->
            makeUnit(n1));
    std::unique_ptr<Unit> str2(Factory<Unit, std::string, Unit *(*) ()>::getInstance()->
            makeUnit(n2));
    std::unique_ptr<Unit> str3(Factory<Unit, std::string, Unit *(*) ()>::getInstance()->
            makeUnit(n3));
    std::vector<std::vector<char>> history;
    history.push_back({'C', 'C', 'C'});
    for(int i = 0; i < N; ++i)
        OneGame(str1, str2, str3, history);
    score[n1] += str1->score;
    score[n2] += str2->score;
    score[n3] += str3->score;

    std::cout.setf(std::ios::fixed);
    std::cout << std::setw(20)<<std::left<<"strategy's name"<< std::setw(10)<<"score"<<std::endl;
    std::cout << std::setw(20)<<std::left<<n1<< std::setw(10)<< str1->score <<std::endl;
    std::cout << std::setw(20)<<std::left<<n2<< std::setw(10)<< str2->score <<std::endl;
    std::cout << std::setw(20)<<std::left<<n3<< std::setw(10)<< str3->score <<std::endl;
    int best = str1->score > str2->score?str1->score:str2->score;
    best = best > str3->score? best:str3->score;
    if(str1->score == best)
        std::cout << n1 << " ";
    if(str2->score == best)
        std::cout << n2 << " ";
    if(str3->score == best)
        std::cout << n3 << " ";
    std::cout << "WIN in tour with score "<<best<< std::endl<< std::endl;

}

void tournament(std::set<std::string>& names){
    std::map<std::string, int> score;
    for (const auto& i: names)
        score[i] = 0;
    auto i_n1 = names.begin();
    int tour_count = 0;
    for(int i = 0; i < names.size(); ++i, ++i_n1){
        auto j_n2 = i_n1;
        j_n2++;
        for(int j = i + 1; j < names.size(); ++j, ++j_n2){
            auto k_n3 = j_n2;
            k_n3++;
            for(int k = j + 1; k < names.size(); ++k, ++k_n3){
                std::cout<< "         TOUR #"<<++tour_count<< std::endl;
                tour( *i_n1,*j_n2, *k_n3, score);
            }
        }
    }
    std::string n;
    int max = 0;

    std::cout.setf(std::ios::fixed);
    std::cout << std::setw(20) << "         RESULTS" << std::endl;
    std::cout << std::setw(20)<<std::left<<"strategy's name"<< std::setw(10)<<"score"<<std::endl;
    for(const auto& i:score){
        std::cout << std::setw(20)<<std::left<<i.first<< std::setw(10)<< i.second <<std::endl;
        if(i.second > max){
            max = i.second;
            n = i.first;
        }
    }
    std::cout << std::endl<< n << " TOTAL WIN" << std::endl;
}

template<typename T>
T convert(char* arg){
    std::stringstream convert(arg);
    T n;
    convert >> n;
    return n;
}

int main(int argc, char* argv[]) {
    if (argc < 4) return -1;
    if(argc >= 5)
    if (argc == 4 or (argc >= 5 and convert<std::string>(argv[4]) == "--mode=detailed")) {
        detailed(argv[1], argv[2], argv[3]);
    }else if(convert<std::string>(argv[4]) == "--mode=fast"){
        int steps = 1000;
        if(argc >=7) {
            std::string s = convert<std::string>(argv[5]);
            if (s.find("--step=") != 0)
                throw std::runtime_error("WRONG ARGUMENTS");
            steps = convert<int>(argv[6]);
        }

        fast(argv[1], argv[2], argv[3], steps);
    }
    else if(convert<std::string>(argv[argc - 1]) == "--mode=tournament" or
             convert<std::string>(argv[argc - 1]).find("--") != 0){
        std::set<std::string> names;
        for(int i = 1; i < argc and convert<std::string>(argv[argc - 1]).find("--"); i++){
            names.emplace(argv[i]);
        }
        tournament(names);
    }else throw std::runtime_error("WRONG ARGUMENTS2");

}

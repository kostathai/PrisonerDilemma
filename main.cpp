#include "mode.h"
#include <sstream>

template<typename T>
T convert_(char* arg){
    std::stringstream convert(arg);
    T n;
    convert >> n;
    return n;
}


/*
...................Реализованные варианты запуска программы.........................
 \PrisonerDilemma.exe tough-tit-for-tat random poor-trusting-fool all-defect
 \PrisonerDilemma.exe tough-tit-for-tat random poor-trusting-fool all-defect --mode=tournament
 \PrisonerDilemma.exe tough-tit-for-tat random poor-trusting-fool
 \PrisonerDilemma.exe tough-tit-for-tat random poor-trusting-fool --mode=detailed
 \PrisonerDilemma.exe tough-tit-for-tat random poor-trusting-fool --mode=fast
 \PrisonerDilemma.exe tough-tit-for-tat random poor-trusting-fool --mode=fast --step= 2000
...................................Стратегии..........................................
 poor-trusting-fool
 all-defect
 random
 soft-tit-for-tat
 tough-tit-for-tat
 .....................................................................................*/


//невероятно корявая обработка аргументов, нужно бы улучшить с помощью фабрики или map(?)
int main(int argc, char* argv[]) {

    if (argc == 4 or (argc >= 5 and convert_<std::string>(argv[4]) == "--mode=detailed")) {
        std::set<std::string> names;
        for(int i = 1; i < 4; i++){
            names.emplace(argv[i]);
        }
        detailed(names);
    }else if(convert_<std::string>(argv[4]) == "--mode=fast"){
        int steps = 1000;
        if(argc >=7) {
            std::string s = convert_<std::string>(argv[5]);
            if (s.find("--step=") != 0)
                throw std::runtime_error("WRONG ARGUMENTS1");
            steps = convert_<int>(argv[6]);
        }
        std::set<std::string> names;
        for(int i = 1; i < 4; i++)
            names.emplace(argv[i]);
        fast(names, steps);
    }
    else if(convert_<std::string>(argv[argc - 1]) == "--mode=tournament" or
            convert_<std::string>(argv[argc - 1]).find("--")){
        std::set<std::string> names;
        for(int i = 1; i < argc and convert_<std::string>(argv[i]).find("--"); i++){
            names.emplace(argv[i]);
        }
        tournament(names);
    }else throw std::runtime_error("WRONG ARGUMENTS2");

}
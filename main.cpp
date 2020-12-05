#include "mode.h"

template<typename T>
T convert(char* arg){
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
/*
    std::map<std::string, void(*)(std::set<std::string>)> mode;
    mode["--mode=detailed"]= reinterpret_cast<void (*)(std::set<std::basic_string<char>, std::less<std::basic_string<char>>, std::allocator<std::basic_string<char>>>)>(detailed);


    if (argc < 4) return -1;
    std::set<std::string> names;

    if (argc < 4){
        for(int i = 1; i < 4; i++){
            names.emplace(argv[i]);
        }
        mode[argv[4]](names);
    }*/

    if (argc == 4 or (argc >= 5 and convert<std::string>(argv[4]) == "--mode=detailed")) {
        std::set<std::string> names;
        for(int i = 1; i < 4; i++){
            names.emplace(argv[i]);
        }
        detailed(names);
    }else if(convert<std::string>(argv[4]) == "--mode=fast"){
        int steps = 1000;
        if(argc >=7) {
            std::string s = convert<std::string>(argv[5]);
            if (s.find("--step=") != 0)
                throw std::runtime_error("WRONG ARGUMENTS1");
            steps = convert<int>(argv[6]);
        }
        std::set<std::string> names;
        for(int i = 1; i < 4; i++)
            names.emplace(argv[i]);
        fast(names, steps);
    }
    else if(convert<std::string>(argv[argc - 1]) == "--mode=tournament" or
             convert<std::string>(argv[argc - 1]).find("--")){
        std::set<std::string> names;
        for(int i = 1; i < argc and convert<std::string>(argv[i]).find("--"); i++){
            names.emplace(argv[i]);
        }
        tournament(names);
    }else throw std::runtime_error("WRONG ARGUMENTS2");

}
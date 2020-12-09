#include "detailed_mode.h"
//#include "fast_mode.h"
//#include "tournament_mode.h"
#include <sstream>
#include "table.h"
#include "factory.h"


typedef  std::map<std::vector<char>, std::vector<int>> MATRIX_;
template<typename T>
T convert_(char* arg){
    std::stringstream convert(arg);
    T n;
    convert >> n;
    return n;
}

struct Mode{
    std::string mode = "detailed";
    int step = 1000;
    std::string matrix_dir;
    MATRIX_ matrix;
};

int main(int argc, char* argv[]) {
    if (argc < 4)
        return -1;
    std::set<std::string> names;
    Mode m;
    for(int i = 1 ; i < argc; ++i){
        auto arg = convert_<std::string>(argv[i]);
        if(arg.find("--") != 0) {
            names.insert(arg);
            if (i == 4)
                m.mode = "tournament";
        }
        else{
            auto pos = arg.find('=');
            if (pos != std::string::npos) {
                std::string arg1 = arg.substr(2, pos-2);
                std::string arg2 = arg.substr(pos + 1);
                if (arg1 == "mode")
                    m.mode = arg2;
                else if (arg1 == "step")
                    m.step = std::stoi(arg2);
                else if (arg1 == "configs"){
                    //do something
                }
                else if(arg1 == "matrix"){
                    m.matrix_dir = arg2;
                }
                else throw std::runtime_error("WRONG ARGUMENTS: " + arg);
            }
            else throw std::runtime_error("WRONG ARGUMENTS: " + arg);
        }
    }
    m.matrix = CreateMatrix(m.matrix_dir);

    std::shared_ptr<PlayMode> game(Factory<PlayMode, std::string,
                                           PlayMode *(*) ()>::getInstance()->makeObject(m.mode));
    game->play(m.matrix, names, m.step);

}
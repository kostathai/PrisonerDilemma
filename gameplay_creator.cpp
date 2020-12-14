#include <sstream>
#include "gameplay_creator.h"
#include <map>
#include <set>
#include "table.h"
#include "factory.h"
#include "mode.h"
#include <memory>

template<typename T>
T convert_(char *arg) {
    std::stringstream convert(arg);
    T n;
    convert >> n;
    return n;
}

Mode creator(int argc, char *argv[]){
    if (argc < 4)
        throw std::runtime_error("NOT ENOUGH ARGUMENTS");
    Mode m;
    for (int i = 1; i < argc; ++i) {
        auto arg = convert_<std::string>(argv[i]);
        if (arg.find("--") != 0) {
            m.names.insert(arg);
            if (m.names.size() == 4)
                m.mode = "tournament";
        } else {
            if (m.names.size() < 3)
                throw std::runtime_error("INVALID NUMBER OF STRATEGY NAMES");
            auto pos = arg.find('=');
            if (pos != std::string::npos) {
                std::string arg1 = arg.substr(2, pos - 2);
                std::string arg2 = arg.substr(pos + 1);
                if (arg1 == "mode")
                    m.mode = arg2;
                else if (arg1 == "step")
                    m.step = std::stoi(arg2);
                else if (arg1 == "configs") {
                    m.configs_dir = arg2;
                } else if (arg1 == "matrix") {
                    m.matrix_dir = arg2;
                } else
                    throw std::runtime_error("WRONG ARGUMENTS: " + arg);
            } else
                throw std::runtime_error("WRONG ARGUMENTS: " + arg);
        }
    }
    if (m.names.size() < 3)
        throw std::runtime_error("INVALID NUMBER OF STRATEGY NAMES");
    if (m.mode == "detailed" and m.names.size() > 3)
        throw std::runtime_error("DETAILED MOD IS POSSIBLE ONLY FOR THREE PLAYERS");

    m.matrix = CreateMatrix(m.matrix_dir);
    std::shared_ptr<PlayMode> game(Factory<PlayMode, std::string,
            PlayMode *(*) ()>::getInstance()
                                           ->makeObject(m.mode));
    m.game = game;
    return m;
}
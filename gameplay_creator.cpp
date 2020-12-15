#include <sstream>
#include "gameplay_creator.h"
#include <map>
#include "factory.h"
#include <memory>

template<typename T>
T convert_(char *arg) {
    std::stringstream convert(arg);
    T n;
    convert >> n;
    return n;
}

std::unique_ptr<PlayMode> Mode::creator(){
    std::unique_ptr<PlayMode> game(Factory<PlayMode, std::string,
            PlayMode *(*) ()>::getInstance()
                                           ->makeObject(mode));
    game->InitialGame(matrix_dir, step,  names, configs_dir);
    return game;
}
void Mode::treatment_arg(int argc, char *argv[]) {
    if (argc < 4) {
        throw std::runtime_error("NOT ENOUGH ARGUMENTS");
    }
    for (int i = 1; i < argc; ++i) {
        auto arg = convert_<std::string>(argv[i]);
        if (arg.find("--") != 0) {
            names.insert(arg);
            if (names.size() == 4) {
                mode = "tournament";
            }
        } else {
            if (names.size() < 3) {
                throw std::runtime_error("INVALID NUMBER OF STRATEGY NAMES");
            }
            auto pos = arg.find('=');
            if (pos != std::string::npos) {
                std::string arg1 = arg.substr(2, pos - 2);
                std::string arg2 = arg.substr(pos + 1);
                if (arg1 == "mode") {
                    mode = arg2;
                } else if (arg1 == "step") {
                    step = std::stoi(arg2);
                } else if (arg1 == "configs") {
                    configs_dir = arg2;
                } else if (arg1 == "matrix") {
                    matrix_dir = arg2;
                } else {
                    throw std::runtime_error("WRONG ARGUMENTS: " + arg);
                }
            } else {
                throw std::runtime_error("WRONG ARGUMENTS: " + arg);
            }
        }
    }
    if (names.size() < 3) {
        throw std::runtime_error("INVALID NUMBER OF STRATEGY NAMES");
    }
    if (mode == "detailed" and names.size() > 3) {
        throw std::runtime_error("DETAILED MOD IS POSSIBLE ONLY FOR THREE PLAYERS");
    }
}
Mode::Mode(int argc, char **argv) {
    treatment_arg(argc, argv);
}

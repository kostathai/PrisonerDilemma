#include <map>
#include <set>
#include <vector>
#include "mode.h"
#include <memory>
typedef std::map<std::vector<char>, std::vector<int>> MATRIX_;
template<typename T>
T convert_(char *arg);

struct Mode {
    std::string mode = "detailed";
    int step = 1000;
    std::string matrix_dir;
    std::string configs_dir;
    MATRIX_ matrix;
    std::set<std::string> names;
    std::shared_ptr<PlayMode> game;
};

Mode creator(int argc, char *argv[]);
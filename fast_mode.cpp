#include "fast_mode.h"
#include "mode.h"
#include <iomanip>

void fast(const MATRIX_& T,std::set<std::string> &names, int N) {
    std::vector<StrategyPtr> str = Initial(names);
    std::vector<std::vector<char>> history;
    history.push_back({'C', 'C', 'C'});
    for (int i = 0; i < N; ++i)
        OneGame(T, str, history);
    PrintGameRes(str);
}


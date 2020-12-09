#include "fast_mode.h"
#include "factory.h"

namespace {
    bool gen() {
        Factory<PlayMode, std::string, PlayMode *(*) ()>::getInstance()->addCreator("fast", createFastMode);
        return true;
    }
    static bool d = gen();
}

PlayMode *createFastMode() {
    return new Fast;
}

void Fast::play(MATRIX_ &M, std::set<std::string> &names, int N) {
    T = M;
    Initial(names);
    for (int i = 0; i < N; ++i)
        OneGame();
    PrintRes();
}

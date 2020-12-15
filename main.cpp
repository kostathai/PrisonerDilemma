#include "gameplay_creator.h"




int main(int argc, char *argv[]) {
    Mode m(argc, argv);
    m.creator()->play();
}

#include <conio.h>
#include <vector>
struct Gamer {
    bool Test = false;
    std::vector<char> Button;
    bool Exit(const int &count){
        if (Test) {
            return (Button[count - 1] == 'q');
        }
        if (count == 0)
            return false;
        int c = getch();
        if (c == 'q')
            return true;
        return false;
    }
};
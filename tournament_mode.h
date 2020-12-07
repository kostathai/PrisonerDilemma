#include <set>
#include <string>
#include <map>
#include <vector>

typedef std::map<std::vector<char>, std::vector<int>> MATRIX_;

void tournament(const MATRIX_ &T, std::set<std::string> &names, int N);
void tour(const MATRIX_ &T, std::set<std::string> &names, std::map<std::string, int> &score, int N);
#pragma once
#include <map>
#include <vector>

std::map<std::vector<char>, std::vector<int>> T {
        {{'D', 'D', 'D'}, {1, 1, 1}},
        {{'D', 'D', 'C'}, {5, 5, 0}},
        {{'D', 'C', 'D'}, {5, 0, 5}},
        {{'C', 'D', 'D'}, {0, 5, 5}},
        {{'D', 'C', 'C'}, {9, 3, 3}},
        {{'C', 'D', 'C'}, {3, 9, 3}},
        {{'C', 'C', 'D'}, {3, 3, 9}},
        {{'C', 'C', 'C'}, {7, 7, 7}}
};
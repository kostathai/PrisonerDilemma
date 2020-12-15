#pragma once
#include <fstream>
#include <map>
#include <vector>

typedef std::map<std::vector<char>, std::vector<int>> MATRIX_;

static MATRIX_ CreateMatrix(const std::string &filename) {
    MATRIX_ T;
    if (filename.empty()) {
        T[{'D', 'D', 'D'}] = {1, 1, 1};
        T[{'D', 'D', 'C'}] = {5, 5, 0};
        T[{'D', 'C', 'D'}] = {5, 0, 5};
        T[{'C', 'D', 'D'}] = {0, 5, 5};
        T[{'D', 'C', 'C'}] = {9, 3, 3};
        T[{'C', 'D', 'C'}] = {3, 9, 3};
        T[{'C', 'C', 'D'}] = {3, 3, 9};
        T[{'C', 'C', 'C'}] = {7, 7, 7};
        return T;
    }
    std::ifstream in(filename);
    if (in.is_open()) {
        int a, b, c;
        in >> a >> b >> c;
        T[{'D', 'D', 'D'}] = {a, b, c};
        in >> a >> b >> c;
        T[{'D', 'D', 'C'}] = {a, b, c};
        in >> a >> b >> c;
        T[{'D', 'C', 'D'}] = {a, b, c};
        in >> a >> b >> c;
        T[{'C', 'D', 'D'}] = {a, b, c};
        in >> a >> b >> c;
        T[{'D', 'C', 'C'}] = {a, b, c};
        in >> a >> b >> c;
        T[{'C', 'D', 'C'}] = {a, b, c};
        in >> a >> b >> c;
        T[{'C', 'C', 'D'}] = {a, b, c};
        in >> a >> b >> c;
        T[{'C', 'C', 'C'}] = {a, b, c};
    } else
        throw std::runtime_error("file with matrix not found :(");
    return T;
}

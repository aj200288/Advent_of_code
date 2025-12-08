#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <vector>
#include <cmath>

struct Box {
    long long x, y, z; // ne rabiš na 0 ker itak vedno eksplicitno inicializiraš
};

struct Edge {
    size_t u, v;
    long long distance;

    bool operator<(const Edge &other) const;
};


long long distance(const Box &box1, const Box &box2);
int is_present(size_t p, const std::vector<std::vector<size_t>> &groups);

#endif // FUNCTIONS_H

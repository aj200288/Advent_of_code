#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <vector>

struct Point
{
    long long x, y;
};

struct Edge
{
    Point u, v;

    bool is_vertical();
};

struct Rectangle
{
    std::vector<Edge> rec;
};



bool intersect_edge(Point point, Edge edge);




#endif // FUNCTIONS_H

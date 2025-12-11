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
    Edge a, b, c, d;
};



bool intersect_edge(Point point, Edge edge);
bool intersect_two_edges(Edge edge1, Edge edge2);
bool on_edge(Point point, Edge edge);



#endif // FUNCTIONS_H

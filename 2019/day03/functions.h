#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <vector>


struct Point {
    int x, y;
};

struct Edge {
    Point start, end;

    bool is_vertical() const { return start.x == end.x; }
    bool is_horizontal() const { return start.y == end.y; }
};


Edge make_edge(const std::string& instruction, const Point& prev_point);
std::vector<Point> find_intersections(const std::vector<std::vector<Edge>>& all_wires);


#endif // FUNCTIONS_H

#include <string>
#include <iostream>

#include "functions.h"


Edge make_edge(const std::string& instruction, const Point& prev_point) {
    char direction = instruction[0];
    int distance = std::stoi(instruction.substr(1));
    Point new_point = prev_point;
    
    switch (direction) {
        case 'L': new_point.x -= distance; break;
        case 'R': new_point.x += distance; break;
        case 'D': new_point.y -= distance; break;
        case 'U': new_point.y += distance; break;
        default: throw std::invalid_argument("Invalid direction");
    }

    return Edge{.start = prev_point, .end = new_point};
}


std::vector<Point> find_intersections(const std::vector<std::vector<Edge>>& all_wires) {
    std::vector<Point> intersections;
    
    for (const auto& edge1 : all_wires[0]) {
        for (const auto& edge2 : all_wires[1]) {
            if (edge1.is_vertical() == edge2.is_vertical()) continue; // parallel edges
            
            // v_edge vertical, h_edge horizontal
            const Edge& v_edge = edge1.is_vertical() ? edge1 : edge2;
            const Edge& h_edge = edge1.is_vertical() ? edge2 : edge1;
            
            int v_edge_x = v_edge.start.x;
            int v_edge_y1 = std::min(v_edge.start.y, v_edge.end.y);
            int v_edge_y2 = std::max(v_edge.start.y, v_edge.end.y);
            
            int h_edge_x1 = std::min(h_edge.start.x, h_edge.end.x);
            int h_edge_x2 = std::max(h_edge.start.x, h_edge.end.x);
            int h_edge_y = h_edge.start.y;
            
            // Check if vertical edge's x is between horizontal edge's x bounds
            // and if horizontal edge's y is between vertical edge's y bounds
            if (h_edge_x1 <= v_edge_x && v_edge_x <= h_edge_x2 && 
                v_edge_y1 <= h_edge_y && h_edge_y <= v_edge_y2) {
                Point intersection{v_edge_x, h_edge_y};
                if (intersection.x != 0 || intersection.y != 0) { // Skip origin
                    intersections.push_back(intersection);
                }
            }
        }
    }
    return intersections;
}

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include "functions.h"


int main() {
    std::vector<std::vector<Edge>> all_wires;
    
    std::ifstream file("input.txt");
    std::string line{};
    
    while (std::getline(file, line)) {
        std::vector<Edge> wire;
        std::stringstream ss(line);
        std::string insturction;

        Point currnet_point{0, 0};
        while (std::getline(ss, insturction, ',')) { // insturction je npr. L234
            Edge edge = make_edge(insturction, currnet_point);
            wire.push_back(edge);
            currnet_point = edge.end;
        }
        all_wires.push_back(wire);
    }
    file.close();


    std::vector<Point> intersections = find_intersections(all_wires);

    if (!intersections.empty()) {
        int min_distance = std::abs(intersections[0].x) + std::abs(intersections[0].y);
        for (const auto& p : intersections) {
            int distance = std::abs(p.x) + std::abs(p.y);
            if (distance < min_distance) {
                min_distance = distance;
            }
        }
        std::cout << "Closest intersection distance: " << min_distance << "\n";
    }



    


    return 0;
}

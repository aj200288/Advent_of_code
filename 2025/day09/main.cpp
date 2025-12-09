#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include "functions.h"


int main() {
    std::vector<Point> points;

    std::ifstream file("test.txt");
    std::string line{};
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        Point p;
        char comma;

        ss  >> p.x >> comma >> p.y;
        points.push_back(p);
    }
    
    // brute force probamo vse kombinacije // verjentno se da kej izboljšat
    long long area = 0;
    for (size_t i = 0; i < points.size() - 1; ++i) {
        for (size_t j = i+1; j < points.size(); ++j) {
            long long dx = std::abs(points[i].x - points[j].x) + 1; // + 1, ker 5-3 = 2, amapk so to 3 vrste
            long long dy = std::abs(points[i].y - points[j].y) + 1;

            if (area < dx*dy)
                area = dx*dy;
            
        }
    }
    std::cout << "Part one: " << area << std::endl;

    // point inside or outside polygon
    // determin ray and test it fore each side. how many intersections do you get????????
    // must also check if side of square iside polygon

    // preverimo če so vse točke znotraj poligona 
    // preverimo, da se nobena stranica ne seka


    std::vector<Edge> edges;
    for (size_t i = 0; i < points.size()-1; ++i) {
        Edge e;
        e.u = points[i];
        e.v = points[i+1];
        edges.push_back(e);
    }
    
    Edge e; // zadnj edge povezuje prvo in zadnjo točko
    e.u = points[points.size()-1];
    e.v = points[0];
    edges.push_back(e);


    // kot v prvem delu perverimo vse kobinacij dveh točk.
    // določimo še točki drugih dveh oglišč in perverimo, če ležita znotraj poligona
    // če ležita 
    for (size_t i = 0; i < points.size() - 1; ++i) {
        for (size_t j = i+1; j < points.size(); ++j) {
            int x1 = points[i].x;
            int x2 = points[j].x;
            int y1 = points[i].y;
            int y2 = points[j].y;
            if(x1 == x2 || y1 == y2) continue;

            // aggregat init??? poglej si
            Point p1{x1, y2};
            Point p2{x2, y1};

            int sump1 = 0;
            int sump2 = 0;
            //kolikokrat  točka seka
            for (auto e : edges) {
                if (e.is_vertical()) {
                    if (intersect_edge(p1, e)) ++sump1;
                    if (intersect_edge(p2, e)) ++sump2;
                }
            }

            // če točka leži izven je sum sodo sicer je liho
            if (sump1 % 2 != 0 && sump2 % 2 != 0) {
                std::cout << x1 << ", " << y1 << " | " << x2 << ", " << y2 << ": " << sump2 << " ";
                std::cout << (abs(x1-x2)+1)*(abs(y1-y2)+1) << std::endl;


            }

        }
    }


    // for (auto e : edges) {
    //     std::cout << e.v.x << " " << e.v.y << " " << e.u.x << " " << e.u.y << std::endl;
    // }


    return 0;
}

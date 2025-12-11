#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include "functions.h"


int main() {
    std::vector<Point> points;

    std::ifstream file("input.txt");
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
    long long max_area = 0;
    for (size_t i = 0; i < points.size() - 1; ++i) {
        for (size_t j = i+1; j < points.size(); ++j) {
            long long x1 = points[i].x;
            long long x2 = points[j].x;
            long long y1 = points[i].y;
            long long y2 = points[j].y;
            if(x1 == x2 || y1 == y2) continue;

            // drugi dve točki pravokotnika
            // aggregat init??? poglej si
            Point p1{x1, y1};
            Point p2{x2, y1};
            Point p3{x2, y2};
            Point p4{x1, y2};

            // Rectangle r{{p1, p2}, {p2, p3}, {p3, p4}, {p4, p1}};
            

            long sump2 = 0;
            long sump4 = 0;
            //kolikokrat  točka seka, če je ta v notranjosti
            for (auto e : edges) {
                if (e.is_vertical()) {
                    if (intersect_edge(p2, e)) ++sump2;
                    if (intersect_edge(p4, e)) ++sump4;
                }
            }

            // ali je točka na robu
            for (auto e : edges) {
                if (on_edge(p2, e)) sump2 = 1; // potem je točka not damo sump na 1
                if (on_edge(p4, e)) sump4 = 1;
            }



            // če točka leži izven je sum sodo sicer je liho
            if (sump2 % 2 != 0 && sump4 % 2 != 0) {
                // std::cout << x1 << ", " << y1 << " | " << x2 << ", " << y2 << ": " << sump2 << " ";
                // std::cout << (abs(x1-x2)+1)*(abs(y1-y2)+1) << std::endl;

                //točke so ok, prevermo še robove
                bool intersects = false;
                for (auto e : edges) {
                    if (intersect_two_edges({p1, p2}, e) ||
                        intersect_two_edges({p2, p3}, e) ||
                        intersect_two_edges({p3, p4}, e) ||
                        intersect_two_edges({p4, p1}, e)) {
                        intersects = true;
                        break;
                    }
                }
                
                if (intersects) {
                    // std::cout << "intersect" << std::endl;
                } else {
                    // std::cout << "not intersect" << std::endl;
                    long long current_area = (abs(x1-x2)+1)*(abs(y1-y2)+1);
                    if (current_area > max_area) {
                        max_area = current_area;
                        // std::cout << x1 << ", " << y1 << " | " << x2 << ", " << y2 << std::endl;

                    }
                }



            }

        }
    }

    std::cout << "Part two: " << max_area << std::endl;


    // for (auto e : edges) {
    //     std::cout << e.v.x << " " << e.v.y << " " << e.u.x << " " << e.u.y << std::endl;
    // }


    return 0;
}




// 7,1
// 11,1
// 11,5
// 2,5
// 2,3
// 7,3
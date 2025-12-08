#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>

#include "functions.h"


int main() {
    std::vector<std::vector<long long>> points;
    
    std::ifstream file("input.txt");
    std::string line;
    
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        long x, y, z;
        char comma;
        
        ss >> x >> comma >> y >> comma >> z;
        
        points.push_back({x, y, z});
    }
    
    // stored in order all distances
    std::multimap<long long, std::pair<size_t, size_t>> distances; 
    // razadalje med vsakima dvema
    for (size_t i = 0; i < points.size() - 1; ++i) {
        for (size_t j = i + 1; j < points.size(); ++j) {
            long long dist = distance(points[i], points[j]);
            distances.insert({dist, std::make_pair(i, j)}); // insert instead of []
        }
    }

    // DELAMO Z INDEKSI
    // groups of conected points
    std::vector<std::vector<size_t>> groups;
    size_t count = 0;
    for (auto it = distances.begin(); it != distances.end() && count < 1000; ++it, ++count) {
        size_t p1 = it->second.first; //indeks prve točke v paru
        size_t p2 = it->second.second; // indeks druge točke v paru

        // index grupe v kateri se najhaja indeks točke
        int indx1 = is_present(p1, groups);
        int indx2 = is_present(p2, groups);

        if (indx1 == -1 && indx2 == -1) {
            groups.push_back({p1, p2}); // nova grupa
        }
        else if (indx1 != -1 && indx2 == -1) {
            groups[indx1].push_back(p2); //gupi ena dodamo index druge točke
        }
        else if (indx1 == -1 && indx2 != -1) {
            groups[indx2].push_back(p1); // grupi 2 dodamo index prve točke
        }
        else if (indx1 != -1 && indx2 != -1) {
            if (indx1 == indx2) {
                continue; // Both already in same group
            }
            else {
                //če je vsak index v drugi grupi združimo grupi
                groups[indx1].insert(groups[indx1].end(), groups[indx2].begin(), groups[indx2].end());
                groups.erase(groups.begin() + indx2);
            }
        }

        
        // std::cout << p1 << " " << p2 << std::endl;

    }

    long long sum = 1;
    std::vector<size_t> sizes;
    for (auto v : groups) {
        sizes.push_back(v.size());
    }
    std::sort(sizes.rbegin(), sizes.rend());

    
    for (size_t i = 0; i < 3; ++i) {
        sum *= sizes[i];
    }

    std::cout << "Part one: " << sum << std::endl;
    
    return 0;
}



// int main() {
//     std::vector<std::vector<long long>> points;
    
//     std::ifstream file("input.txt");
//     std::string line;
    
//     while (std::getline(file, line)) {
//         std::stringstream ss(line);
//         long x, y, z;
//         char comma;
        
//         ss >> x >> comma >> y >> comma >> z;
        
//         points.push_back({x, y, z});
//     }
    
//     // stored in order all distances
//     std::multimap<long long, std::pair<size_t, size_t>> distances; 
//     // razadalje med vsakima dvema
//     for (size_t i = 0; i < points.size() - 1; ++i) {
//         for (size_t j = i + 1; j < points.size(); ++j) {
//             long long dist = distance(points[i], points[j]);
//             distances.insert({dist, std::make_pair(i, j)}); // insert instead of []
//         }
//     }

//     // DELAMO Z INDEKSI
//     // groups of conected points
//     std::vector<std::vector<size_t>> groups;
//     for (auto it = distances.begin(); it != distances.end(); ++it) {
//         size_t p1 = it->second.first; //indeks prve točke v paru
//         size_t p2 = it->second.second; // indeks druge točke v paru

//         // index grupe v kateri se najhaja indeks točke
//         int indx1 = is_present(p1, groups);
//         int indx2 = is_present(p2, groups);

//         if (indx1 == -1 && indx2 == -1) {
//             groups.push_back({p1, p2}); // nova grupa
//         }
//         else if (indx1 != -1 && indx2 == -1) {
//             groups[indx1].push_back(p2); //gupi ena dodamo index druge točke
//         }
//         else if (indx1 == -1 && indx2 != -1) {
//             groups[indx2].push_back(p1); // grupi 2 dodamo index prve točke
//         }
//         else if (indx1 != -1 && indx2 != -1) {
//             if (indx1 == indx2) {
//                 continue; // Both already in same group
//             }
//             else {
//                 //če je vsak index v drugi grupi združimo grupi
//                 groups[indx1].insert(groups[indx1].end(), groups[indx2].begin(), groups[indx2].end());
//                 groups.erase(groups.begin() + indx2);
//             }
//         }

//         std::cout << groups[0].size() << std::endl;
//         if (groups[0].size() == 1000) {
//             std::cout << points[p1][0] * points[p2][0] << std::endl;
//         }

        
//         // std::cout << p1 << " " << p2 << std::endl;
        
//     }

    
//     return 0;
// }

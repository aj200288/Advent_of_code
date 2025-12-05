#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include "functions.h"


int main() {
    // par ker shranjujemo pare in jih vse obdelamo (map ima hiter lookup)
    std::vector<std::pair<const size_t, const size_t>> ids; //vektor parov (podobnon kot map - map ma dejanosko notr shranjen pair<const key, value>)

    std::ifstream file("input.txt");
    std::string line{};
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string token;

        while (std::getline(ss, token, ',')) {
            size_t pos = token.find('-');
            if (pos != std::string::npos) {
                size_t first = std::stoll(token.substr(0, pos));
                size_t second = std::stoll(token.substr(pos + 1));
                ids.emplace_back(first, second);
            }
        }
    }   


    size_t sum1 = 0;
    size_t sum2 = 0;
    for (const auto &p : ids) {
        sum1 += invalid_ids_part1(p.first, p.second);
        sum2 += invalid_ids_part2(p.first, p.second);
    }

    std::cout << "Part one: " << sum1 << std::endl;
    std::cout << "Part two: " << sum2 << std::endl;
    
    
    return 0;
}

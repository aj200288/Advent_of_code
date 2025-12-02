#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include "functions.h"


int main() {
    std::vector<std::pair<long long, long long>> ids;

    std::ifstream file("input.txt");
    std::string line{};
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string token;

        while (std::getline(ss, token, ',')) {
            if (token.empty()) continue;

            size_t pos = token.find('-');
            if (pos != std::string::npos) {
                long long first = std::stoll(token.substr(0, pos));
                long long second = std::stoll(token.substr(pos + 1));
                ids.emplace_back(first, second);
            }
        }
    }   


    long long sum1 = 0;
    long long sum2 = 0;
    for (const auto &p : ids) {
        sum1 += invalid_ids_part1(p.first, p.second);
        sum2 += invalid_ids_part2(p.first, p.second);
    }

    std::cout << "Part one: " << sum1 << std::endl;
    std::cout << "Part two: " << sum2 << std::endl;
    
    
    return 0;
}

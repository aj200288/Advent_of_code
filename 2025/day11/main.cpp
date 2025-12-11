#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
#include <string>
#include <vector>
#include <sstream>

#include "functions.h"



int main() {
    std::unordered_map<std::string, std::vector<std::string>> connections;

    std::ifstream file("input.txt");
    std::string line{};
    while (std::getline(file, line)) {
        size_t colon_pos = line.find(':');
        std::string key = line.substr(0, colon_pos); // ključ
        std::string values_str = line.substr(colon_pos + 2);
        
        // povezave
        std::vector<std::string> values;
        std::stringstream ss(values_str);
        std::string value;
        while (ss >> value) {
            values.push_back(value);
        }
        connections[key] = values;
    }

    std::cout << "Part one: " << paths("you", connections) << std::endl;

    std::unordered_map<std::string, long long> memo;
    long long sf = paths2("svr", "fft", connections, memo);
    memo.clear();
    long long fd = paths2("fft", "dac", connections, memo);
    memo.clear();
    long long dou = paths2("dac", "out", connections, memo);
    memo.clear();

    long long sd = paths2("svr", "dac", connections, memo);
    memo.clear();
    long long df = paths2("dac", "fft", connections, memo);
    memo.clear();
    long long fo = paths2("fft", "out", connections, memo);

    long long sum = sf*fd*dou + sd*df*fo;

    std::cout << "Part two: " << sum << std::endl;
    
    
    
    return 0;
}

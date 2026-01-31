#include <fstream>
#include <iostream>
#include <string>

#include "functions.h"


int main() {
    long long sum1 = 0;
    long long sum2 = 0;

    std::ifstream file("input.txt");
    std::string line{};
    while (std::getline(file, line)) {
        int mass = std::stoi(line);
        sum1 += find_fuel_part1(mass);
        sum2 += find_fuel_part2(mass);
    }

    std::cout << "Part one: " << sum1 << std::endl;
    std::cout << "Part two: " << sum2 << std::endl;
    
    return 0;
}

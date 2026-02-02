#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#include "functions.h"


int main() {
    std::ifstream file("input.txt");
    std::string line{};
    std::vector<long long> numbers;
    
    if (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string token;
        
        while (std::getline(ss, token, ',')) {
            numbers.push_back(std::stoll(token));
        }
    }
    
    // naeest tega kopiranja bi lahko samo klicu fukcijo brez reference
    std::vector<long long> numbers_copy = numbers;
    numbers[1] = 12;
    numbers[2] = 2;

    std::cout << "Part one: " << intcode(numbers_copy) << std::endl;

    // optimiziraj: brake skoči iz samo ene zanke
    for (size_t i = 0; i < 100; ++i) {
        for (size_t j = 0; j < 100; ++j) {
            std::vector<long long> numbers_copy = numbers;
            numbers_copy[1] = i;
            numbers_copy[2] = j;
            if (intcode(numbers_copy) == 19690720) {
                std::cout << 100*i +j << std::endl;
                break;
            }
        }
    }

    return 0;
}


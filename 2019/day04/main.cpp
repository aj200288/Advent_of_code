#include <fstream>
#include <iostream>
#include <string>

#include "functions.h"


int main() {
    // std::ifstream file("input.txt");
    // std::string line{};
    // while (std::getline(file, line)) {

    // } 
    int sum1 = 0;
    int sum2 = 0;

    for (int i = 382345; i <= 843167; ++i) {
        if (is_valid1(i)) ++sum1;
        if (is_valid2(i)) ++sum2;
    }


    std::cout << "Part one: " << sum1 << std::endl;
    std::cout << "Part two: " << sum2 << std::endl;

    return 0;
}

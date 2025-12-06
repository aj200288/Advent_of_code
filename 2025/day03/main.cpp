#include <fstream>
#include <iostream>
#include <string>

#include "functions.h"


int main() {
    long long sum1 = 0;
    long long sum2 = 0;

    std::ifstream file("input.txt");
    // std::ifstream file("test.txt");
    std::string line{};
    while (std::getline(file, line)) {
        sum1 += max(line, 2);
        sum2 += max(line,  12);

    }
    
    std::cout << "Part one: " << sum1 << std::endl;
    std::cout << "Part two: " << sum2 << std::endl;



    
    return 0;
}

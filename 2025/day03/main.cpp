#include <fstream>
#include <iostream>
#include <string>

#include "functions.h"


int main() {
    int sum  = 0;
    long long sum2 = 0;

    std::ifstream file("input.txt");
    // std::ifstream file("test.txt");
    std::string line{};
    while (std::getline(file, line)) {
        sum += max(line);
        sum2 += max2(line);

    }
    
    std::cout << sum2 << std::endl;



    
    return 0;
}

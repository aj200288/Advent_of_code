#include <fstream>
#include <iostream>
#include <string>

#include "functions.h"


int main() {
    int num = 50;
    int sum1 = 0;
    int sum2 = 0; 

    std::string filename = "input.txt";

    std::ifstream file(filename);
    std::string line{};
    while (std::getline(file, line)) {
        int add = std::stoi(line.substr(1));

        if (line[0] == 'L') {
            if (num == 0)
                --sum2; // v primeru da začnemo z 0 štejemo isto vrednost dvakrat zato se tu enkrat odšteje

            for (int i = 0; i < add; ++i){
                --num;

                if (num < 0) {
                    num = 99;
                    ++sum2;
                }
            }

            if (num == 0)
                ++sum2;
        }
        else {
            for (int j = 0; j < add; ++j) {
                ++num;

                if (num > 99) {
                    num = 0;
                    ++sum2;
                }
            }
        }

        if (num == 0)
            ++sum1;
    }
    
    std::cout << "Part one: " << sum1 << std::endl;
    std::cout << "Part two: " << sum2 << std::endl;
    
    return 0;
}

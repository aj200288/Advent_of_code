#include <fstream>
#include <iostream>
#include <string>

#include "functions.h"


int main() {
    int num = 50;
    int sum = 0; 


    std::ifstream file("input.txt");
    std::string line{};
    while (std::getline(file, line)) {
        int add = std::stoi(line.substr(1));

        if (line[0] == 'L') {
            if (num == 0)
                --sum;

            for (int i = 0; i < add; ++i){
                --num;
               
                if (num < 0) {
                    num = 99;
                    ++sum;
                }
            }

            if (num == 0)
                ++sum;
        }
        else {
            for (int j = 0; j < add; ++j) {
                ++num;

                if (num > 99) {
                    num = 0;
                    ++sum;
                }
            }
        }

        std::cout << num << ": " << sum << std::endl;


    }
    
    std::cout << sum << std::endl;
    
    return 0;
}

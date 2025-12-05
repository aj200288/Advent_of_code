#include <fstream>
#include <iostream>
#include <string>

#include "functions.h"


int main() {
    int counter = 50;
    int sum1 = 0;
    int sum2 = 0; 

    std::string filename = "input.txt";

    std::ifstream file(filename);
    std::string line{};
    while (std::getline(file, line)) {
        int clicks = std::stoi(line.substr(1));

        if (line[0] == 'L') {
            if (counter == 0)
                --sum2; // v primeru da začnemo z 0 štejemo isto vrednost dvakrat (takoj gremo nazaj in jo tam spet prištejemo)

            // odštevamo in v primeru, da števec pade pod 0 ga nastavimo na 0.
            for (int i = 0; i < clicks; ++i){
                --counter;

                if (counter < 0) {
                    counter = 99;
                    ++sum2;
                }
            }

            if (counter == 0) // če končamo na 0
                ++sum2;
        }
        else {
            for (int j = 0; j < clicks; ++j) {
                ++counter;

                // če gre števec prek 99 ga nastavimo na 0
                if (counter > 99) {
                    counter = 0;
                    ++sum2;
                }
            }
        }

        if (counter == 0) // če po premikanju kazalca števec kaže na 0, prištejemo 1
            ++sum1;
    }
    
    std::cout << "Part one: " << sum1 << std::endl;
    std::cout << "Part two: " << sum2 << std::endl;
    
    return 0;
}

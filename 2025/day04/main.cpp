#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "functions.h"


int main() {
    std::vector<std::vector<char>> input;
    std::vector<std::vector<char>> input_copy;

    std::ifstream file("input.txt");
    std::string line{};
    while (std::getline(file, line)) {
        std::vector<char> v_line;
        for (auto c : line) {
            v_line.push_back(c);
        }
        input.push_back(v_line);
    }
    input_copy = input;

    int sum = 0;
    while (true) {
        input = input_copy;
    for (int l = 0; l < input.size(); ++l) {
        for (int c = 0; c < input[l].size(); ++c) { // charcter in line
            int neighbours = -1;
            if (input[l][c] != '@') continue;

            for (int i = -1; i <= 1; ++i) {
                for (int j = -1; j <= 1; ++j) {
                    try {
                        if (input.at(l + i).at(c + j) == '@')
                            ++neighbours;
                    }
                    catch(std::out_of_range &e) {
                        continue;
                    }

                }
            }
            
            if (neighbours < 4) {
                ++sum;
                input_copy[l][c] = '.';
            }
            // std::cout << sum << std::endl;


        }
        // std::cout << std::endl;
    }

    std::cout << "END: " << sum << std::endl;
}
    
    return 0;
}   



// gr
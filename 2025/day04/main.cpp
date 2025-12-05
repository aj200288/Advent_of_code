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
    bool first_iter = true;
    int sum = 0;
    int prev_sum = -1;
    
    while (sum != prev_sum) {
        prev_sum = sum;
        input = input_copy;
        
        for (size_t l = 0; l < input.size(); ++l) { // vrstice
            for (size_t c = 0; c < input[l].size(); ++c) { // znaki v vrstici
                int neighbours = -1; // ker bo štel tudi sebe
                if (input[l][c] != '@') continue;

                for (int i = -1; i <= 1; ++i) {
                    for (int j = -1; j <= 1; ++j) {
                        // ulovimo izjeme za robne znake
                        try {
                            if (input.at(l + i).at(c + j) == '@')
                                ++neighbours;
                        }
                        catch (std::out_of_range &e) {
                            continue;
                        }
                    }
                }
                
                if (neighbours < 4) {
                    ++sum;
                    input_copy[l][c] = '.';
                }
            }
        }

        if (first_iter) {
            std::cout << "Part one: " << sum << std::endl;
            first_iter = false;
        }
    }

    std::cout << "Part two: " << sum << std::endl;
    
    return 0;
}
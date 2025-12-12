#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#include "functions.h"


int main() {
    std::vector<Line> lines;

    std::ifstream file("input.txt");
    std::string line{};
    while (std::getline(file, line)) {
        size_t x_pos = line.find('x'); 
        if(x_pos == std::string::npos) continue;

        Line l;
        l.region_size = std::stoll(line.substr(0, x_pos)) * std::stoll(line.substr(x_pos+1, 2));

        size_t colon_pos = line.find(':');
        std::stringstream ss(line.substr(colon_pos + 1));
        int value;
        while (ss >> value) {
            l.presents.push_back(value);
        }

        lines.push_back(l);
    }


    //hardcode - vem, zelo slaba praksa, samo se mi ne da z input parsanjem hecat
    std::vector<std::vector<std::vector<bool>>> present_shapes_test {{{1, 1, 1}, {1, 1, 0}, {1, 1, 0}},
                                                                      {{1, 1, 1}, {1, 1, 0}, {0, 1, 1}},
                                                                      {{0, 1, 1}, {1, 1, 1}, {1, 1, 0}},
                                                                      {{1, 1, 0}, {1, 1, 1}, {1, 1, 0}},
                                                                      {{1, 1, 1}, {1, 0, 0}, {1, 1, 1}},
                                                                      {{1, 1, 1}, {0, 1, 0}, {1, 1, 1}}};
    std::vector<int> number_of_tiles_test {7, 7, 7, 7, 7, 7};

    std::vector<std::vector<std::vector<bool>>> present_shapes_input {{{1, 0, 1}, {1, 1, 1}, {1, 0, 1}},
                                                                      {{1, 1, 1}, {1, 1, 1}, {1, 0, 0}},
                                                                      {{1, 1, 1}, {0, 1, 1}, {1, 1, 0}},
                                                                      {{1, 1, 1}, {0, 1, 1}, {0, 0, 1}},
                                                                      {{1, 1, 1}, {0, 0, 1}, {1, 1, 1}},
                                                                      {{1, 1, 0}, {0, 1, 1}, {0, 0, 1}}};
    std::vector<int> number_of_tiles_input {7, 7, 7, 6, 7, 6};


    auto &number_of_tiles = number_of_tiles_input;

    long long can_fit = 0;
    long long cannot_fit = 0;
    long long maybe_fit = 0;

    // preverimo katere primere je treba sploh preverjati
    for (const auto &line : lines) {
        long long sum_3x3_tiles = 0;
        long long sum_actual_tiles = 0;
        
        for (size_t i = 0; i < line.presents.size(); ++i) {
            sum_3x3_tiles += line.presents[i] * 9;
            sum_actual_tiles += line.presents[i] * number_of_tiles[i];
        }

        // std::cout << sum_3x3_tiles << " " << sum_actual_tiles << std::endl;

        if (sum_3x3_tiles <= line.region_size)
            ++can_fit;
        else if(sum_actual_tiles > line.region_size)
            ++cannot_fit;
        else
            ++maybe_fit;
    }

    //heh maybe_fit je 0 :)
    std::cout << can_fit << " " << cannot_fit << " " << maybe_fit << std::endl;
    

    // for(const auto &l : lines) {
    //     std::cout << l.region_size << ": ";
    //     for (const auto &p : l.presents){
    //         std::cout << p << " ";
    //     }
    //     std::cout << std::endl;
    // }
    
    return 0;
}

// brute force? vsakega probaš postavit na vse pozicije  (backtracking)
// zna ful dolg trajat

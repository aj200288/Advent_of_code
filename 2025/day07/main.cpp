#include <fstream>
#include <iostream>
#include <string>
#include <vector>
// #include <list>
#include <set>
#include <map>

#include "functions.h"


int main() {
    long long sum = 0;
    std::vector<std::vector<size_t>> splitter_pos;
    std::set<size_t> beam_pos;

    std::map<size_t, int> beams;


    std::ifstream file("input.txt");
    std::string line{};
    
    
    while (std::getline(file, line)) {
        std::vector<size_t> row;
        for (size_t c = 0; c < line.size(); ++c) {
            if (line[c] == '^') 
                row.push_back(c);
            else if (line[c] == 'S') 
                beam_pos.insert(c);
        }
        if(!row.empty())
            splitter_pos.push_back(row);
    }


    for (auto l : splitter_pos) { //vektor znotraj vektorja
        std::set<size_t> new_beam_pos;

        for (auto b : beam_pos) { // za vsak beam
            bool hit = false;
            
            for (auto s : l) { // preveriš vse splitterje
                if (s == b) {
                    new_beam_pos.insert(b - 1);
                    new_beam_pos.insert(b + 1);
                    ++sum;
                    hit = true;
                    break; // beam lahko zadane samo en splitter
                }
            }
            
            if (!hit) {
                new_beam_pos.insert(b); // beam nadaljuje nespremenjen
            }
        }
        
        beam_pos = new_beam_pos;
    }


    for (auto l: splitter_pos) {
        
    }




    
    


    std::cout << sum << std::endl;
    
    return 0;
}

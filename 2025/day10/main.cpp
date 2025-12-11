#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <bitset>

#include "functions.h"


int main() {
    long long sum = 0;

    std::ifstream file("input.txt");
    std::string line{};    
    while (std::getline(file, line)) {
        size_t pos = 0;
        
        // lights
        std::string lights;
        size_t bracket_start = line.find('[');
        size_t bracket_end = line.find(']');
        lights = line.substr(bracket_start + 1, bracket_end - bracket_start - 1);
        pos = bracket_end + 1;

                // lights to binary (int)
        int lights_bin = 0;
        for (const auto &c : lights) {
            lights_bin <<= 1;
            if ( c == '#')
                lights_bin |= 1;
        }

        
        // Vsi gumbi
        // buttons vsebuje intigerje, ki so pretvorba vsakega gumba v toggle int
        std::vector<int> buttons;
        while ((pos = line.find('(', pos)) != std::string::npos) {
            size_t close_pos = line.find(')', pos);            
            std::string group_str = line.substr(pos, close_pos - pos + 1);

            std::vector<int> button = parse_group(group_str); // togle intigerji
            const size_t button_size = lights.length(); // stevilo lučk
            int bin_button = 0; //binarni zapis togglov
            for (const auto &i : button) {
                bin_button |= (1 << (button_size-i-1));
            }
            buttons.push_back(bin_button); // ad to vector of buttons
            // std::cout << std::bitset<32>(bin_button) << std::endl;
            pos = close_pos + 1;
        }
        
        // joltage
        std::vector<int> joltage;
        size_t brace_start = line.find('{');
        size_t brace_end = line.find('}');
        std::string brace_str = line.substr(brace_start, brace_end - brace_start + 1);
        joltage = parse_group(brace_str);
        

        //-----------------------
        // Logika

        sum += BFS(buttons, 0, lights_bin);

        // lights_bin je binarno število ki ga želimo dosčt,
        // v vektorju buttons so binaran števila, ki pretavljajao gubme
        // stanje = stanje ^ buttons[i]
        // if stanje == lights_bin
            //done


    }
    
    std::cout << sum << std::endl;
    
    
    return 0;
}

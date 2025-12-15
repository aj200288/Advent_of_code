#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <bitset>
#include <z3++.h>  // Z3 solver by microsoft - na redditu zvedu za tole

#include "functions.h"


int main() {
    long long sum1 = 0;
    long long sum2 = 0;

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
        // buttons_bin vsebuje intigerje, ki so pretvorba vsakega gumba v toggle int
        std::vector<int> buttons_bin; // binarni gumbi
        std::vector<std::vector<int>> buttons; // vektor gumbov
        while ((pos = line.find('(', pos)) != std::string::npos) {
            size_t close_pos = line.find(')', pos);            
            std::string group_str = line.substr(pos, close_pos - pos + 1);

            std::vector<int> button = parse_group(group_str); // togle intigerji
            buttons.push_back(button);

            const size_t button_size = lights.length(); // stevilo lučk
            int bin_button = 0; //binarni zapis togglov
            for (const auto &i : button) {
                bin_button |= (1 << (button_size-i-1));
            }
            buttons_bin.push_back(bin_button); // ad to vector of buttons_bin
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
        // Logika part one

        sum1 += BFS(buttons_bin, 0, lights_bin);

        // lights_bin je binarno število ki ga želimo dosčt,
        // v vektorju buttons_bin so binaran števila, ki pretavljajao gubme
        // stanje = stanje ^ buttons_bin[i]
        // if stanje == lights_bin
            //done


        // part two

        sum2 += part2(buttons, joltage);














        


    }
    
    std::cout << "Part one: " << sum1 << std::endl;
    std::cout << "Part two: " << sum2 << std::endl;




    // // Z3 Example Usage (uncomment to use):
    // z3::context ctx;
    // z3::expr x = ctx.int_const("x");
    // z3::expr y = ctx.int_const("y");
    
    // z3::solver s(ctx);
    // s.add(x + y == 10);
    // s.add(x - y == 2);
    
    // if (s.check() == z3::sat) {
    //     z3::model m = s.get_model();
    //     std::cout << "Z3 solution: x = " << m.eval(x) << ", y = " << m.eval(y) << std::endl;
    // }
    
    return 0;
}

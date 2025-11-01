#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>


//prever kako je s tem const int v tej funckiji
std::vector<int> split(const std::string& str) {
    std::vector<int> out;
    std::istringstream iss(str);
    std::string word;
    
    while (iss >> word) {
        out.push_back(stoi(word));
    }
    
    return out;
}


void part_one() {
    std::ifstream file("input.txt");
    if (!file.is_open()) {
        std::cerr << "Could not open file\n";
    }

    int sum = 0;

    std::string line;
    while (getline(file, line)) {
        auto pos = line.find(':');
        std::string card_num = line.substr(pos - 3, 3); // not the best practice sam v tem primeru deluje
        int card_number = stoi(card_num);

        auto pos_line = line.find('|');

        std::vector<int> winning_num = split(line.substr(pos + 2, pos_line - pos - 2));
        std::vector<int> my_nums = split(line.substr(pos_line + 2, line.length() - pos_line - 2));
        
        int i = 0;
        int game_score = 0;
        for (const auto &w : winning_num) {
            for (const auto &my : my_nums) {
                if (w == my) {
                    game_score = pow(2, i++);
                }
            }
        }
        sum += game_score;
    }

    std::cout << "Part one: " << sum << std::endl;
}



int main() {

    part_one();

    return 0;
}
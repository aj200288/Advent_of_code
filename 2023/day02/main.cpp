#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <unordered_map> //faster than normal (ordered) map


std::unordered_map<std::string, const int> color_values = {
    {"red", 12},
    {"green", 13},
    {"blue", 14}
};

int main() {

    std::ifstream file("input.txt");
    if (!file.is_open()) {
        std::cerr << "Could not open file\n";
        return 1;
    }

    int sum = 0;
    std::string line;
    while (getline(file, line)) {

        auto pos = line.find(':');
        std::string game_str = line.substr(5, pos - 5); // 5 is postition of strarting game number
        int game_number = std::stoi(game_str);
        sum += game_number; // add current game_number (will be substracted later if any number is higher than specified)

        std::string str_num = "";
        for (auto i = pos + 2; i < line.size(); ++i) {
            char c = line[i];

            if (c == ' ') continue;

            if (isdigit(c)) {
                str_num += c;
                continue;
            }

            int current_number = std::stoi(str_num);
            str_num = ""; // Clear the string for next number

            std::string current_color;
            switch(c){
                case 'r':
                    i += 4;
                    current_color = "red";
                    break;

                case 'g':
                    i += 6;
                    current_color = "green";
                    break;

                case 'b':
                    i += 5;
                    current_color = "blue";
                    break;
            }

            if (current_number > color_values[current_color]) {
                sum -= game_number; // substract current game
                break; // go to new line
            };
        }
    }

    std::cout << sum << std::endl;

    return 0;
}
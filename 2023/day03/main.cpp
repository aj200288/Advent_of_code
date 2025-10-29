// večino sam, vseen pa potem ideja kle: https://github.com/coralkashri/AOC/blob/master/src/2023/day_3.hpp


#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <array>
#include <string>


int get_numbers (const std::vector<std::vector<char>>& data, int i, int& j) {
    //move to the left to get to the start of the number
    // &j so that number is not counted multiple times if more of its digits touch special symbol
    while (isdigit(data[i][j])){
        --j;
    }

    // str to int se da tud bl pregledno narest glej prejšnji dan, bom pustu kle, da vem tud za to možnost

    //store number is stack
    std::stack<char> num_parsed;
    while (isdigit(data[i][++j])) {
        num_parsed.push(data[i][j]);
    }

    //convert to intiger number from chars
    int num = 0;
    int multi = 1;
    while (!num_parsed.empty()) {
        num += (num_parsed.top() - '0') * multi;
        num_parsed.pop();
        multi *= 10;
    }

    return num;
}


int check_for_numbers(const std::vector<std::vector<char>>& data, int i, int j) {
    //check neighbouring cells if digits
    int sum = 0;
    for (int ni = i - 1; ni <= i + 1; ++ni) {
        for (int nj = j - 1; nj <= j + 1; ++nj) {
            if (isdigit(data[ni][nj])) {   
                sum += get_numbers(data, ni, nj);
            }
        }
    }
    return sum;
}

int check_if_two_numbers(const std::vector<std::vector<char>>& data, int i, int j) {
    //check neighbouring cells if digits
    std::array<int, 2> neighbours = {0, 0};
    int current_neighbour = 0;
    for (int ni = i - 1; ni <= i + 1; ++ni) {
        for (int nj = j - 1; nj <= j + 1; ++nj) {
            if (isdigit(data[ni][nj])) {   
                if(current_neighbour == 2) return 0;
                neighbours[current_neighbour++] =  get_numbers(data, ni, nj);
            }
        }
    }
    return current_neighbour == 2 ? neighbours[0] * neighbours[1] : 0;
}


void part_one(std::vector<std::vector<char>>& data) {
    // loop through file again to finc special symbols and read numbers
    int sum = 0;
    for (int i = 0; i < data.size(); ++i) {
        for (int j = 0; j < data[i].size(); ++j) {
            if(!isdigit(data[i][j]) && data[i][j] != '.') {
                sum += check_for_numbers(data, i, j);
            }
        }
    }
    std::cout << "Part one: " << sum << std::endl;
}


void part_two(std::vector<std::vector<char>>& data) {
    int sum = 0;
    for (int i = 0; i < data.size(); ++i) {
        for (int j = 0; j < data[i].size(); ++j) {
            if(data[i][j] == '*') {
                sum += check_if_two_numbers(data, i, j);
            }
        }
    }
    std::cout << "Part two: " << sum << std::endl;
}


int main() {
    // open a file
    std::ifstream file("input.txt");
    if (!file.is_open()) {
        std::cerr << "Could not open file.\n";
        return 1;
    }

    // read contents of a file and store them in 2d vector
    std::string line;
    std::vector<std::vector<char>> data;
    while (getline(file, line)) {
        std::vector<char> parse_line;
        for (const char &c : line) {
            parse_line.push_back(c);
        }
        data.push_back(parse_line);
    }


    part_one(data);
    part_two(data);


    return 0;
}





    // Bolj eleganto sam rabm i pa j
    // for (const auto &row : data) {
    //     for (const auto &ch : row) {
    //         if(!isdigit(ch) && ch != '.') {
    //         }
    //     }
    // }


/*
    - V prvi in zadnji vrsti ni special sibolov - ne rabiš pazit index out of range - lahko bi za vajo naredu
    - mislm da je vsaka številka samo enkrat vključena
    - številke niso daljše od 3-eh števk
*/
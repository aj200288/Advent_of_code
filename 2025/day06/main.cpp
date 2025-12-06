#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

#include "functions.h"


int main() {
    std::vector<std::string> rows;
    std::vector<char> operators;

    std::ifstream file("input.txt");
    std::string line;

    while (std::getline(file, line)) {
        if (line[0] == '+' || line[0] == '*') {
            for (char c : line) {
                if (c == '*' || c == '+')
                    operators.push_back(c);
            }
        }
        else
            rows.push_back(line);
    }

    // Part 1: Shranimo številke ločene s presledki
    // Vsak vektor vsebuje celotno vrstico 
    std::vector<std::vector<int>> numbers_part1;
    for (const auto &row : rows) {
        std::vector<int> row_nums;
        std::stringstream ss(row);
        int num;
        while (ss >> num) {
            row_nums.push_back(num);
        }
        numbers_part1.push_back(row_nums);
    }

    long long sum1 = 0;
    for (size_t i = 0; i < operators.size(); ++i) {
        long long col_sum = (operators[i] == '+') ? 0 : 1;

        for (const auto &row : numbers_part1) {
            if (operators[i] == '+')
                col_sum += row[i];
            else
                col_sum *= row[i];
        }
        sum1 += col_sum;
    }

    // Part 2: Shranimo za vsak stolpec posebaj
    // Vsak vektor vsebuje šteilke enega stolpca
    std::vector<std::vector<int>> numbers_part2;
    std::vector<int> col_numbers;

    for (size_t c = 0; c < rows[0].length(); ++c) {
        std::string col;
        for (const auto &row : rows) {
            col += row[c];
        }

        try {
            col_numbers.push_back(std::stoi(col));
        }
        catch (const std::invalid_argument& e) {
            numbers_part2.push_back(col_numbers);
            col_numbers.clear();
        }
    }
    numbers_part2.push_back(col_numbers);

    long long sum2 = 0;
    for (size_t i = 0; i < operators.size(); ++i) {
        long long col_sum = (operators[i] == '+') ? 0 : 1;

        for (const auto &num : numbers_part2[i]) {
            if (operators[i] == '+') 
                col_sum += num;
            else
                col_sum *= num;
        }
        sum2 += col_sum;
    }

    std::cout << "Part 1: " << sum1 << std::endl;
    std::cout << "Part 2: " << sum2 << std::endl;

    return 0;
}
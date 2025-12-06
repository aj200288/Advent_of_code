#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <vector>

#include "functions.h"


int main() {
    std::multimap<size_t, size_t> ranges; //multy map ker ti lahko povozi prvo vrednost
    std::vector<size_t> ids;
    bool first_data = true;

    std::ifstream file("input.txt");
    std::string line{};
    while (std::getline(file, line)) {
        if (line.empty()) {
            first_data = false;
            continue;
        }

        if (first_data) {
            size_t pos = line.find('-');
            size_t first = std::stoll(line.substr(0, pos));
            size_t second = std::stoll(line.substr(pos+1));
            ranges.insert({first, second});
        }
        else {
            ids.push_back(std::stoll(line));
        }

    }

    //first part, improve searching
    // std::map<size_t, size_t>::iterator
    long long sum1 = 0;
    for (auto &i : ids) {
        for (auto &r : ranges) {
            size_t lower = r.first;
            size_t upper = r.second;

            if(i >= lower && i <= upper){
                ++sum1;
                break;
            }
        } 
    }


    std::cout << sum1 << std::endl;

    //prever kako je najbolj prov dodajat elemente!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

    std::map<size_t, size_t> total_range;
    for (const auto &r : ranges) {
        size_t lower = r.first;
        size_t upper = r.second;

        if (total_range.empty()) {
            total_range[lower] = upper; //če še ni nč se doda prvi element
        }
        else {
            auto last = total_range.rbegin(); //zadnji range v total_range
            auto lower_last = last->first;
            auto upper_last = last->second;

            if (lower > upper_last) {
                total_range[lower] = upper;
            }
            else if (upper > upper_last) {
                total_range[lower_last] = upper;
            }
        }
    }

    long long sum2 = 0;
    for (auto &a : total_range) {
        size_t lower = a.first;
        size_t upper = a.second;
        // std::cout << a.first << " : " << a.second << std::endl;

        sum2 += upper - lower + 1;
    }

    std::cout << sum2 << std::endl;






    return 0;
}


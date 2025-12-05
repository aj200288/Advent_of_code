#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <vector>

#include "functions.h"


int main() {
    std::multimap<long long, long long> ranges; //multy map ker ti lahko povozi prvo vrednost
    std::vector<long long> ids;
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
            long long first = std::stoll(line.substr(0, pos));
            long long second = std::stoll(line.substr(pos+1));
            ranges.insert({first, second});
        }
        else {
            ids.push_back(std::stoll(line));
        }

    }
    
    
    // for (auto m : ranges) {
    //     std::cout << m.first << " : " << m.second << std::endl;
    // }

    //first part, improve searching
    // std::map<long long, long long>::iterator
    size_t sum1 = 0;
    for (auto &i : ids) {
        for (auto &r : ranges) {
            long long lower = r.first;
            long long upper = r.second;

            if(i >= lower && i <= upper){
                ++sum1;
                break;
            }
        } 
    }


    std::cout << sum1 << std::endl;

    //prever kako je najbolj prov dodajat elemente!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

    std::map<long long, long long> total_range;
    for (const auto &r : ranges) {
        long long lower = r.first;
        long long upper = r.second;

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
        long long lower = a.first;
        long long upper = a.second;
        // std::cout << a.first << " : " << a.second << std::endl;

        sum2 += upper - lower + 1;
    }

    std::cout << sum2 << std::endl;






    return 0;
}


//map ma dejanosko notr shranjen pair<const key, value>

#include "functions.h"
#include <algorithm>

constexpr int calculate_fuel(int mass) {
    return std::max(0, mass / 3 - 2);
}

int find_fuel_part1(int mass) {
    return calculate_fuel(mass);
}

int find_fuel_part2(int mass) {
    int total_fuel = 0;
    int fuel = calculate_fuel(mass);
    
    while (fuel > 0) {
        total_fuel += fuel;
        fuel = calculate_fuel(fuel);
    }
    
    return total_fuel;
}
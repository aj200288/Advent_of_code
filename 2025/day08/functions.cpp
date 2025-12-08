#include "functions.h"

long long distance(std::vector<long long> vec1, std::vector<long long> vec2) {
    long long sum = 0;
    for (size_t i = 0; i < vec1.size(); ++i) {
        sum += (vec1[i] - vec2[i]) * (vec1[i] - vec2[i]);
    }

    return sum;
}

// retudn the index of group
int is_present(size_t p, const std::vector<std::vector<size_t>> &groups) {
    for (size_t i = 0; i < groups.size(); ++i) {
        for (const auto& element : groups[i]) {
            if (element == p) {
                return i;
            }
        }
    }
    return -1;
}
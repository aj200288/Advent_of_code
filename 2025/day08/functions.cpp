#include "functions.h"

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


// distance beteen two boxes
long long distance(const Box &box1, const Box &box2) {
        long long dx = box1.x - box2.x;
        long long dy = box1.y - box2.y;
        long long dz = box1.z - box2.z;
        return dx*dx + dy*dy + dz*dz;
    }


bool Edge::operator<(const Edge &other) const {
    return distance < other.distance;
}
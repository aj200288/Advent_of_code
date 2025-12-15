#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <vector>
#include <string>
#include <sstream>
#include <queue>
#include <set>
#include <utility>
#include <z3++.h> 

std::vector<int> parse_group(const std::string& str);
int BFS(const std::vector<int> &buttons, const int &initial_state, const int &goal_state);
long long part2(const std::vector<std::vector<int>> &buttons, const std::vector<int> &joltage);


#endif // FUNCTIONS_H

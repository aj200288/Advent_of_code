#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <vector>
#include <string>
#include <sstream>
#include <queue>
#include <set>
#include <utility>

std::vector<int> parse_group(const std::string& str);
int BFS(const std::vector<int> &buttons, const int &initial_state, const int &goal_state);


#endif // FUNCTIONS_H

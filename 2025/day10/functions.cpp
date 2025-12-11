#include "functions.h"

std::vector<int> parse_group(const std::string& str) {
    std::vector<int> result;
    std::string content = str.substr(1, str.length() - 2); // odstrani oklepaje
    
    std::stringstream ss(content);
    std::string token;
    while (std::getline(ss, token, ',')) {
        result.push_back(std::stoi(token));
    }
    return result;
}



int BFS(const std::vector<int> &buttons, const int &initial_state, const int &goal_state) {
    std::queue<std::pair<int, int>> que; // state, passes
    std::set<int> visited;

    que.push({initial_state, 0});
    visited.insert(initial_state);

    while (!que.empty()) {
        auto [current_state, passes] = que.front();
        que.pop();

        if (current_state == goal_state)
            return passes;

        for (const auto &btn : buttons) {
            int new_state = current_state ^ btn;


            if (visited.find(new_state) == visited.end()) { // not found
                    visited.insert(new_state);
                    que.push({new_state, passes + 1});
            }
        }
    }

    return -1; // če ne najde nič

}


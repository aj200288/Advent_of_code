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


long long part2(const std::vector<std::vector<int>> &buttons, const std::vector<int> &joltage) {
    z3::context ctx;
    z3::optimize opt(ctx);

    std::vector<z3::expr> button_vars;
    for (size_t b = 0; b < buttons.size(); b++) {
      z3::expr var = ctx.int_const(("b" + std::to_string(b)).c_str());
      button_vars.push_back(var);
      opt.add(var >= 0);
    }

    for (size_t c = 0; c < joltage.size(); c++) {
      z3::expr sum = ctx.int_val(0);
      for (size_t b = 0; b < buttons.size(); b++) {
        bool affects = false;
        for (int id : buttons[b]) {
          if (id == (int)c) {
            affects = true;
            break;
          }
        }
        if (affects) {
          sum = sum + button_vars[b];
        }
      }
      opt.add(sum == ctx.int_val(joltage[c]));
    }

    z3::expr objective = ctx.int_val(0);
    for (size_t i = 0; i < buttons.size(); i++) {
      objective = objective + button_vars[i];
    }
    opt.minimize(objective);
    if (opt.check() == z3::sat) {
      z3::model m = opt.get_model();
      return m.eval(objective).get_numeral_int();
    }

    return 0;
}


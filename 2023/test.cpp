#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

std::vector<int> split(const std::string& str) {
    std::vector<int> out;
    std::istringstream iss(str);
    std::string word;
    
    while (iss >> word) {
        out.push_back(stoi(word));
    }
    
    return out;
}

int main() {

    std::string a = " 12 13 14 15 ";
    std::vector<int> b = split(a);

    for(auto &o : b) {
        std::cout << o << std::endl;
    }

    return 0;
}
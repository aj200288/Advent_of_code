#include <iostream>
#include <string>
using namespace std;

int main() {
    
    std::string a = "";
    a += '1';
    a += '2';

    int b = std::stoi(a);

    std::cout << b;
    return 0;
}
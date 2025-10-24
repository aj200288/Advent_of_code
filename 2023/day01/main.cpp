#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>


int main() {

    // Part one:
    int sum1 = 0;

    // read file line by line
    std::ifstream file("input.txt");
    std::string line;
    while (getline(file, line)) {
        bool first = true;
        int last = 0;

        for (char c : line) {
            if (isdigit(c)) {
                if (first) {
                    sum1 +=  (c - '0') * 10; // get a digit form char. (multiply by 10 as first digits are tens)
                    first = false;
                }
                last = c - '0';
            }
        }
        sum1 += last;
    }

    std::cout << "Part one: " << sum1 << std::endl;



    // Part two ------------------------------------------------------------------------------------------------
    // Reset file stream to beginning for second pass
    file.clear();  // Clear any error flags
    file.seekg(0); // Seek to beginning of file

    std::vector<std::string> num_words = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    std::map<int, int> map; // position -> digit value
    int sum2 = 0;

    while (getline(file, line)) {
        map.clear(); // each line own map

        // find word numbers
        for (int i = 0; i < num_words.size(); ++i) {
            const auto& word = num_words[i]; //auto for maintainibility and &address location so that memory is not copied 
            size_t pos = line.find(word);
            while (pos != std::string::npos) { // npos-> not found, while instead of if to find all instances
                map[pos] = i;
                pos = line.find(word, pos + 1); //keep searching
            }
        }

        // find digits
        for (int i = 0; i < line.length(); ++i) {
            if (isdigit(line[i])) map[i] = line[i] - '0';
        }

        sum2 += (map.begin()->second) * 10; // get the value of first element in the map (firs number in line)
        sum2 += (map.rbegin()->second); // get the value of the last lement in the map (last number in line)
    }

    std::cout << "Part two: " << sum2 << std::endl;

    return 0;
}


// bi blo bl učinkovit če za vsask char v vrstici prever če je števka in poj še za besedo -> pa naprej ..




// CHATGPT SOLUTION:

// std::map<int, int> all_nums; // position -> digit value

// // Find digit characters
// for (size_t pos = 0; pos < line.length(); ++pos) {
//     if (isdigit(line[pos])) {
//         all_nums[pos] = line[pos] - '0';
//     }
    
//     // Check for word numbers at this position
//     for (int i = 0; i < num_words.size(); ++i) {
//         const auto& word = num_words[i];
//         if (pos + word.length() <= line.length() && 
//             line.substr(pos, word.length()) == word) {
//             all_nums[pos] = i;
//         }
//     }
// }

// // Get first and last numbers
// if (!all_nums.empty()) {
//     int first = all_nums.begin()->second;
//     int last = all_nums.rbegin()->second;
//     // Use first and last...
// }

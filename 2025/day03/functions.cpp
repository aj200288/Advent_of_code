#include <string>
#include <iostream>
#include <vector>

#include "functions.h"


//najprej preverš vse razen zadnjih 11
//poj preverš vse od prejšnje max pa do zadnjih 10
//poj preverš vse od prejšnje pa do zadnjih 9

size_t max(const std::string &line, const int num_bat) {
    size_t total = 0;
    size_t start_pos = 0;

    // za vseh 12 kje končaš (ne more bit size t ker je veno true v tem primeru)
    for (int k = num_bat-1; k >= 0; --k) {
        int max = 0;
        size_t max_pos = start_pos;
        
        //za vse char v vrsti
        for (size_t j = start_pos; j < line.size() - k; ++j) {
            int num = line[j] - '0';
            if (num > max) {
                max = num;
                max_pos = j;
                if (num == 9) // večje cifre ne bo
                    break;
            }
        }
        total = total * 10 + max;
        start_pos = max_pos + 1;  // Start naslenje iteracije je eno za prejšnjo max vrednostjo
    }
    // std::cout << max_str << std::endl;
    return total;
}


// Original: 

// size_t max(const std::string &line, const int num_bat) {
//     std::string max_str = "";
//     int start_pos = 0;

//     // za vseh 12 kje končaš
//     for (int k = num_bat-1; k >= 0; --k) {
//         int max = 0;
//         char cmax = '0';
//         int max_pos = start_pos;
        

//         //za vse char v vrsti
//         for (int j = start_pos; j < line.size() - k; ++j) {
//             int num = line[j] - '0';
//             if (num > max) {
//                 max = num;
//                 cmax = line[j];
//                 max_pos = j + 1;
//             }
//         }
//         max_str += cmax;
//         start_pos = max_pos;  // Naslednja iteracija po max prejšje
//     }


//     // std::cout << max_str << std::endl;
//     return std::stoll(max_str);
// }
#include <string>
#include <set>

#include <iostream>

#include "functions.h"


long long invalid_ids_part1 (long long id1, long long id2) {
    long long sum = 0;

    for (long long i = id1; i < id2 + 1; ++i) {
        std::string id = std::to_string(i);

        int id_len = id.size();
        if (id_len % 2 != 0) continue;

        std::string half1 = id.substr(0, id_len / 2);
        std::string half2 = id.substr(id_len / 2);

        if (half1 == half2) {
            sum += i;
        }
    }

    return sum;
}

// improved
long long invalid_ids_part2 (long long id1, long long id2) {
    long long sum = 0;

    for (long long i = id1; i <= id2; ++i) {
        std::string id = std::to_string(i);
        int id_len = id.size();

        for (int w = 1; w <= id_len / 2; ++w) {
            if (id_len % w != 0) continue; // če dolžina niza ni večkratnik okna preskoči
            
            bool is_valid = true;
            std::string pattern = id.substr(0, w); // prvo okno (vsa nadaljna morajo biti enaka)
            
            //sprehodimo se čez niz z oknom
            for (int j = w; j < id_len; j += w) {
                if (id.substr(j, w) != pattern) {
                    is_valid = false;
                    break;
                }
            }

            if (is_valid) {
                sum += i;
                break; // ko je za določneo število potrjeno, da je id, končamo (sicer se idji lahko ponavljajo - 2222 -> 2 2 2 2 ali 22 22))
            }
        }
    }
    
    return sum;
}



// ORIGINAL part2:

// long long invalid_ids_part2 (long long id1, long long id2) {
//     long long sum = 0;
//     std::set<std::string> id_set;

//      for (long long i = id1; i < id2 + 1; ++i) {
//         std::string id = std::to_string(i);
//         int id_len = id.size();

//         //velikost okna
//         for (int w = 1; w <= id_len / 2 ; ++w) {
//             if (id_len % w != 0) continue; // če dolžina niza ni večkratnik okna preskoči
//             bool is_id = true;

//             // se sprehodimo čez niz z oknom
//             for(int j = 0; j < id_len/w - 1; ++j) {
//                 if (id.substr(j*w, w) != id.substr((j+1)*w,  w)) {
//                     is_id = false;
//                     break;
//                 }
//             }

//             if (is_id)
//                 id_set.insert(id); // dodamo v set (set ker jih se idji lahko ponavljajo - 2222 -> 2 2 2 2 ali 22 22)

           
//         }
//     }

//     for (auto const &a : id_set) {
//         // std::cout << "set: " << a << std::endl;
//         sum += std::stoll(a);
//     }
    
//     return sum;
// }
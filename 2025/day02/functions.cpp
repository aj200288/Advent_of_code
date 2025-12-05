#include <string>
#include <set>

#include <iostream>

#include "functions.h"

// mora biti const das lahko pass by reference ker p.first ni specifično ime spremenljivke (v main.cpp) 
size_t invalid_ids_part1 (const size_t &id1, const size_t &id2) {
    size_t sum = 0;

    for (size_t id = id1; id <= id2; ++id) { // za vsak id v šteivlu
        const std::string sid = std::to_string(id);
        const int id_len = sid.size();

        if (id_len % 2 != 0) continue; // če ni parno število, ne moremo števila dat točno na pol

        // prva in druga polovica števila morta biti enaki
        if (sid.substr(0, id_len / 2) == sid.substr(id_len / 2)) {
            sum += id;
        }
    }

    return sum;
}

// improved
size_t invalid_ids_part2 (const size_t &id1, const size_t &id2) {
    size_t sum = 0;

    for (size_t id = id1; id <= id2; ++id) {
        const std::string sid = std::to_string(id);
        const int id_len = sid.size();

        //dolžina okna, ki je največ polovica niza
        for (int w = 1; w <= id_len / 2; ++w) {
            if (id_len % w != 0) continue; // če dolžina niza ni večkratnik okna preskoči
            
            bool is_valid = true;
            const std::string pattern = sid.substr(0, w); // prvo okno (vsa nadaljna morajo biti enaka)
            
            //sprehodimo se čez niz z oknom
            for (int j = w; j < id_len; j += w) {
                if (sid.substr(j, w) != pattern) {
                    is_valid = false;
                    break;
                }
            }

            if (is_valid) {
                sum += id;
                break; // ko je za določeno število potrjeno, da je id, končamo (sicer se idji lahko ponavljajo - 2222 -> 2 2 2 2 ali 22 22))
            }
        }
    }
    
    return sum;
}



// ORIGINAL part2:

// size_t invalid_ids_part2 (size_t id1, size_t id2) {
//     size_t sum = 0;
//     std::set<std::string> id_set;

//      for (size_t i = id1; i < id2 + 1; ++i) {
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
#include "functions.h"

// če je you morš pazit da se ne zacikla dejansk ne ker je forward graf in ne greš nazaj 
long long paths(const std::string &key, const std::unordered_map<std::string, std::vector<std::string>> &connections) {
    long long sum = 0;
    for (const auto &conn : connections.at(key)) {// za vsako povezavo
        if (conn == "out") sum += 1;
        else sum += paths(conn, connections);
    }
    return sum;
}



long long paths2(const std::string &key, const std::string &key_out, const std::unordered_map<std::string, std::vector<std::string>> &connections, std::unordered_map<std::string, long long> &memo) {
    // preverimo če ključ obstaja (out dela probleme)
    if(connections.find(key) == connections.end()){
        return 0;
    }

    // Če smo ključ že obravnavali
    if (memo.count(key) > 0) {
        return memo[key];
    }
    
    long long sum = 0;
    for (const auto &conn : connections.at(key)) {// za vsako povezavo
        if (conn == key_out) sum += 1;
        else sum += paths2(conn, key_out, connections, memo);
    }
    
    // shranimo ključ in vsto do takrat
    memo[key] = sum;
    return sum;
}









// sum se ne skenlsa ker gledaš vasako posebi
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>
#include <vector>
#include <unordered_map>
#include <set>

long long paths(const std::string &key, const std::unordered_map<std::string, std::vector<std::string>> &connections);
long long paths2(const std::string &key, const std::string &key_out, const std::unordered_map<std::string, std::vector<std::string>> &connections, std::unordered_map<std::string, long long> &memo);



#endif // FUNCTIONS_H

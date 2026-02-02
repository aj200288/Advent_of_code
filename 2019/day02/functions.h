#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <vector>

long long intcode(std::vector<long long>& nums);


struct IntcodeBlock {
    long long opcode;
    long long operand1_pos;
    long long operand2_pos;
    long long destination_pos;
};



#endif // FUNCTIONS_H

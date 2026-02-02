#include <iostream>
#include <vector>

#include "functions.h"



long long intcode(std::vector<long long>& nums) {
    for (size_t i = 0; i + 3 < nums.size(); i += 4) {
        IntcodeBlock block{nums[i], nums[i+1], nums[i+2], nums[i+3]};
        
        if (block.opcode == 1)
            nums[block.destination_pos] = nums[block.operand1_pos] + nums[block.operand2_pos];
        else if (block.opcode == 2)
            nums[block.destination_pos] = nums[block.operand1_pos] * nums[block.operand2_pos];
        else if (block.opcode == 99)
            return nums[0];
        else {
            // std::cout << "Unknown opcode: " << block.opcode << std::endl;
            return -1;
        }
    }
    
    return nums[0];
}
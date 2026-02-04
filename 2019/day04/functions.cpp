#include "functions.h"


bool is_valid1(int num) {
    int prev_digit = 10; 
    bool has_double = false;
    
    while (num > 0) {
        int digit = num % 10;
        num /= 10;

        if (digit > prev_digit)
            return false;

        if (digit == prev_digit)
            has_double = true;

        prev_digit = digit;
    }

    return has_double;
}

bool is_valid2(int num) {
    bool has_exact_double = false;

    Repeat current {.digit = 10, .repetitions = 0};

    while (num > 0) {
        int digit = num % 10;
        num /= 10;

        if (digit > current.digit)
            return false;

        if (digit == current.digit) {
            ++current.repetitions;
        } 
        else {
            if (current.repetitions == 1) // ker ko je 1 sta že obe skupej
                has_exact_double = true;

            current.digit = digit;
            current.repetitions = 0;
        }
    }
    
    if (current.repetitions == 1)
        has_exact_double = true;

    return has_exact_double;
}

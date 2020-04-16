#include "sum_square_difference.h"

#include <iostream>

namespace project_euler {
    void print_sum_square_difference(const unsigned int n) {
        std::cout << "The sum square difference of the sequence 1 to "
            << n << " is: " << get_sum_square_difference(n) << "\n";
    }
}
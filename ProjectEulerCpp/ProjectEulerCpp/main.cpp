#include "project_euler.h"

#include <iostream>

namespace pe = project_euler;

int main() {
    //pe::print_smallest_multiple_of_one_through_n(20);
    //pe::print_sum_square_difference(100);
    pe::print_largest_product_of_a_series(pe::largeSeries, 13);
    /*std::vector<unsigned int> vec{0,1,2,3,4,9,9,8,9,2};
    std::cout << "Product: " << produce_product(vec.begin() + 2, vec.begin() + 4, 1U) << "\n";*/

    return 0;
}
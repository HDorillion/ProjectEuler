#include "maths.h"
#include "smallest_multiple.h"

#include <algorithm>
#include <iostream>
#include <vector>

namespace project_euler {
    // Prints the least common multiple of the sequence 1 to n
    void print_smallest_multiple_of_one_through_n(const unsigned int n) {
        std::vector<unsigned int> vec;
        for (auto i = 1U; i < n; ++i) {
            auto primes = math::get_prime_factors(i);
            std::vector<unsigned int> result;
            auto new_end = std::set_difference(
                primes.begin(), primes.end(), vec.begin(), vec.end(),
                std::back_inserter(result)
            );
            std::move(result.begin(), result.end(), std::back_inserter(vec));
            std::sort(vec.begin(), vec.end());
        }

        // Calculate and print the LCM
        unsigned int leastCommonMultiple = 1;
        for (int i : vec) {
            leastCommonMultiple *= i;
        }
        std::cout << "Least common multiple: " << leastCommonMultiple << "\n";
    }
}

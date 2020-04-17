#include "summation_of_primes.h"

#include <iostream>

namespace project_euler {
    void print_summation_of_primes_below_n(unsigned int n) {
        std::cout << "The sum of all primes below " << n << " is: "
            << get_summation_of_primes_below_n(n) << "\n"
        ;
    }
}
#pragma once

#include <algorithm>

#include "maths.h"

namespace project_euler {
    constexpr double get_summation_of_primes_below_n(unsigned int n) {
        // Start at sum == 2 and i == 3 so every other number is skipped
        double sum = 2.0;
        for (auto i = 3.0; i < n; i+=2) {
            sum += i * static_cast<unsigned int>(math::is_prime(static_cast<unsigned int>(i)));
        }
        return sum;
    }

    void print_summation_of_primes_below_n(unsigned int n);
}

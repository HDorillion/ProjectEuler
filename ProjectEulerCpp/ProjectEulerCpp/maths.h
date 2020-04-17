#pragma once

#include <vector>

namespace math {
    // Returns all prime factors of n
    std::vector<unsigned int> get_prime_factors(unsigned int n);
    constexpr bool is_prime(unsigned int n) {
        // Return if divisible by 2
        if (n % 2 == 0 && n != 2) {
            return n == 2;
        }

        // Skip one element because n is odd
        for (int i = 3; i <= sqrt(n); i += 2) {
            // While i divides n
            while (n % i == 0) {
                return false;
            }
        }

        // n is a prime number
        return true;
    }
}

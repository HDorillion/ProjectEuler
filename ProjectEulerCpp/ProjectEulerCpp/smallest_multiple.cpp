#include "smallest_multiple.h"

#include <algorithm>
#include <iostream>
#include <vector>

namespace project_euler {
    // Returns all prime factors of n
    std::vector<unsigned int> get_prime_factors(unsigned int n)
    {
        std::vector<unsigned int> factors;
        // Loop until n is odd
        while (n % 2 == 0)
        {
            factors.push_back(2);
            n = n / 2;
        }

        // Skip one element because n is odd
        for (int i = 3; i <= sqrt(n); i = i + 2)
        {
            // While i divides n
            while (n % i == 0)
            {
                factors.push_back(i);
                n = n / i;
            }
        }

        // n is a prime number greater than 2
        if (n > 2)
            factors.push_back(n);
        return factors;
    }

    // Prints the least common multiple of the sequence 1 to n
    void print_smallest_multiple_of_one_through_n(const unsigned int n) {
        std::vector<unsigned int> arr;
        for (auto i = 1; i < n; ++i) {
            auto primes = get_prime_factors(i);
            std::vector<unsigned int> result;
            auto new_end = std::set_difference(
                primes.begin(), primes.end(), arr.begin(), arr.end(),
                std::back_inserter(result)
            );
            std::move(result.begin(), result.end(), std::back_inserter(arr));
            std::sort(arr.begin(), arr.end());
        }

        unsigned int leastCommonMultiple = 1;
        for (int i : arr) {
            leastCommonMultiple *= i;
        }
        std::cout << "Least common multiple: " << leastCommonMultiple << "\n";
    }
}

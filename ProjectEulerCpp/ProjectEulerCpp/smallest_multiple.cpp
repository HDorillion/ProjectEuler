#include "smallest_multiple.h"

#include <algorithm>
#include <iostream>
#include <vector>

namespace project_euler {
    template<typename T>
    constexpr std::vector<T> generate_sequence(const T n) {
        std::vector<T> arr( static_cast<size_t>(n) );
        for (size_t i = 0; i < n; ++i) {
            arr[i] = i + 1;
        }
        return arr;
    }
    void print_smallest_multiple_of_one_through_n(const unsigned int n) {
        auto numberArray = generate_sequence(n);
        while (true) {
            auto minElement = std::min_element(numberArray.begin(), numberArray.end());
            auto maxElement = std::max_element(numberArray.begin(), numberArray.end());
            if (minElement == maxElement) {
                std::cout << *minElement << "\n";
                break;
            }
            *minElement += std::distance(numberArray.begin(), minElement) + 1;
        }
    }

    std::vector<unsigned int> get_prime_factors(unsigned int n)
    {
        std::vector<unsigned int> factors;
        // Print the number of 2s that divide n  
        while (n % 2 == 0)
        {
            factors.push_back(2);
            n = n / 2;
        }

        // n must be odd at this point. So we can skip  
        // one element (Note i = i +2)  
        for (int i = 3; i <= sqrt(n); i = i + 2)
        {
            // While i divides n, print i and divide n  
            while (n % i == 0)
            {
                factors.push_back(i);
                n = n / i;
            }
        }

        // This condition is to handle the case when n  
        // is a prime number greater than 2
        if (n > 2)
            factors.push_back(n);
        return factors;
    }

    void print_smallest_multiple_of_one_through_n_with_prime_factors(const unsigned int n) {
        std::vector<unsigned int> arr;
        for (auto i = 1; i < n; ++i) {
            auto primes = get_prime_factors(i);
            std::vector<unsigned int>result;
            auto new_end = std::set_difference(
                primes.begin(), primes.end(), arr.begin(), arr.end(),
                std::back_inserter(result)
            );
            std::cout << "Input: ";
            for (int j : result) {
                std::cout << j << " ";
            }
            std::cout << "\n";
            std::move(result.begin(), result.end(), std::back_inserter(arr));
            std::sort(arr.begin(), arr.end());
            std::cout << "Output: ";
            for (int j : arr) {
                std::cout << j << " ";
            }
            std::cout << "\n";
        }
        
        unsigned int leastCommonMultiple = 1;
        for (int i : arr) {
            leastCommonMultiple *= i;
        }
        std::cout << "Least common multiple: " << leastCommonMultiple << "\n";
    }
}

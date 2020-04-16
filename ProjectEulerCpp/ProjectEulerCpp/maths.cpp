#include "maths.h"

namespace math {
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
}
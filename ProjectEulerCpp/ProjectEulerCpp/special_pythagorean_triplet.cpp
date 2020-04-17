#include "special_pythagorean_triplet.h"

namespace project_euler {
    // This function depends on the fact that sum will equal 1000
    // This is NOT a general function
    constexpr unsigned int get_pythagorean_triplet_product() {
        auto a = 0U, b = 0U, c = 0U;
        auto m = 2U; // loop from 2 to max_limitit
        auto sum = 0U;

        // Until sum == 1000, loop on j from 1 to i-1 
        while (sum != 1000U) {
            for (auto n = 1U; n < m; ++n) {
                // use the relation between a, b and c 
                a = m * m - n * n;
                b = 2 * m * n;
                c = m * m + n * n;
                sum = a + b + c;
                if (sum == 1000U) {
                    return a * b * c;
                }
            }
            m++;
        }
        return 0; // Failed to be a general function
    }
    void print_pythagorean_triplet() {
        std::cout << "The product of the pythagorean triplet where a + b + c = 1000 is: "
            << get_pythagorean_triplet_product() << "\n"
        ;
    }
}
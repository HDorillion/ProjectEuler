#include "largest_product_of_a_series.h"

#include <algorithm>
#include <iostream>

namespace project_euler {
    template<class InputIt, class T>
    _NODISCARD
    constexpr T produce_product(InputIt first, InputIt last, T init) {
        for (; first != last; ++first) {
            init = std::move(init) * (*first);
        }
        return init;
    }

    // The test case of 4 worked, but the quiz for 13 failed
    // Need to investigate further
    unsigned int get_largest_product_of_a_series(
        const std::vector<unsigned int> series,
        const unsigned int length
    ) {
        unsigned int largestProduct = 0;
        for (auto it = series.begin(); it != (series.end() - length + 1); ++it) {
            auto contains_zero = [](auto a) { return (a == 0); };
            if (std::count_if(it, it + length, contains_zero)) {
                continue;
            }
            auto product = produce_product(it, it + length, 1U);
            largestProduct = std::max(largestProduct, product);
        }
        return largestProduct;
    }
    void print_largest_product_of_a_series(
        const std::vector<unsigned int> series,
        const unsigned int length
    ) {
        std::cout << "The largest product of " << length
            << " consecutive numbers for the given series is: "
            << get_largest_product_of_a_series(series, length) << "\n"
        ;
    }
}
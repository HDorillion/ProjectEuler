#pragma once

// Prompt:
// The sum of the squares of the first ten natural numbers is,
// 1^2 + 2^22 + ... + 10^2 = 385
// The square of the sum of the first ten natural numbers is,
// (1 + 2 + ... + 10)^2 = 55^2 = 3025
// Hence the difference between the sum of the squares of the first ten natural
// numbers and the square of the sum is 3025 - 385 = 2640
//
// Find the difference between the sum of the squares of the first one hundred
// natural numbers and the square of the sum.
namespace project_euler {
    void print_sum_square_difference(const unsigned int n);
    constexpr unsigned int get_sum_square_difference(const unsigned int n) {
        unsigned int sumOfSquares = 0;
        unsigned int squareOfSums = 0;
        for (size_t i = 1; i <= n; ++i) {
            sumOfSquares += (i * i);
            squareOfSums += i;
        }
        squareOfSums = squareOfSums * squareOfSums;
        return squareOfSums - sumOfSquares;
    }
}

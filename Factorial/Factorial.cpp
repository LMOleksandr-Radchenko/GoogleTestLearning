#include "Factorial.h"
#include <stdexcept>

size_t Factorial::compute(int n)
{
    if (n < 0)
        throw std::invalid_argument("Factorial of negative number is undefined");

    if (auto it = cache.find(n); it != cache.end())
        return it->second;

    size_t result = n * compute(n - 1);
    cache[n] = result;
    return result;
}

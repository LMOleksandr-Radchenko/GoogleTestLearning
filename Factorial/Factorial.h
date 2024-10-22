#ifndef FACTORIAL_H
#define FACTORIAL_H

#include <unordered_map>
#include <cstddef>

class Factorial
{
public:
    size_t compute(int n);

protected:
    std::unordered_map<int, size_t> cache {{0, 1}};
};

#endif // FACTORIAL_H

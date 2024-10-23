#include "Factorial.h"
#include <stdexcept>

void FactorialCache::put(int n, size_t value) noexcept
{
    cache[n] = value;
}

size_t FactorialCache::get(int n) const
{
    if (const auto it = cache.find(n); it != cache.end())
        return it->second;

    throw std::out_of_range("Cache does not contain the following value");
}

Factorial::Factorial(std::unique_ptr<FactorialCacheInterface> cache): cache(std::move(cache))
{
    this->cache->put(0, 1);
}

size_t Factorial::compute(int n)
{
    if (n < 0)
        throw std::invalid_argument("Factorial of negative number is undefined");

    try
    {
        return cache->get(n);
    }
    catch(const std::out_of_range&)
    {
        const size_t result = n * compute(n - 1);
        cache->put(n, result);
        return result;
    }
}

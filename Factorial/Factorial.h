#ifndef FACTORIAL_H
#define FACTORIAL_H

#include <unordered_map>
#include <cstddef>
#include <memory>

class FactorialCacheInterface
{
public:
    virtual ~FactorialCacheInterface() = default;
    virtual void put(int, size_t) noexcept = 0;
    [[nodiscard]] virtual size_t get(int) const = 0;
};

class FactorialCache : public FactorialCacheInterface
{
public:
    void put(int n, size_t value) noexcept override;
    [[nodiscard]] size_t get(int n) const override;

private:
    std::unordered_map<int, size_t> cache;
};

class Factorial
{
public:
    explicit Factorial(std::unique_ptr<FactorialCacheInterface> cache = std::make_unique<FactorialCache>());
    [[nodiscard]] size_t compute(int n);

protected:
    std::unique_ptr<FactorialCacheInterface> cache;
};

#endif // FACTORIAL_H

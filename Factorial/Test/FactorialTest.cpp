#include <gtest/gtest.h>
#include "Factorial.h"
#include <chrono>

class FactorialDerived : public Factorial
{
public:
    const std::unordered_map<int, size_t>& getCache() const
    {
        return cache;
    }
};

class FactorialTest : public ::testing::Test
{
public:
    FactorialDerived factorial;

protected:
    void TearDown() override
    {
        // reset the cache
        factorial = FactorialDerived();
    }
};

TEST_F(FactorialTest, TestValues) 
{
    EXPECT_EQ(factorial.compute(0), 1);
    EXPECT_EQ(factorial.compute(1), 1);
    EXPECT_EQ(factorial.compute(2), 2);
    EXPECT_EQ(factorial.compute(3), 6);
    EXPECT_EQ(factorial.compute(4), 24);
    EXPECT_EQ(factorial.compute(5), 120);
    EXPECT_EQ(factorial.compute(6), 720);
    EXPECT_EQ(factorial.compute(7), 5040);
    EXPECT_EQ(factorial.compute(8), 40320);
    EXPECT_EQ(factorial.compute(9), 362880);
    EXPECT_EQ(factorial.compute(10), 3628800);
}

TEST_F(FactorialTest, TestNegative) 
{
    EXPECT_THROW(factorial.compute(-1), std::invalid_argument);
    EXPECT_THROW(factorial.compute(-2), std::invalid_argument);
    EXPECT_THROW(factorial.compute(-3), std::invalid_argument);
    EXPECT_THROW(factorial.compute(-4), std::invalid_argument);
    EXPECT_THROW(factorial.compute(-5), std::invalid_argument);
}

TEST_F(FactorialTest, TestCacheFilling) 
{
    factorial.compute(5);
    for (int i = 0; i <= 5; ++i)
    {
        EXPECT_NE(factorial.getCache().find(i), factorial.getCache().end()) << "Cache missed for " << i;
    }
    for (int i = 6; i <= 10; ++i)
    {
        EXPECT_EQ(factorial.getCache().find(i), factorial.getCache().end()) << "Cache exists for " << i;
    }
}

TEST_F(FactorialTest, TestCacheUsage) 
{
    for (int i = 0; i <= 10; ++i)
    {
        auto no_cache_start = std::chrono::high_resolution_clock::now();
        factorial.compute(10);
        auto no_cache_end = std::chrono::high_resolution_clock::now();

        auto cache_start = std::chrono::high_resolution_clock::now();
        factorial.compute(10);
        auto cache_end = std::chrono::high_resolution_clock::now();

        auto no_cache_duration = std::chrono::duration_cast<std::chrono::nanoseconds>(no_cache_end - no_cache_start);
        auto cache_duration = std::chrono::duration_cast<std::chrono::nanoseconds>(cache_end - cache_start);

        EXPECT_GT(no_cache_duration, cache_duration);

        TearDown();
    }
}

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Factorial.h"
#include <chrono>

using namespace ::testing;

class FactorialCacheTest : public FactorialCacheInterface
{
public:
    MOCK_METHOD(void, put, (int, size_t), (noexcept, override));
    MOCK_METHOD(size_t, get, (int), (const, override));
};

TEST(FactorialTest, TestValues)
{
    Factorial factorial;

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

TEST(FactorialTest, TestNegative)
{
    Factorial factorial;

    EXPECT_THROW(factorial.compute(-1), std::invalid_argument);
    EXPECT_THROW(factorial.compute(-2), std::invalid_argument);
    EXPECT_THROW(factorial.compute(-3), std::invalid_argument);
    EXPECT_THROW(factorial.compute(-4), std::invalid_argument);
    EXPECT_THROW(factorial.compute(-5), std::invalid_argument);
}

TEST(FactorialTest, TestCacheUsage)
{
    InSequence s;

    FactorialCacheTest* cache_ref;
    Factorial factorial;

    {
        std::unique_ptr<FactorialCacheTest> cache = std::make_unique<FactorialCacheTest>();
        cache_ref = cache.get();

        // expect that cache will be initialized with "0! = 1"
        EXPECT_CALL(*cache_ref, put(0, ::testing::_)).Times(1);
        factorial = Factorial(std::move(cache));
    }

    EXPECT_CALL(*cache_ref, get(_))
        .Times(5)
        .WillRepeatedly(Throw(std::out_of_range("Factorial of negative number is undefined")));
    EXPECT_CALL(*cache_ref, get(_))
        .WillRepeatedly(Return(1));

    EXPECT_CALL(*cache_ref, put(1, _)).Times(1);
    EXPECT_CALL(*cache_ref, put(2, _)).Times(1);
    EXPECT_CALL(*cache_ref, put(3, _)).Times(1);
    EXPECT_CALL(*cache_ref, put(4, _)).Times(1);
    EXPECT_CALL(*cache_ref, put(5, _)).Times(1);

    EXPECT_EQ(factorial.compute(5), 120);

    EXPECT_CALL(*cache_ref, get(_))
        .WillOnce(Return(54));

    EXPECT_EQ(factorial.compute(5), 54);
}

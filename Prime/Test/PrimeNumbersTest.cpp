#include <gtest/gtest.h>

#include "PrimeNumbers.h"

TEST(PrimeNumbersTest, PositiveValuesTest)
{
    EXPECT_EQ(isPrime(1), false);
    EXPECT_EQ(isPrime(2), true);
    EXPECT_EQ(isPrime(3), true);
    EXPECT_EQ(isPrime(4), false);
    EXPECT_EQ(isPrime(5), true);
}

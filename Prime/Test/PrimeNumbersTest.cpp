#include <gtest/gtest.h>

#include "PrimeNumbers.h"

TEST(PrimeNumbersTest, LargePrimeValuesTest)
{
    EXPECT_EQ(isPrime(101), true);
    EXPECT_EQ(isPrime(103), true);
    EXPECT_EQ(isPrime(107), true);
    EXPECT_EQ(isPrime(109), true);
    EXPECT_EQ(isPrime(113), true);
}

TEST(PrimeNumbersTest, LargeNonPrimeValuesTest)
{
    EXPECT_EQ(isPrime(100), false);
    EXPECT_EQ(isPrime(102), false);
    EXPECT_EQ(isPrime(104), false);
    EXPECT_EQ(isPrime(105), false);
    EXPECT_EQ(isPrime(110), false);
}

TEST(PrimeNumbersTest, EdgeCaseValuesTest)
{
    EXPECT_EQ(isPrime(0), false);
    EXPECT_EQ(isPrime(1), false);
    EXPECT_EQ(isPrime(2), true);
    EXPECT_EQ(isPrime(3), true);
    EXPECT_EQ(isPrime(4), false);
}

TEST(PrimeNumbersTest, NegativeValuesTest)
{
    for (int i = 0; i > -100; --i)
    {
        EXPECT_EQ(isPrime(i), false) << "Failed for i = " << i;
    }
}

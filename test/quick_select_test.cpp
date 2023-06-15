#include <gtest/gtest.h>
extern "C" {
#include "algorithm/algorithm.h"
}

TEST(QuickSelect, Basic)
{
    for (int i = 0; i < 5; ++i)
    {
        int array[] = {0, 1,2,3,4};
        EXPECT_EQ(quick_select(array, 5, i), i);
    }
}

TEST(QuickSelect, Basic2)
{
    for (int i = 0; i < 5; ++i)
    {
        int array[] = {4, 3, 2, 1, 0};
        EXPECT_EQ(quick_select(array, 5, i), i);
    }
}

TEST(QuickSelect, Random)
{
    for (int i = 0; i < 5; ++i)
    {
        int array[] = {4, 0, 2, 1, 3};
        EXPECT_EQ(quick_select(array, 5, i), i);
    }
}

TEST(QuickSelect, Random2)
{
    for (int i = 0; i < 5; ++i)
    {
        int array[] = {0, 4, 3, 2, 1};
        EXPECT_EQ(quick_select(array, 5, i), i);
    }
}

TEST(QuickSelect, Random3)
{
    for (int i = 0; i < 5; ++i)
    {
        int array[] = {1, 2, 3 ,4, 0};
        EXPECT_EQ(quick_select(array, 5, i), i);
    }
}

TEST(QuickSelect, One)
{
    int array[] = {0};
    EXPECT_EQ(quick_select(array, 1, 0), 0);
}

TEST(QuickSelect, Two)
{
    for (int i = 0; i < 2; ++i)
    {
        int array[] = {0, 1};
        EXPECT_EQ(quick_select(array, 2, i), i);
    }
}
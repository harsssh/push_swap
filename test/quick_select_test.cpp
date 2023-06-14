#include <gtest/gtest.h>
extern "C" {
#include "algorithm/algorithm.h"
}

TEST(QuickSelect, Basic)
{
    int array[] = {0, 1,2,3,4};
    EXPECT_EQ(quick_select(array, 5, 0), 0);
    EXPECT_EQ(quick_select(array, 5, 1), 1);
    EXPECT_EQ(quick_select(array, 5, 2), 2);
    EXPECT_EQ(quick_select(array, 5, 3), 3);
    EXPECT_EQ(quick_select(array, 5, 4), 4);
}

TEST(QuickSelect, Basic2)
{
    int array[] = {4,3,2,1,0};
    EXPECT_EQ(quick_select(array, 5, 0), 0);
    EXPECT_EQ(quick_select(array, 5, 1), 1);
    EXPECT_EQ(quick_select(array, 5, 2), 2);
    EXPECT_EQ(quick_select(array, 5, 3), 3);
    EXPECT_EQ(quick_select(array, 5, 4), 4);
}

TEST(QuickSelect, Random)
{
    int array[] = {4, 0, 2, 1, 3};
    EXPECT_EQ(quick_select(array, 5, 0), 0);
    EXPECT_EQ(quick_select(array, 5, 1), 1);
    EXPECT_EQ(quick_select(array, 5, 2), 2);
    EXPECT_EQ(quick_select(array, 5, 3), 3);
    EXPECT_EQ(quick_select(array, 5, 4), 4);
}

TEST(QuickSelect, One)
{
    int array[] = {0};
    EXPECT_EQ(quick_select(array, 1, 0), 0);
}

TEST(QuickSelect, Two)
{
    int array[] = {0, 1};
    EXPECT_EQ(quick_select(array, 2, 0), 0);
    EXPECT_EQ(quick_select(array, 2, 1), 1);
}
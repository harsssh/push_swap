#include <gtest/gtest.h>
extern "C" {
#include "deque/deque.h"
}

TEST(deque, push_front_pop_front)
{
    t_deque	*dq;

    dq = deque_init(10);
    deque_push_front(dq, 1);
    deque_push_front(dq, 2);
    deque_push_front(dq, 3);
    EXPECT_EQ(deque_size(dq), 3);
    EXPECT_EQ(deque_pop_front(dq), 3);
    EXPECT_EQ(deque_pop_front(dq), 2);
    EXPECT_EQ(deque_pop_front(dq), 1);
    EXPECT_EQ(deque_size(dq), 0);
}

TEST(deque, push_front_pop_back)
{
    t_deque	*dq;

    dq = deque_init(10);
    deque_push_front(dq, 1);
    deque_push_front(dq, 2);
    deque_push_front(dq, 3);
    EXPECT_EQ(deque_size(dq), 3);
    EXPECT_EQ(deque_pop_back(dq), 1);
    EXPECT_EQ(deque_pop_back(dq), 2);
    EXPECT_EQ(deque_pop_back(dq), 3);
    EXPECT_EQ(deque_size(dq), 0);
}

TEST(deque, push_back_pop_front)
{
    t_deque	*dq;

    dq = deque_init(10);
    deque_push_back(dq, 1);
    deque_push_back(dq, 2);
    deque_push_back(dq, 3);
    EXPECT_EQ(deque_size(dq), 3);
    EXPECT_EQ(deque_pop_front(dq), 1);
    EXPECT_EQ(deque_pop_front(dq), 2);
    EXPECT_EQ(deque_pop_front(dq), 3);
    EXPECT_EQ(deque_size(dq), 0);
}

TEST(deque, push_back_pop_back)
{
    t_deque	*dq;

    dq = deque_init(10);
    deque_push_back(dq, 1);
    deque_push_back(dq, 2);
    deque_push_back(dq, 3);
    EXPECT_EQ(deque_size(dq), 3);
    EXPECT_EQ(deque_pop_back(dq), 3);
    EXPECT_EQ(deque_pop_back(dq), 2);
    EXPECT_EQ(deque_pop_back(dq), 1);
    EXPECT_EQ(deque_size(dq), 0);
}

TEST(deque, push_over_capacity)
{
    t_deque	*dq;

    dq = deque_init(3);
    deque_push_front(dq, 1);
    deque_push_front(dq, 2);
    deque_push_front(dq, 3);
    deque_push_front(dq, 4);
    EXPECT_EQ(deque_size(dq), 3);
    EXPECT_EQ(deque_pop_front(dq), 3);
    EXPECT_EQ(deque_pop_front(dq), 2);
    EXPECT_EQ(deque_pop_front(dq), 1);
    EXPECT_EQ(deque_size(dq), 0);
}

TEST(deque, pop_empty)
{
    t_deque	*dq;

    dq = deque_init(3);
    EXPECT_EQ(deque_pop_front(dq), 0);
    EXPECT_EQ(deque_pop_back(dq), 0);
    EXPECT_EQ(deque_size(dq), 0);
}

TEST(deque, push_and_pop_many)
{
    t_deque	*dq;

    dq = deque_init(100);
    for (int i = 0; i < 100; i++)
        deque_push_front(dq, i);
    EXPECT_EQ(deque_size(dq), 100);
    for (int i = 99; i >= 0; i--)
        EXPECT_EQ(deque_pop_front(dq), i);
    EXPECT_EQ(deque_size(dq), 0);
}

TEST(deque, is_empty)
{
    t_deque	*dq;

    dq = deque_init(10);
    EXPECT_EQ(dq->is_empty, true);
    deque_push_front(dq, 1);
    EXPECT_EQ(dq->is_empty, false);
    deque_pop_front(dq);
    EXPECT_EQ(dq->is_empty, true);
    deque_pop_front(dq);
    EXPECT_EQ(dq->is_empty, true);
}
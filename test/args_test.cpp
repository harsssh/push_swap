#include <gtest/gtest.h>
extern "C" {
#include "args/parse_args.h"
}

/* 異常系 */
// 何も与えない場合はexit
TEST(parse_args, no_args)
{
    char	*argv[] = {"./args_test"};

    EXPECT_EXIT(parse_args(1, argv), ::testing::ExitedWithCode(1), "");
}

// 数値表現でない場合はexit
TEST(parse_args, not_number)
{
    char	*argv[] = {"./args_test", "a"};

    EXPECT_EXIT(parse_args(2, argv), ::testing::ExitedWithCode(1), "");
}

// leading zeroがある場合はexit
TEST(parse_args, leading_zero)
{
    char	*argv[] = {"./args_test", "01"};

    EXPECT_EXIT(parse_args(2, argv), ::testing::ExitedWithCode(1), "");
}

TEST(parse_args, leading_zero2)
{
    char	*argv[] = {"./args_test", "00"};

    EXPECT_EXIT(parse_args(2, argv), ::testing::ExitedWithCode(1), "");
}

// 正の符号がある場合はexit
TEST(parse_args, positive_sign)
{
    char	*argv[] = {"./args_test", "+1"};

    EXPECT_EXIT(parse_args(2, argv), ::testing::ExitedWithCode(1), "");
}

// 負の符号のみの場合はexit
TEST(parse_args, negative_sign_only)
{
    char	*argv[] = {"./args_test", "-"};

    EXPECT_EXIT(parse_args(2, argv), ::testing::ExitedWithCode(1), "");
}

// 負の符号を複数もつ場合はexit
TEST(parse_args, negative_sign)
{
    char	*argv[] = {"./args_test", "--1"};

    EXPECT_EXIT(parse_args(2, argv), ::testing::ExitedWithCode(1), "");
}

// 0が負の符号をもつ場合はexit
TEST(parse_args, negative_sign2)
{
    char	*argv[] = {"./args_test", "-0"};

    EXPECT_EXIT(parse_args(2, argv), ::testing::ExitedWithCode(1), "");
}

// leading zeroがある0が負の符号をもつ場合はexit
TEST(parse_args, negative_sign3)
{
    char	*argv[] = {"./args_test", "-00"};

    EXPECT_EXIT(parse_args(2, argv), ::testing::ExitedWithCode(1), "");
}

// 符号が混在する場合
TEST(parse_args, mixed_sign)
{
    char	*argv[] = {"./args_test", "-+1"};

    EXPECT_EXIT(parse_args(2, argv), ::testing::ExitedWithCode(1), "");
}

TEST(parse_args, mixed_sign2)
{
    char	*argv[] = {"./args_test", "+-1"};

    EXPECT_EXIT(parse_args(2, argv), ::testing::ExitedWithCode(1), "");
}

// 重複がある場合はexit
TEST(parse_args, duplicate)
{
    char	*argv[] = {"./args_test", "1", "1"};

    EXPECT_EXIT(parse_args(3, argv), ::testing::ExitedWithCode(1), "");
}

// INT_MAXより大きい場合はexit
TEST(parse_args, too_big)
{
    char	*argv[] = {"./args_test", "2147483648"};

    EXPECT_EXIT(parse_args(2, argv), ::testing::ExitedWithCode(1), "");
}

// INT_MINより小さい場合はexit
TEST(parse_args, too_small)
{
    char	*argv[] = {"./args_test", "-2147483649"};

    EXPECT_EXIT(parse_args(2, argv), ::testing::ExitedWithCode(1), "");
}

/* 正常系 */
// 引数が1つ
TEST(parse_args, one_arg)
{
    char	*argv[] = {"./args_test", "0"};
    int		*args;

    args = parse_args(2, argv);
    EXPECT_EQ(args[0], 0);
}

// 引数が2つ
TEST(parse_args, two_args)
{
    char	*argv[] = {"./args_test", "10", "-200"};
    int		*args;

    args = parse_args(3, argv);
    EXPECT_EQ(args[0], 10);
    EXPECT_EQ(args[1], -200);
}

// 引数が4つ
TEST(parse_args, four_args)
{
    char	*argv[] = {"./args_test", "0", "-1", "2", "-3"};
    int		*args;

    args = parse_args(5, argv);
    EXPECT_EQ(args[0], 0);
    EXPECT_EQ(args[1], -1);
    EXPECT_EQ(args[2], 2);
    EXPECT_EQ(args[3], -3);
}

// INT_MIN, INT_MAXを含む
TEST(parse_args, min_max)
{
    char	*argv[] = {"./args_test", "2147483647", "-2147483648"};
    int		*args;

    args = parse_args(3, argv);
    EXPECT_EQ(args[0], 2147483647);
    EXPECT_EQ(args[1], -2147483648);
}

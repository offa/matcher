
#include <CppUTest/TestHarness.h>
#include "matcher/CompareMatcher.h"
#include "Helper.h"

using namespace matcher;

TEST_GROUP(CompareMatcherTest)
{
};

TEST(CompareMatcherTest, is)
{
    CHECK_MATCHER(3, is(3), true, "is");
    CHECK_MATCHER(4, is(3), false, "is");
}

TEST(CompareMatcherTest, eq)
{
    CHECK_MATCHER(3, eq(3), true, "eq");
    CHECK_MATCHER(4, eq(3), false, "eq");
}

TEST(CompareMatcherTest, ne)
{
    CHECK_MATCHER(4, ne(3), true, "ne");
    CHECK_MATCHER(3, ne(3), false, "ne");
}

TEST(CompareMatcherTest, lt)
{
    CHECK_MATCHER(2, lt(3), true, "lt");
    CHECK_MATCHER(4, lt(3), false, "lt");
    CHECK_MATCHER(3, lt(3), false, "lt");
}

TEST(CompareMatcherTest, le)
{
    CHECK_MATCHER(2, le(3), true, "le");
    CHECK_MATCHER(3, le(3), true, "le");
    CHECK_MATCHER(4, le(3), false, "le");
}

TEST(CompareMatcherTest, gt)
{
    CHECK_MATCHER(4, gt(3), true, "gt");
    CHECK_MATCHER(2, gt(3), false, "gt");
    CHECK_MATCHER(3, gt(3), false, "gt");
}

TEST(CompareMatcherTest, ge)
{
    CHECK_MATCHER(4, ge(3), true, "ge");
    CHECK_MATCHER(3, ge(3), true, "ge");
    CHECK_MATCHER(2, ge(3), false, "ge");
}

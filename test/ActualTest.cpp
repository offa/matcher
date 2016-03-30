
#include <CppUTest/TestHarness.h>
#include "matcher/Actual.h"
#include "matcher/CompareMatcher.h"

using namespace matcher;

TEST_GROUP(ActualTest)
{
    const int value = 3;
};

TEST(ActualTest, expectThatReturnsTrueOnMatch)
{
    auto result = expect(value).that(eq(value));
    CHECK_TRUE(std::get<0>(result));
}

TEST(ActualTest, expectThatReturnsFalseOnMismatch)
{
    auto result = expect(value).that(eq(value + 1));
    CHECK_FALSE(std::get<0>(result));
}

TEST(ActualTest, expectMatchReturnsTrueOnMatch)
{
    bool result = expect(value).match(eq(value));
    CHECK_TRUE(result);
}

TEST(ActualTest, expectMatchReturnsFalseOnMismatch)
{
    bool result = expect(value).match(eq(value + 1));
    CHECK_FALSE(result);
}

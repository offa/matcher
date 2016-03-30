
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
    auto result = expect(value).that(is(value));
    CHECK_TRUE(std::get<0>(result));
}

TEST(ActualTest, expectThatReturnsFalseOnMismatch)
{
    auto result = expect(value).that(is(value + 1));
    CHECK_FALSE(std::get<0>(result));
}

TEST(ActualTest, expectMatchReturnsTrueOnMatch)
{
    bool result = expect(value).match(is(value));
    CHECK_TRUE(result);
}

TEST(ActualTest, expectMatchReturnsFalseOnMismatch)
{
    bool result = expect(value).match(is(value + 1));
    CHECK_FALSE(result);
}


#include <CppUTest/TestHarness.h>
#include "matcher/CompareMatcher.h"
#include "matcher/CombinationMatcher.h"
#include "Helper.h"

using namespace matcher;

TEST_GROUP(CombinationMatcherTest)
{
    const int value = 3;
};

TEST(CombinationMatcherTest, both)
{
    CHECK_MATCHER(value, both(gt(1), lt(5)), true, "both");
    CHECK_MATCHER(value, both(gt(4), lt(5)), false, "both");
    CHECK_MATCHER(value, both(gt(1), lt(2)), false, "both");
}

TEST(CombinationMatcherTest, negate)
{
    CHECK_MATCHER(value, negate(gt(1)), false, "negate");
    CHECK_MATCHER(value, negate(gt(4)), true, "negate");
}

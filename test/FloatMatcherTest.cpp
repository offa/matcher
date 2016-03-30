#include "matcher/FloatMatcher.h"
#include "Helper.h"
#include <CppUTest/TestHarness.h>

using namespace matcher;

TEST_GROUP(FloatMatcherTest)
{
};

TEST(FloatMatcherTest, doubleNear)
{
    CHECK_MATCHER(3.0, doubleNear(3.0, 0.01), true, "doubleNear");
    CHECK_MATCHER(3.0, doubleNear(3.003, 0.01), true, "doubleNear");
    CHECK_MATCHER(3.0, doubleNear(3.1, 0.01), false, "doubleNear");
    CHECK_MATCHER(3.0, doubleNear(3.05, 0.01), false, "doubleNear");
}

TEST(FloatMatcherTest, doubleNearWithFloat)
{
    CHECK_MATCHER(3.0f, doubleNear(3.0f, 0.01f), true, "doubleNear");
    CHECK_MATCHER(3.0f, doubleNear(3.003f, 0.01f), true, "doubleNear");
    CHECK_MATCHER(3.0f, doubleNear(3.1f, 0.01f), false, "doubleNear");
    CHECK_MATCHER(3.0f, doubleNear(3.05f, 0.01f), false, "doubleNear");
}

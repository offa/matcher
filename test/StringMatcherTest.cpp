#include "matcher/StringMatcher.h"
#include "Helper.h"
#include <CppUTest/TestHarness.h>

using namespace matcher;

TEST_GROUP(StringMatcherTest)
{
    const std::string str = "abc";
};

TEST(StringMatcherTest, eq)
{
    CHECK_MATCHER(str, strEq(str), true, "strEq");
    CHECK_MATCHER(str, strEq(std::string("aBc")), false, "strEq");
}

TEST(StringMatcherTest, strLength)
{
    CHECK_MATCHER(str, strLength(3), true, "strLength");
    CHECK_MATCHER(str, strLength(4), false, "strLength");
}

TEST(StringMatcherTest, lengthIfEmpty)
{
    CHECK_MATCHER(std::string(""), strLength(0), true, "strLength");
    CHECK_MATCHER(std::string(""), strLength(1), false, "strLength");
}

TEST(StringMatcherTest, empty)
{
    CHECK_MATCHER(std::string(""), strEmpty(), true, "strEmpty");
    CHECK_MATCHER(str, strEmpty(), false, "strEmpty");
}

TEST(StringMatcherTest, notEmpty)
{
    CHECK_MATCHER(str, strNotEmpty(), true, "strNotEmpty");
    CHECK_MATCHER(std::string(""), strNotEmpty(), false, "strNotEmpty");
}

TEST(StringMatcherTest, strStartsWith)
{
    CHECK_MATCHER(str, strStartsWith(std::string("a")), true, "strStartsWith");
    CHECK_MATCHER(str, strStartsWith(std::string("aB")), false, "strStartsWith");
}

TEST(StringMatcherTest, strEndsWIth)
{
    CHECK_MATCHER(str, strEndsWith(std::string("c")), true, "strEndsWith");
    CHECK_MATCHER(str, strEndsWith(std::string("Bc")), false, "strEndsWith");
}


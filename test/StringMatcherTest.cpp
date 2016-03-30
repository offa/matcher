/*
 * Matcher - C++ Matchers.
 * Copyright (C) 2016  offa
 * 
 * This file is part of Matcher.
 *
 * Matcher is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Matcher is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Matcher.  If not, see <http://www.gnu.org/licenses/>.
 */

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


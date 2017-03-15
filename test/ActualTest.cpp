/*
 * Matcher - C++ Matchers.
 * Copyright (C) 2016-2017  offa
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
    const auto result = expect(value).that(is(value));
    CHECK_TRUE(result.getResult());
}

TEST(ActualTest, expectThatReturnsFalseOnMismatch)
{
    const auto result = expect(value).that(is(value + 1));
    CHECK_FALSE(result.getResult());
}

TEST(ActualTest, expectMatchReturnsTrueOnMatch)
{
    const bool result = expect(value).match(is(value));
    CHECK_TRUE(result);
}

TEST(ActualTest, expectMatchReturnsFalseOnMismatch)
{
    const bool result = expect(value).match(is(value + 1));
    CHECK_FALSE(result);
}

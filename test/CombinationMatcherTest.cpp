/*
 * Matcher - C++ Matchers.
 * Copyright (C) 2016-2019  offa
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

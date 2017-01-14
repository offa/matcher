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

#include "matcher/DoubleMatcher.h"
#include "Helper.h"
#include <CppUTest/TestHarness.h>

using namespace matcher;

TEST_GROUP(DoubleMatcherTest)
{
};

TEST(DoubleMatcherTest, doubleNear)
{
    CHECK_MATCHER(3.0, doubleNear(3.0, 0.01), true, "doubleNear");
    CHECK_MATCHER(3.0, doubleNear(3.003, 0.01), true, "doubleNear");
    CHECK_MATCHER(3.0, doubleNear(3.1, 0.01), false, "doubleNear");
    CHECK_MATCHER(3.0, doubleNear(3.05, 0.01), false, "doubleNear");
}

TEST(DoubleMatcherTest, doubleNearWithFloat)
{
    CHECK_MATCHER(3.0f, doubleNear(3.0f, 0.01f), true, "doubleNear");
    CHECK_MATCHER(3.0f, doubleNear(3.003f, 0.01f), true, "doubleNear");
    CHECK_MATCHER(3.0f, doubleNear(3.1f, 0.01f), false, "doubleNear");
    CHECK_MATCHER(3.0f, doubleNear(3.05f, 0.01f), false, "doubleNear");
}

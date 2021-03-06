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

#include "matcher/MatchResult.h"
#include <CppUTest/TestHarness.h>

using namespace matcher;

TEST_GROUP(MatchResultTest)
{
};

TEST(MatchResultTest, resultValues)
{
    const std::string descr = "abc";
    MatchResult res(true, descr);
    CHECK_TRUE(res.getResult());
    CHECK_EQUAL(descr, res.getDescription());
}


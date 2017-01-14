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

#pragma once

#include "matcher/MatchResult.h"
#include <CppUTest/TestHarness.h>

template<class T, class Matcher>
void checkMatcher(const T& cmp, const Matcher& matcher, bool expectedResult,
                    const char* expMsg, const char* file, size_t line)
{
    matcher::MatchResult result = matcher.operator()(cmp);

    CHECK_EQUAL_LOCATION(expectedResult, result.getResult(), nullptr, file, line);
    STRCMP_EQUAL_LOCATION(expMsg, result.getDescription().c_str(), nullptr, file, line);
}


#define CHECK_MATCHER(value, matcher, expectedResult, msg)   \
            checkMatcher(value, matcher, expectedResult, msg, __FILE__, __LINE__)



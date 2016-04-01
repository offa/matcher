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

#ifndef HELPER_H
#define HELPER_H

#include <CppUTest/TestHarness.h>

template<class T, class Matcher>
void checkMatcher(const T& cmp, const Matcher& matcher, bool expectedResult, 
                    const char* expMsg, const char* file, size_t line)
{
    bool result;
    std::string msg;
    std::tie(result, msg) = matcher.operator()(cmp);

    CHECK_EQUAL_LOCATION(expectedResult, result, nullptr, file, line);
    STRCMP_EQUAL_LOCATION(expMsg, msg.c_str(), nullptr, file, line);
}


#define CHECK_MATCHER(value, matcher, expectedResult, msg)   \
            checkMatcher(value, matcher, expectedResult, msg, __FILE__, __LINE__)



#endif /* HELPER_H */


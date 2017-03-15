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

#include "matcher/ContainerMatcher.h"
#include "Helper.h"
#include <vector>
#include <array>
#include <CppUTest/TestHarness.h>

using namespace matcher;

TEST_GROUP(ContainerMatcherTest)
{
    void setup() override
    {
        vec = std::vector<int>{1, 2, 3};
        arr = std::array<int, size>{{1, 2, 3}};
        str = "abc";
    }


    static constexpr size_t size = 3;
    std::vector<int> vec;
    std::array<int, size> arr;
    std::string str;
};

TEST(ContainerMatcherTest, containsElementFound)
{
    CHECK_MATCHER(vec, contains(3), true, "contains");
    CHECK_MATCHER(arr, contains(3), true, "contains");
    CHECK_MATCHER(str, contains('c'), true, "contains");
}

TEST(ContainerMatcherTest, containsElementNotFound)
{
    CHECK_MATCHER(vec, contains(4), false, "contains");
    CHECK_MATCHER(arr, contains(4), false, "contains");
    CHECK_MATCHER(str, contains('x'), false, "contains");
}

TEST(ContainerMatcherTest, isEmpty)
{
    CHECK_MATCHER(vec, isEmpty(), false, "isEmpty");
    CHECK_MATCHER(arr, isEmpty(), false, "isEmpty");
    CHECK_MATCHER(str, isEmpty(), false, "isEmpty");
    vec.clear();
    str.clear();
    CHECK_MATCHER(vec, isEmpty(), true, "isEmpty");
    CHECK_MATCHER(str, isEmpty(), true, "isEmpty");
}

TEST(ContainerMatcherTest, isNotEmpty)
{
    CHECK_MATCHER(vec, isNotEmpty(), true, "isNotEmpty");
    CHECK_MATCHER(arr, isNotEmpty(), true, "isNotEmpty");
    CHECK_MATCHER(str, isNotEmpty(), true, "isNotEmpty");
    vec.clear();
    str.clear();
    CHECK_MATCHER(vec, isNotEmpty(), false, "isNotEmpty");
    CHECK_MATCHER(str, isNotEmpty(), false, "isNotEmpty");
}

TEST(ContainerMatcherTest, sizeIs)
{
    CHECK_MATCHER(vec, sizeIs(vec.size()), true, "sizeIs");
    CHECK_MATCHER(vec, sizeIs(vec.size() + 1), false, "sizeIs");

    CHECK_MATCHER(arr, sizeIs(vec.size()), true, "sizeIs");
    CHECK_MATCHER(str, sizeIs(vec.size() + 1), false, "sizeIs");

    CHECK_MATCHER(str, sizeIs(vec.size()), true, "sizeIs");
    CHECK_MATCHER(arr, sizeIs(vec.size() + 1), false, "sizeIs");

    vec.clear();
    str.clear();
    CHECK_MATCHER(vec, sizeIs(0), true, "sizeIs");
    CHECK_MATCHER(str, sizeIs(0), true, "sizeIs");
}

TEST(ContainerMatcherTest, eachIs)
{
    CHECK_MATCHER(vec, eachIs(3), false, "eachIs");
    CHECK_MATCHER(arr, eachIs(3), false, "eachIs");
    CHECK_MATCHER(str, eachIs(3), false, "eachIs");
    vec = std::vector<int>(3, 3);
    arr = std::array<int, size>{{3, 3, 3}};
    str = "yyy";
    CHECK_MATCHER(vec, eachIs(3), true, "eachIs");
    CHECK_MATCHER(str, eachIs('y'), true, "eachIs");
}

TEST(ContainerMatcherTest, elementsAre)
{
    CHECK_MATCHER(vec, elementsAre({1, 2, 3}), true, "elementsAre");
    CHECK_MATCHER(vec, elementsAre({1, 2, 4}), false, "elementsAre");

    CHECK_MATCHER(arr, elementsAre({1, 2, 3}), true, "elementsAre");
    CHECK_MATCHER(arr, elementsAre({1, 2, 4}), false, "elementsAre");

    CHECK_MATCHER(str, elementsAre({'a', 'b', 'c'}), true, "elementsAre");
    CHECK_MATCHER(str, elementsAre({'a', 'b', 'x'}), false, "elementsAre");
}

TEST(ContainerMatcherTest, elementsAreUnordered)
{
    CHECK_MATCHER(vec, elementsAreUnordered({3, 1, 2}), true, "elementsAreUnordered");
    CHECK_MATCHER(vec, elementsAreUnordered({3, 1, 4}), false, "elementsAreUnordered");

    CHECK_MATCHER(arr, elementsAreUnordered({3, 1, 2}), true, "elementsAreUnordered");
    CHECK_MATCHER(arr, elementsAreUnordered({3, 1, 4}), false, "elementsAreUnordered");

    CHECK_MATCHER(str, elementsAreUnordered({'b', 'a', 'c'}), true, "elementsAreUnordered");
    CHECK_MATCHER(str, elementsAreUnordered({'b', 'a', 'x'}), false, "elementsAreUnordered");
}

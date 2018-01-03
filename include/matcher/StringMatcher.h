/*
 * Matcher - C++ Matchers.
 * Copyright (C) 2016-2018  offa
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

#include "MatcherBase.h"
#include <algorithm>
#include <string>

namespace matcher
{
    namespace internal
    {
        template<class Expected>
        struct StrEq : protected MatcherBase<Expected>
        {
            using MatcherBase<Expected>::MatcherBase;

            template<class Actual>
            MatchResult operator()(const Actual& actual) const
            {
                const bool result = std::equal(std::begin(this->m_expected),
                                                std::end(this->m_expected),
                                                std::begin(actual));
                return MatchResult(result, this->m_description);
            }
        };

        template<class Expected>
        struct StrLength : protected MatcherBase<Expected>
        {
            using MatcherBase<Expected>::MatcherBase;

            template<class Actual>
            MatchResult operator()(const Actual& actual) const
            {
                const auto expSize = static_cast<typename Actual::size_type>(this->m_expected);
                const bool result = (actual.length() == expSize);
                return MatchResult(result, this->m_description);
            }
        };


        template<class Expected>
        struct StrStartsWith : protected MatcherBase<Expected>
        {
            using MatcherBase<Expected>::MatcherBase;

            template<class Actual>
            MatchResult operator()(const Actual& actual) const
            {
                const auto itrPair = std::mismatch(std::begin(actual),
                                                    std::end(actual),
                                                    std::begin(this->m_expected));
                const bool result = ( itrPair.second == std::end(this->m_expected) );
                return MatchResult(result, this->m_description);
            }
        };


        template<class Expected>
        struct StrEndsWith : protected MatcherBase<Expected>
        {
            using MatcherBase<Expected>::MatcherBase;

            template<class Actual>
            MatchResult operator()(const Actual& actual) const
            {
                const auto itrPair = std::mismatch(actual.rbegin(),
                                                    actual.rend(),
                                                    this->m_expected.rbegin());
                const bool result = ( itrPair.second == this->m_expected.rend() );
                return MatchResult(result, this->m_description);
            }
        };


        struct StrEmpty : protected MatcherBase<void>
        {
            using MatcherBase<void>::MatcherBase;

            template<class Actual>
            MatchResult operator()(const Actual& actual) const
            {
                return MatchResult(actual.empty(), this->m_description);
            }
        };


        struct StrNotEmpty : protected MatcherBase<void>
        {
            using MatcherBase<void>::MatcherBase;

            template<class Actual>
            MatchResult operator()(const Actual& actual) const
            {
                return MatchResult((actual.empty() == false), this->m_description);
            }
        };
    }


    template<class Expected>
    internal::StrEq<Expected> strEq(const Expected& expected)
    {
        return internal::StrEq<Expected>(expected, "strEq");
    }

    template<class Expected>
    internal::StrLength<Expected> strLength(const Expected& expected)
    {
        return internal::StrLength<Expected>(expected, "strLength");
    }

    template<>
    internal::StrLength<size_t> strLength(const size_t& expected)
    {
        return internal::StrLength<size_t>(expected, "strLength");
    }

    template<class Expected>
    internal::StrStartsWith<Expected> strStartsWith(const Expected& expected)
    {
        return internal::StrStartsWith<Expected>(expected, "strStartsWith");
    }

    template<class Expected>
    internal::StrEndsWith<Expected> strEndsWith(const Expected& expected)
    {
        return internal::StrEndsWith<Expected>(expected, "strEndsWith");
    }

    inline internal::StrEmpty strEmpty()
    {
        return internal::StrEmpty("strEmpty");
    }

    inline internal::StrNotEmpty strNotEmpty()
    {
        return internal::StrNotEmpty("strNotEmpty");
    }
}


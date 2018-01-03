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

#include <tuple>
#include "MatcherBase.h"

namespace matcher
{
    namespace internal
    {
        template<class Expected1, class Expected2>
        struct Both : protected MatcherBase<Expected1>
        {
            Both(const Expected1& expected1, const Expected2& expected2, const std::string& description)
                            : MatcherBase<Expected1>(expected1, description), m_expected2(expected2)
            {
            }

            template<class Actual>
            MatchResult operator()(const Actual& actual) const
            {
                const bool result = ( this->m_expected(actual).getResult()
                                    && m_expected2(actual).getResult() );
                return MatchResult(result, this->m_description);
            }

        protected:

            const Expected2& m_expected2;
        };


        template<class Expected>
        struct Negate : protected MatcherBase<Expected>
        {
            using MatcherBase<Expected>::MatcherBase;

            template<class Actual>
            MatchResult operator()(const Actual& actual) const
            {
                const bool result = !this->m_expected(actual).getResult();
                return MatchResult(result, this->m_description);
            }
        };
    }


    template<class Expected1, class Expected2>
    internal::Both<Expected1, Expected2> both(const Expected1& expected1, const Expected2& expected2)
    {
        return internal::Both<Expected1, Expected2>(expected1, expected2, "both");
    }


    template<class Expected>
    internal::Negate<Expected> negate(const Expected& expected)
    {
        return internal::Negate<Expected>(expected, "negate");
    }
}


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

#pragma once

#include "MatcherBase.h"

namespace matcher
{
    namespace internal
    {
        template<class Expected>
        struct Eq : protected MatcherBase<Expected>
        {
            using MatcherBase<Expected>::MatcherBase;

            template<class Actual>
            MatchResult operator()(const Actual& actual) const
            {
                return MatchResult(( actual == this->m_expected ), this->m_description);
            }
        };


        template<class Expected>
        struct Ne : protected MatcherBase<Expected>
        {
            using MatcherBase<Expected>::MatcherBase;

            template<class Actual>
            MatchResult operator()(const Actual& actual) const
            {
                return MatchResult(( actual != this->m_expected ), this->m_description);
            }
        };


        template<class Expected>
        struct Lt : protected MatcherBase<Expected>
        {
            using MatcherBase<Expected>::MatcherBase;

            template<class Actual>
            MatchResult operator()(const Actual& actual) const
            {
                return MatchResult(( actual < this->m_expected ), this->m_description);
            }
        };


        template<class Expected>
        struct Le : protected MatcherBase<Expected>
        {
            using MatcherBase<Expected>::MatcherBase;

            template<class Actual>
            MatchResult operator()(const Actual& actual) const
            {
                return MatchResult(( actual <= this->m_expected ), this->m_description);
            }
        };


        template<class Expected>
        struct Gt : protected MatcherBase<Expected>
        {
            using MatcherBase<Expected>::MatcherBase;

            template<class Actual>
            MatchResult operator()(const Actual& actual) const
            {
                return MatchResult(( actual > this->m_expected ), this->m_description);
            }
        };


        template<class Expected>
        struct Ge : protected MatcherBase<Expected>
        {
            using MatcherBase<Expected>::MatcherBase;

            template<class Actual>
            MatchResult operator()(const Actual& actual) const
            {
                return MatchResult(( actual >= this->m_expected ), this->m_description);
            }
        };
    }


    template<class Expected>
    internal::Eq<Expected> is(const Expected& expected)
    {
        return internal::Eq<Expected>(expected, "is");
    }


    template<class Expected>
    internal::Ne<Expected> isNot(const Expected& expected)
    {
        return internal::Ne<Expected>(expected, "isNot");
    }


    template<class Expected>
    internal::Eq<Expected> eq(const Expected& expected)
    {
        return internal::Eq<Expected>(expected, "eq");
    }


    template<class Expected>
    internal::Ne<Expected> ne(const Expected& expected)
    {
        return internal::Ne<Expected>(expected, "ne");
    }


    template<class Expected>
    internal::Lt<Expected> lt(const Expected& expected)
    {
        return internal::Lt<Expected>(expected, "lt");
    }


    template<class Expected>
    internal::Le<Expected> le(const Expected& expected)
    {
        return internal::Le<Expected>(expected, "le");
    }


    template<class Expected>
    internal::Gt<Expected> gt(const Expected& expected)
    {
        return internal::Gt<Expected>(expected, "gt");
    }


    template<class Expected>
    internal::Ge<Expected> ge(const Expected& expected)
    {
        return internal::Ge<Expected>(expected, "ge");
    }

}


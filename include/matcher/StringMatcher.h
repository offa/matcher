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

#ifndef STRINGMATCHER_H
#define STRINGMATCHER_H

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
            std::tuple<bool, std::string> operator()(const Actual& actual) const
            {
                bool result = std::equal(std::begin(this->m_expected), 
                                        std::end(this->m_expected), 
                                        std::begin(actual));
                return std::make_tuple(result, this->m_descr);
            }
        };

        template<class Expected>
        struct StrLength : protected MatcherBase<Expected>
        {
            using MatcherBase<Expected>::MatcherBase;

            template<class Actual>
            std::tuple<bool, std::string> operator()(const Actual& actual) const
            {
                auto expSize = static_cast<typename Actual::size_type>(this->m_expected);
                bool result = (actual.length() == expSize);
                return std::make_tuple(result, this->m_descr);
            }
        };

        
        template<class Expected>
        struct StrStartsWith : protected MatcherBase<Expected>
        {
            using MatcherBase<Expected>::MatcherBase;

            template<class Actual>
            std::tuple<bool, std::string> operator()(const Actual& actual) const
            {
                auto itrPair = std::mismatch(std::begin(actual), 
                                            std::end(actual), 
                                            std::begin(this->m_expected));
                bool result = ( itrPair.second == std::end(this->m_expected) );
                return std::make_tuple(result, this->m_descr);
            }
        };

        
        template<class Expected>
        struct StrEndsWith : protected MatcherBase<Expected>
        {
            using MatcherBase<Expected>::MatcherBase;

            template<class Actual>
            std::tuple<bool, std::string> operator()(const Actual& actual) const
            {
                auto itrPair = std::mismatch(actual.rbegin(), 
                                            actual.rend(), 
                                            this->m_expected.rbegin());
                bool result = ( itrPair.second == this->m_expected.rend() );
                return std::make_tuple(result, this->m_descr);
            }
        };

        
        struct StrEmpty : protected MatcherBase<void>
        {
            using MatcherBase<void>::MatcherBase;

            template<class Actual>
            std::tuple<bool, std::string> operator()(const Actual& actual) const
            {
                return std::make_tuple(actual.empty(), this->m_descr);
            }
        };

        
        struct StrNotEmpty : protected MatcherBase<void>
        {
            using MatcherBase<void>::MatcherBase;

            template<class Actual>
            std::tuple<bool, std::string> operator()(const Actual& actual) const
            {
                return std::make_tuple((actual.empty() == false), this->m_descr);
            }
        };
    }

    template<class Expected>
    internal::StrEq<Expected> strEq(const Expected& e)
    {
        return internal::StrEq<Expected>(e, "strEq");
    }

    template<class Expected>
    internal::StrEq<Expected> strEqIgnoreCase(const Expected& e)
    {
        auto lowered = e;
        std::transform(std::begin(e), std::end(e), std::begin(lowered), ::tolower);
        return internal::StrEq<Expected>(lowered, "strEqIgnoreCase");
    }

    template<class Expected>
    internal::StrLength<Expected> strLength(const Expected& e)
    {
        return internal::StrLength<Expected>(e, "strLength");
    }

    template<>
    internal::StrLength<size_t> strLength(const size_t& e)
    {
        return internal::StrLength<size_t>(e, "strLength");
    }

    template<class Expected>
    internal::StrStartsWith<Expected> strStartsWith(const Expected& e)
    {
        return internal::StrStartsWith<Expected>(e, "strStartsWith");
    }

    template<class Expected>
    internal::StrStartsWith<Expected> strStartsWithIgnoreCase(const Expected& e)
    {
        auto lowered = e;
        std::transform(std::begin(e), std::end(e), std::begin(lowered), ::tolower);
        return internal::StrStartsWith<Expected>(lowered, "strStartsWithIgnoreCase");
    }

    template<class Expected>
    internal::StrEndsWith<Expected> strEndsWith(const Expected& e)
    {
        return internal::StrEndsWith<Expected>(e, "strEndsWith");
    }

    template<class Expected>
    internal::StrEndsWith<Expected> strEndsWithIgnoreCase(const Expected& e)
    {
        auto lowered = e;
        std::transform(std::begin(e), std::end(e), std::begin(lowered), ::tolower);
        return internal::StrEndsWith<Expected>(lowered, "strEndsWithIgnoreCase");
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

#endif /* STRINGMATCHER_H */


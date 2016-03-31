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
                bool result = std::equal(std::begin(this->m_expected), std::end(this->m_expected), std::begin(actual));
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
                bool result = ( actual.length() == static_cast<typename Actual::size_type>(this->m_expected) );
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
                bool result = std::mismatch(actual.begin(), actual.end(), this->m_expected.begin()).second == this->m_expected.end();
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
                bool result = std::mismatch(actual.rbegin(), actual.rend(), this->m_expected.rbegin()).second == this->m_expected.rend();
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
                return std::make_tuple(( actual.empty() == false ), this->m_descr);
            }
        };
    }

    template<class Expected>
    internal::StrEq<Expected> strEq(const Expected& e)
    {
        return internal::StrEq<Expected>(e, "strEq");
    }

    
    inline internal::StrLength<size_t> strLength(size_t e)
    {
        return internal::StrLength<size_t>(e, "strLength");
    }
    
    
    template<class Expected>
    internal::StrStartsWith<Expected> strStartsWith(const Expected& e)
    {
        return internal::StrStartsWith<Expected>(e, "strStartsWith");
    }
    
    
    template<class Expected>
    internal::StrEndsWith<Expected> strEndsWith(const Expected& e)
    {
        return internal::StrEndsWith<Expected>(e, "strEndsWith");
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


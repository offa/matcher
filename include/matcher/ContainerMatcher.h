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

#ifndef CONTAINERMATCHER_H
#define CONTAINERMATCHER_H

#include "MatcherBase.h"
#include <algorithm>
#include <functional>

namespace matcher
{
    namespace internal
    {
        template<class Expected>
        struct Contains : protected MatcherBase<Expected>
        {
            using MatcherBase<Expected>::MatcherBase;

            template<class Actual>
            std::tuple<bool, std::string> operator()(const Actual& actual) const
            {
                auto itr = std::find(std::begin(actual), std::end(actual), this->m_expected);
                bool result = ( itr != std::end(actual) );
                return std::make_tuple(result, this->m_descr);
            }
        };

        
        struct IsEmpty : protected MatcherBase<void>
        {
            using MatcherBase<void>::MatcherBase;
            
            template<class Actual>
            std::tuple<bool, std::string> operator()(const Actual& actual) const
            {
                bool result = actual.empty();
                return std::make_tuple(result, this->m_descr);
            }
        };

        
        struct IsNotEmpty : protected MatcherBase<void>
        {
            using MatcherBase<void>::MatcherBase;
            
            template<class Actual>
            std::tuple<bool, std::string> operator()(const Actual& actual) const
            {
                bool result = actual.empty();
                return std::make_tuple(!result, this->m_descr);
            }
        };

        
        template<class Expected>
        struct SizeIs : protected MatcherBase<Expected>
        {
            using MatcherBase<Expected>::MatcherBase;
            
            template<class Actual>
            std::tuple<bool, std::string> operator()(const Actual& actual) const
            {
                auto expSize = static_cast<typename Actual::size_type>(this->m_expected);
                bool result = ( actual.size() == expSize );
                return std::make_tuple(result, this->m_descr);
            }
        };

        
        template<class Expected>
        struct EachIs : protected MatcherBase<Expected>
        {
            using MatcherBase<Expected>::MatcherBase;
            
            template<class Actual>
            std::tuple<bool, std::string> operator()(const Actual& actual) const
            {
                bool result = std::all_of(std::begin(actual),
                                        std::end(actual), 
                                        [&](const Expected& value)
                                            { return this->m_expected == value; });
                return std::make_tuple(result, this->m_descr);
            }
        };

        
        template<class Expected>
        struct ElementsAre : protected MatcherBase<std::initializer_list<Expected>>
        {
            using MatcherBase<std::initializer_list<Expected>>::MatcherBase;
            
            template<class Actual>
            std::tuple<bool, std::string> operator()(const Actual& actual) const
            {
                bool result = std::equal(std::begin(actual), 
                                        std::end(actual), 
                                        std::begin(this->m_expected));
                return std::make_tuple(result, this->m_descr);
            }
        };

        
        template<class Expected>
        struct ElementsAreUnordered : protected MatcherBase<std::initializer_list<Expected>>
        {
            using MatcherBase<std::initializer_list<Expected>>::MatcherBase;
            
            template<class Actual>
            std::tuple<bool, std::string> operator()(const Actual& actual) const
            {
                bool result = std::is_permutation(std::begin(actual), 
                                                std::end(actual), 
                                                std::begin(this->m_expected));
                return std::make_tuple(result, this->m_descr);
            }
        };
    }

    
    template<class Expected>
    internal::Contains<Expected> contains(const Expected& e)
    {
        return internal::Contains<Expected>(e, "contains");
    }

    
    inline internal::IsEmpty isEmpty()
    {
        return internal::IsEmpty("isEmpty");
    }
    
    
    inline internal::IsNotEmpty isNotEmpty()
    {
        return internal::IsNotEmpty("isNotEmpty");
    }

    
    template<class Expected>
    internal::SizeIs<Expected> sizeIs(const Expected& e)
    {
        return internal::SizeIs<Expected>(e, "sizeIs");
    }
    
    template<>
    internal::SizeIs<size_t> sizeIs(const size_t& e)
    {
        return internal::SizeIs<size_t>(e, "sizeIs");
    }

    
    template<class Expected>
    internal::EachIs<Expected> eachIs(const Expected& e)
    {
        return internal::EachIs<Expected>(e, "eachIs");
    }
    
    
    template<class Expected>
    internal::ElementsAre<Expected> elementsAre(const std::initializer_list<Expected>& e)
    {
        return internal::ElementsAre<Expected>(e, "elementsAre");
    }
    
    
    template<class Expected>
    internal::ElementsAreUnordered<Expected> elementsAreUnordered(const std::initializer_list<Expected>& e)
    {
        return internal::ElementsAreUnordered<Expected>(e, "elementsAreUnordered");
    }
}


#endif /* CONTAINERMATCHER_H */



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
                bool result = std::find(std::begin(actual), std::end(actual), this->m_expected) != std::end(actual);
                return std::make_tuple(result, "contains");
            }
        };

        
        struct IsEmpty : protected MatcherBase<void>
        {
            template<class Actual>
            std::tuple<bool, std::string> operator()(const Actual& actual) const
            {
                bool result = actual.empty();
                return std::make_tuple(result, "isEmpty");
            }
        };

        
        struct IsNotEmpty : protected MatcherBase<void>
        {
            template<class Actual>
            std::tuple<bool, std::string> operator()(const Actual& actual) const
            {
                bool result = actual.empty();
                return std::make_tuple(!result, "isNotEmpty");
            }
        };

        
        template<class Expected>
        struct SizeIs : protected MatcherBase<Expected>
        {
            using MatcherBase<Expected>::MatcherBase;
            
            template<class Actual>
            std::tuple<bool, std::string> operator()(const Actual& actual) const
            {
                bool result = ( actual.size() == static_cast<typename Actual::size_type>(this->m_expected) );
                return std::make_tuple(result, "sizeIs");
            }
        };

        
        template<class Expected>
        struct EachIs : protected MatcherBase<Expected>
        {
            using MatcherBase<Expected>::MatcherBase;
            
            template<class Actual>
            std::tuple<bool, std::string> operator()(const Actual& actual) const
            {
                bool result = std::all_of(std::begin(actual), std::end(actual), [&](const Expected& value) { return this->m_expected == value; });
                return std::make_tuple(result, "eachIs");
            }
        };

        
        template<class Expected>
        struct ElementsAre : protected MatcherBase<std::initializer_list<Expected>>
        {
            using MatcherBase<std::initializer_list<Expected>>::MatcherBase;
            
            template<class Actual>
            std::tuple<bool, std::string> operator()(const Actual& actual) const
            {
                bool result = std::equal(std::begin(actual), std::end(actual), std::begin(this->m_expected));
                return std::make_tuple(result, "elementsAre");
            }
        };

        
        template<class Expected>
        struct ElementsAreUnordered : protected MatcherBase<std::initializer_list<Expected>>
        {
            using MatcherBase<std::initializer_list<Expected>>::MatcherBase;
            
            template<class Actual>
            std::tuple<bool, std::string> operator()(const Actual& actual) const
            {
                bool result = std::is_permutation(std::begin(actual), std::end(actual), std::begin(this->m_expected));
                return std::make_tuple(result, "elementsAreUnordered");
            }
        };
    }

    
    template<class Expected>
    internal::Contains<Expected> contains(const Expected& e)
    {
        return internal::Contains<Expected>(e);
    }

    
    inline internal::IsEmpty isEmpty()
    {
        return internal::IsEmpty();
    }
    
    
    inline internal::IsNotEmpty isNotEmpty()
    {
        return internal::IsNotEmpty();
    }

    
    template<class Expected>
    internal::SizeIs<Expected> sizeIs(const Expected& e)
    {
        return internal::SizeIs<Expected>(e);
    }
    
    template<>
    internal::SizeIs<size_t> sizeIs(const size_t& e)
    {
        return internal::SizeIs<size_t>(e);
    }

    
    template<class Expected>
    internal::EachIs<Expected> eachIs(const Expected& e)
    {
        return internal::EachIs<Expected>(e);
    }
    
    
    template<class Expected>
    internal::ElementsAre<Expected> elementsAre(const std::initializer_list<Expected>& e)
    {
        return internal::ElementsAre<Expected>(e);
    }
    
    
    template<class Expected>
    internal::ElementsAreUnordered<Expected> elementsAreUnordered(const std::initializer_list<Expected>& e)
    {
        return internal::ElementsAreUnordered<Expected>(e);
    }
}


#endif /* CONTAINERMATCHER_H */


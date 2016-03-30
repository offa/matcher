
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
                bool result = ( actual.size() == static_cast<typename Actual::size_type>(this->m_expected) );
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
                bool result = std::all_of(std::begin(actual), std::end(actual), [&](const Expected& value) { return this->m_expected == value; });
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
                bool result = std::equal(std::begin(actual), std::end(actual), std::begin(this->m_expected));
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
                bool result = std::is_permutation(std::begin(actual), std::end(actual), std::begin(this->m_expected));
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


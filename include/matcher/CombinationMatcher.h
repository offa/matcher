#ifndef COMBINATIONMATCHER_H
#define COMBINATIONMATCHER_H

#include <tuple>
#include "MatcherBase.h"

namespace matcher
{
    namespace internal
    {
        template<class Expected1, class Expected2>
        struct Both : protected MatcherBase<Expected1>
        {
            Both(const Expected1& e1, const Expected2& e2) : MatcherBase<Expected1>(e1), m_expected2(e2)
            {
            }

            template<class Actual>
            std::tuple<bool, std::string> operator()(const Actual& actual) const
            {
                bool result = std::get<0>(this->m_expected(actual)) && std::get<0>(m_expected2(actual));
                return std::make_tuple(result, "both");
            }
            
            const Expected2& m_expected2;
        };
        
        
        template<class Expected>
        struct Negate : protected MatcherBase<Expected>
        {
            using MatcherBase<Expected>::MatcherBase;
            
            template<class Actual>
            std::tuple<bool, std::string> operator()(const Actual& actual) const
            {
                bool result = !std::get<0>(this->m_expected(actual));
                return std::make_tuple(result, "negate");
            }
        };
    }
    
    
    template<class Expected1, class Expected2>
    internal::Both<Expected1, Expected2> both(const Expected1& e1, const Expected2& e2)
    {
        return internal::Both<Expected1, Expected2>(e1, e2);
    }
    
    
    template<class Expected>
    internal::Negate<Expected> negate(const Expected& e)
    {
        return internal::Negate<Expected>(e);
    }
}


#endif /* COMBINATIONMATCHER_H */


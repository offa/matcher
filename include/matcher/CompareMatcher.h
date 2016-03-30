
#ifndef COMPAREMATCHER_H
#define COMPAREMATCHER_H

#include "MatcherBase.h"

namespace matcher
{
    namespace internal
    {
        template<class Expected>
        struct Is : protected MatcherBase<Expected>
        {
            using MatcherBase<Expected>::MatcherBase;

            template<class Actual>
            std::tuple<bool, std::string> operator()(const Actual& actual) const
            {
                return std::make_tuple(( actual == this->m_expected ), "is");
            }
        };
        
        
        template<class Expected>
        struct Eq : protected MatcherBase<Expected>
        {
            using MatcherBase<Expected>::MatcherBase;

            template<class Actual>
            std::tuple<bool, std::string> operator()(const Actual& actual) const
            {
                return std::make_tuple(( actual == this->m_expected ), "eq");
            }
        };

        
        template<class Expected>
        struct Ne : protected MatcherBase<Expected>
        {
            using MatcherBase<Expected>::MatcherBase;

            template<class Actual>
            std::tuple<bool, std::string> operator()(const Actual& actual) const
            {
                return std::make_tuple(( actual != this->m_expected ), "ne");
            }
        };

        
        template<class Expected>
        struct Lt : protected MatcherBase<Expected>
        {
            using MatcherBase<Expected>::MatcherBase;

            template<class Actual>
            std::tuple<bool, std::string> operator()(const Actual& actual) const
            {
                return std::make_tuple(( actual < this->m_expected ), "lt");
            }
        };

        
        template<class Expected>
        struct Le : protected MatcherBase<Expected>
        {
            using MatcherBase<Expected>::MatcherBase;

            template<class Actual>
            std::tuple<bool, std::string> operator()(const Actual& actual) const
            {
                return std::make_tuple(( actual <= this->m_expected ), "le");
            }
        };

        
        template<class Expected>
        struct Gt : protected MatcherBase<Expected>
        {
            using MatcherBase<Expected>::MatcherBase;

            template<class Actual>
            std::tuple<bool, std::string> operator()(const Actual& actual) const
            {
                return std::make_tuple(( actual > this->m_expected ), "gt");
            }
        };

        
        template<class Expected>
        struct Ge : protected MatcherBase<Expected>
        {
            using MatcherBase<Expected>::MatcherBase;

            template<class Actual>
            std::tuple<bool, std::string> operator()(const Actual& actual) const
            {
                return std::make_tuple(( actual >= this->m_expected ), "ge");
            }
        };
    }
    
    
    template<class Expected>
    internal::Is<Expected> is(const Expected& e)
    {
        return internal::Is<Expected>(e);
    }

    
    template<class Expected>
    internal::Eq<Expected> eq(const Expected& e)
    {
        return internal::Eq<Expected>(e);
    }
    
    
    template<class Expected>
    internal::Ne<Expected> ne(const Expected& e)
    {
        return internal::Ne<Expected>(e);
    }
    
    
    template<class Expected>
    internal::Lt<Expected> lt(const Expected& e)
    {
        return internal::Lt<Expected>(e);
    }
    
    
    template<class Expected>
    internal::Le<Expected> le(const Expected& e)
    {
        return internal::Le<Expected>(e);
    }
    
    
    template<class Expected>
    internal::Gt<Expected> gt(const Expected& e)
    {
        return internal::Gt<Expected>(e);
    }
    
    
    template<class Expected>
    internal::Ge<Expected> ge(const Expected& e)
    {
        return internal::Ge<Expected>(e);
    }
    
}

#endif /* COMPAREMATCHER_H */


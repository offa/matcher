
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


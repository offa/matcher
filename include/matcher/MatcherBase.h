
#ifndef MATCHERBASE_H
#define MATCHERBASE_H

#include <tuple>

namespace matcher
{
    namespace internal
    {

        template<class Expected>
        class MatcherBase
        {
        public:

            MatcherBase(const Expected& expected, const std::string& descr) : m_expected(expected), m_descr(descr)
            {
            }

        protected:

            const Expected& m_expected;
            const std::string m_descr;
        };

        template<>
        class MatcherBase<void>
        {
        public:

            explicit MatcherBase(const std::string& descr) : m_descr(descr)
            {
            }
            
        protected:
            
            const std::string m_descr;
        };

    }
}


#endif /* MATCHERBASE_H */


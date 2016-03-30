
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

            explicit MatcherBase(const Expected& expected) : m_expected(expected)
            {
            }

        protected:

            const Expected& m_expected;
        };

        
        template<>
        class MatcherBase<void>
        {
        };
        
    }
}


#endif /* MATCHERBASE_H */


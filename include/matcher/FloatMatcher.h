
#ifndef FLOATMATCHER_H
#define FLOATMATCHER_H

#include "MatcherBase.h"
#include <cmath>

namespace matcher
{
    namespace internal
    {
        template<class Expected>
        struct DoubleNear : protected MatcherBase<Expected>
        {
            DoubleNear(const Expected& expected, const Expected& abs, const std::string& descr) : MatcherBase<Expected>(expected, descr), m_abs(abs)
            {
            }

            template<class Actual>
            std::tuple<bool, std::string> operator()(const Actual& actual) const
            {
                using std::fabs;
                bool result = ( fabs(actual - this->m_expected ) <= m_abs * std::max(fabs(actual), fabs(this->m_expected)));
                return std::make_tuple(result, this->m_descr);
            }

        protected:

            const Expected& m_abs;
        };
    }

    
    template<class Expected>
    internal::DoubleNear<Expected> doubleNear(const Expected& e, const Expected& abs)
    {
        return internal::DoubleNear<Expected>(e, abs, "doubleNear");
    }
}

#endif /* FLOATMATCHER_H */


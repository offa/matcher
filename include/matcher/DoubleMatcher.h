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

#ifndef DOUBLEMATCHER_H
#define DOUBLEMATCHER_H

#include "MatcherBase.h"
#include <cmath>

namespace matcher
{
    namespace internal
    {
        template<class Expected>
        struct DoubleNear : protected MatcherBase<Expected>
        {
            DoubleNear(const Expected& expected, const Expected& abs, const std::string& descr)
                            : MatcherBase<Expected>(expected, descr), m_abs(abs)
            {
            }

            template<class Actual>
            std::tuple<bool, std::string> operator()(const Actual& actual) const
            {
                using std::fabs;
                bool result = ( fabs(actual - this->m_expected ) 
                                <= m_abs * std::max(fabs(actual), fabs(this->m_expected)));
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

#endif /* DOUBLEMATCHER_H */


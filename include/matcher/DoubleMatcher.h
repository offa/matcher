/*
 * Matcher - C++ Matchers.
 * Copyright (C) 2016-2017  offa
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

#pragma once

#include "MatcherBase.h"
#include <cmath>

namespace matcher
{
    namespace internal
    {
        template<class Expected>
        struct DoubleNear : protected MatcherBase<Expected>
        {
            DoubleNear(const Expected& expected, const Expected& epsilon, const std::string& description)
                            : MatcherBase<Expected>(expected, description), m_epsilon(epsilon)
            {
            }

            template<class Actual>
            MatchResult operator()(const Actual& actual) const
            {
                using std::fabs;
                const bool result = ( fabs(actual - this->m_expected )
                                    <= m_epsilon * std::max(fabs(actual), fabs(this->m_expected)));
                return MatchResult(result, this->m_description);
            }

        protected:

            const Expected& m_epsilon;
        };
    }


    template<class Expected>
    internal::DoubleNear<Expected> doubleNear(const Expected& expected, const Expected& epsilon)
    {
        return internal::DoubleNear<Expected>(expected, epsilon, "doubleNear");
    }
}


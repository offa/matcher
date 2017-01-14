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

#include "matcher/MatchResult.h"

namespace matcher
{
    namespace internal
    {

        template<class Expected>
        class MatcherBase
        {
        public:

            MatcherBase(const Expected& expected, const std::string& description)
                                : m_expected(expected), m_description(description)
            {
            }

        protected:

            const Expected& m_expected;
            const std::string m_description;
        };

        template<>
        class MatcherBase<void>
        {
        public:

            explicit MatcherBase(const std::string& description)
                                    : m_description(description)
            {
            }


        protected:

            const std::string m_description;
        };

    }
}


/*
 * Matcher - C++ Matchers.
 * Copyright (C) 2016-2019  offa
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
    template<class T>
    class Actual
    {
    public:

        explicit Actual(const T& value) : m_value(value)
        {
        }

        template<class Matcher>
        MatchResult that(const Matcher& m) const
        {
            return m(m_value);
        }

        template<class Matcher>
        bool match(const Matcher& matcher) const
        {
            return that(matcher).getResult();
        }


    private:

        const T& m_value;
    };


    template<class T>
    Actual<T> expect(const T& value)
    {
        return Actual<T>(value);
    }

}


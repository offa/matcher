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

#ifndef MATCHRESULT_H
#define MATCHRESULT_H

#include <string>

namespace matcher
{

    class MatchResult
    {
    public:

        MatchResult(bool result, const std::string& description)
                            : m_result(result), m_description(description)
        {
        }

        bool getResult() const
        {
            return m_result;
        }
        
        std::string getDescription() const
        {
            return m_description;
        }

    private:

        const bool m_result;
        const std::string& m_description;
    };
}

#endif /* MATCHRESULT_H */



#ifndef MATCHER_H
#define MATCHER_H

#include <tuple>

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
        std::tuple<bool, std::string> that(const Matcher& m) const
        {
            return m(m_value);
        }

        template<class Matcher>
        bool match(const Matcher& m) const
        {
            return std::get<0>(that(m));
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

#endif /* MATCHER_H */


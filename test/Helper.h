
#ifndef HELPER_H
#define HELPER_H

#include <CppUTest/TestHarness.h>

template<class T, class Matcher>
void checkMatcher(const T& cmp, const Matcher& matcher, bool expectedResult, const char* expMsg, const char* file, size_t line)
{
    bool result;
    std::string msg;
    std::tie(result, msg) = matcher.operator()(cmp);

    CHECK_EQUAL_LOCATION(expectedResult, result, nullptr, file, line);
    STRCMP_EQUAL_LOCATION(expMsg, msg.c_str(), nullptr, file, line);
}


#define CHECK_MATCHER(value, matcher, expectedResult, msg)   checkMatcher(value, matcher, expectedResult, msg, __FILE__, __LINE__)



#endif /* HELPER_H */


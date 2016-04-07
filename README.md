# [Matcher](https://github.com/offa/matcher)

[![Build Status](https://travis-ci.org/offa/matcher.svg?branch=master)](https://travis-ci.org/offa/matcher)
[![GitHub release](https://img.shields.io/github/release/offa/matcher.svg)](https://github.com/offa/matcher/releases)
[![License](https://img.shields.io/badge/license-GPLv3-yellow.svg)](LICENSE)

C++11 Hamcrest like Matcher implementation.


## Requirements

 - [**CMake**](http://www.cmake.org/) - for building tests *(Optional)*
 - [**CppUTest**](https://github.com/cpputest/cpputest) - for testing *(Optional)*


## Installtion

Header only - no compilation / installation is required.


## Example

```cpp
int main(int argc, char** argv)
{
    using namespace matcher;

    std::vector<int> v = { 0, 1, 2, 3  };

    auto res = expect(v).that(sizeIs(4));
    assert(res.getResult());

    auto res2 = expect(v).that(elementsAre({0, 1, 2, 3}));
    assert(res2.getResult());

    bool res3 = expect(123.456).match(doubleNear(123.45, 0.001));
    assert(res3);

    return 0;
}
```


## Testing

```
mkdir build
cmake ..
make
make unittest
```

It's also possible to use `make test` / `ctest` instead. For `unittest` it's possible to switch verbosity by CMake option.


## License

**GNU General Public License (GPL)**

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.


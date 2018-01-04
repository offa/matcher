#!/bin/bash

set -ex

if [[ "${CXX}" == clang* ]]
then
    export CXXFLAGS="-stdlib=libc++"
fi

mkdir build && cd build

cmake -DUNITTEST_VERBOSE=ON ..
make
make unittest


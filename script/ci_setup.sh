#!/bin/bash

set -ex

mkdir deps && cd deps
git clone --depth=1 https://github.com/cpputest/cpputest.git cpputest
cd cpputest && mkdir _build && cd _build


if [[ "${CXX}" == clang* ]]
then
    export CXXFLAGS="-stdlib=libc++"
fi

cmake -DC++11=ON -DTESTS=OFF ..
make -j
make install

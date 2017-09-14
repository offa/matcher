#!/bin/bash

set -ex

## Install CppUTest
CPPUTEST_VERSION=master
CPPUTEST=cpputest-${CPPUTEST_VERSION}

BUILD_FLAGS="-DC++11=ON -DTESTS=OFF"

if [[ "$CXX" == clang* ]]; then
    BUILD_FLAGS="$BUILD_FLAGS -DCMAKE_CXX_FLAGS=-stdlib=libc++" 
fi


wget https://github.com/offa/cpputest/archive/${CPPUTEST_VERSION}.tar.gz
tar -xzf ${CPPUTEST_VERSION}.tar.gz
pushd ${CPPUTEST}
mkdir _build && cd _build
cmake ${BUILD_FLAGS} ..
make -j4 && sudo make install
popd

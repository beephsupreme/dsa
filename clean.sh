#!/bin/sh
rm -rf build
mkdir build
cd build
cmake -DCMAKE_C_COMPILER=/opt/homebrew/bin/gcc-13 -DCMAKE_CXX_COMPILER=/opt/homebrew/bin/g++-13 ..

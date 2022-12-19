#!/bin/sh
mkdir build
cmake CMakeLists.txt -B build
cd build
make
cd ..
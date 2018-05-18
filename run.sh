#!/bin/sh

rm -rf build driver
mkdir build
cmake -Bbuild -H.
cd build
make
cp driver ..


#!/bin/bash
# script to run and compile

echo "-------running script to compile and space invaders game of Dieter De Wilde"
mkdir build
cd build
cmake ..
make install
../bin/spaceinvaders
echo "-------end of script"

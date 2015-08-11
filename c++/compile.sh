#!/bin/bash

if [ $# -ne 1 ]; then
echo "example: sh ./compile.sh pb001"
exit
fi
g++ $1.cpp -o $1.run -std=c++11
./$1.run
rm $1.run

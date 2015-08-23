#!/bin/bash

rm -f $1.run
if [ $# -ne 1 ]; then
echo "example: sh ./compile.sh pb001"
exit
fi
g++ $1.cpp -o $1.run -pthread -lgtest -std=c++11 2>&1 | tee compile.log
./$1.run

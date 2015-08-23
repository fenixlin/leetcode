#!/bin/bash

# This script is written to guide and has not been tested. 
# After installation, compile with -lgtest and -pthread to use.

$download_dir="download directory"
$build_dir="build directory"
$library_dir="destination library directory"
$include_dir="destination include directory"

wget https://googletest.googlecode.com/files/gtest-1.7.0.zip ${download_dir}
unzip ${download_dir}/gtest-1.7.0.zip
mkdir ${build_dir}
cd ${build_dir}
cmake ${download_dir}/gtest-1.7.0
make
cp -r libgtest.a libgtest_main.a ${library_dir}
cp -r ${download_dir}/gtest-1.7.0/include/gtest ${include_dir}

#rm -rf ${build_dir}

#!/bin/bash
if g++ -std=c++17 -Wall -Wextra -Wshadow bongi.cpp; then
    for i in *.in; do
        echo $i
        ./a.exe < $i > ${i:0:1}.out
    done;
    rm a.exe;
    zip soumission.zip *.out
fi

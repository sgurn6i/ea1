#!/bin/bash
# ea1 テスト実行 2016-06-14 08:32:31
EXECUTABLE=ea1_test_exec
if [ ! -f Makefile ]; then
   ./configure
fi
make
g++ -Wall -g -o $EXECUTABLE ea1_test_main.cpp -lea1
./$EXECUTABLE
rm -f $EXECUTABLE

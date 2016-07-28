#!/bin/bash
# ea1 テスト実行 2016-06-14 08:32:31
EXECUTABLE=ea1_test_exec
if [ ! -f Makefile ]; then
   ./configure
fi
make
# CPPFLAGS="-DEA1_DEBUG -DEA1_NO_LOGE"
CPPFLAGS="-DEA1_DEBUG"
g++ -Wall -g $CPPFLAGS -o $EXECUTABLE ea1_test_main.cpp -lea1
./$EXECUTABLE
rm -f $EXECUTABLE

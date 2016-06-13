#!/bin/bash
# ea1 テスト実行 2016-06-14 08:32:31
EXECUTABLE=ea1_test_exec
gcc -Wall -g -o $EXECUTABLE ea1_test_main.c
./$EXECUTABLE
rm -f $EXECUTABLE

#!/bin/bash

defaultEdit="$1" # Set the default editor in parameter $1 (such as: code, vim, nvim, ...)

if [ "$1" == "" ]; then
	defaultEdit="nvim"
fi

$defaultEdit ./test/src/main.cpp $(find src/ test/ inc/ -type f) CMakeLists.txt

